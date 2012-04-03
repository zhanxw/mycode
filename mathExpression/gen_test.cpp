#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE* fp = fopen("test.txt", "w");
    int n = 1000;
    if (argc == 2) {
        n = atoi(argv[1]);
    }
    srand(0);
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d\t%d\n", rand() % 100, rand() % 100 );
    fclose(fp);
    return 0;
}
