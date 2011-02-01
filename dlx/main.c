#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

int verbose = 0; // trun on debug or not

typedef struct Node_t{
    char name[9];
    unsigned int size;
    struct Node_t* left;
    struct Node_t* right;
    struct Node_t* up;
    struct Node_t* down;
    struct Node_t* col;
}* Node_ptr;

void load_data(Node_ptr root, char* file_name) {
    FILE* fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "Cannot open file %s\n", file_name);
        exit(1);
    }
    int nrow, ncol;
    fscanf(fp, "%d %d", &nrow, &ncol);
    if (verbose) {
        printf("nrow = %d ncol = %d\n", nrow, ncol);
    }

    // fill in root node
    strcpy(root->name, "root");

    // make header
    struct Node_t* header = malloc(sizeof(struct Node_t)*ncol);
    root->right = &header[0];

    int c = 0;
    for (; c < ncol; c++) {
        sprintf(header[c].name, "h%d", c);
        header[c].size = 0;
        header[c].up = &header[c];
        header[c].down = &header[c];
        if (c == 0) 
            header[c].left = root;
        else
            header[c].left = &header[c-1];
        if (c == ncol-1)
            header[ncol-1].right = root;
        else
            header[c].right = &header[c+1];
        header[c].col = &header[c];
    }

    // read row one by one
    int r;
    for (r = 0; r < nrow; r++) {
        Node_ptr rptr = 0;

        for (c = 0; c < ncol; c++) {
            int elem;
            assert(fscanf(fp, "%d", &elem));
            if (elem != 1) 
                continue;

            Node_ptr p = malloc(sizeof(struct Node_t));
            assert(p);
            sprintf(p->name, "r%d c%d", r, c);
            if (verbose) fprintf(stdout, "r%d c%d\n", r, c);

            header[c].size++;
            p->size = 0;
            p -> up = header[c].up;
            p -> down = &header[c];
            header[c]. up -> down = p;
            header[c]. up = p;

            if (!rptr)  {
                rptr = p;
                p -> left = p;
                p -> right = p;
            } else {
                p->left = rptr->left;
                p->right = rptr;
                p->left->right =p;
                p->right->left = p;
            }
            p->col = &header[c];
        }
    }
};

void print_dlx(Node_ptr root){
    Node_ptr p;
    p = root;
    if (verbose) printf("%s -> \n", p->name); // print root

    // print header
    for (p = root-> right; p!=root; p=p->right) {
        if (verbose){
            printf ("%s (%d) -> ", p->name, p->size);
            Node_ptr r;
            for (r = p->down; r !=p ; r = r->down) {
                printf("%s ,", r->name);
            }
            printf ("\n");
        }
    } 
    printf("\n");

};

void cover(Node_ptr c){
    if (verbose)     printf("cover %s\n", c->name);
    Node_ptr i,j;

    c->right->left = c->left;
    c->left->right = c->right;
    for (i = c->down; i != c; i = i->down) {
        for (j = i->right; j != i; j = j-> right) {
            j->down->up = j->up;
            j->up->down = j->down;
            j->col->size --;
        }
    }
}

void uncover(Node_ptr c) {
    if (verbose) printf("uncover %s\n", c->name);
    Node_ptr i, j;
    for (i = c->up; i != c; i = i-> up) {
        for (j = i->left; j !=i ; j = j->left) {
            j->col->size++;
            j->up->down = j;
            j->down->up = j;
        }
    }
    c->right->left = c;
    c->left->right = c;
 }

void print_result(unsigned int k, Node_ptr* solution){
    static int i = 0;
    printf("solution %d :\n", ++i);
    for (int i = 0; i< k; i++){
        //printf("%p %s -> ", solution[i], solution[i]->name);
        printf("%s -> ", solution[i]->name);
    }
    printf("end\n");

}

// k: depth searched
// root: head node
// solution: Node_ptr[k]
void dfs(unsigned int k, Node_ptr root, Node_ptr* solution) {
    if (root->right == root) {
        print_result(k, solution);
        return;
    }
    // find a column
    // first try random pick one
    Node_ptr r;
    Node_ptr c;
    Node_ptr j;

    c = root->right; 
    cover(c);
    for (r = c->down; r!=c; r = r->down) {
        solution[k] = r;
        assert(r);
        if (verbose) printf("solution set: %s and k = %d \n", r->name, k);
        for (j = r->right; j!=r; j = j->right) {
            cover(j->col);
        }
        dfs(k+1, root, solution);
        r = solution[k];
        c = r->col;
        for (j=r->left; j!=r; j = j->left){
            uncover(j->col);
        }
    }
    uncover(c);
}

int main(int argc, char *argv[])
{

    Node_ptr root = malloc(sizeof(struct Node_t));
    Node_ptr solution[8] = {0};

    time_t begin, end;
    time(&begin);
    load_data(root, "input");
    print_dlx(root);
    dfs(0, root, solution);
    // make graph
    // dancing links
    // print output
    time(&end);
    printf("Total time spent: %.2f\n", difftime(end,begin));
    printf("Done\n");
    return 0;
}