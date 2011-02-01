#include <stdio.h>
typedef struct {
    char cval;
    int ival;
}mytype;
int main(void)
{
    mytype test;
    printf("__alignof__(char)=%d\n", __alignof__(char));
    printf("__alignof__(short)=%d\n", __alignof__(short));
    printf("__alignof__(int)=%d\n", __alignof__(int));
    printf("__alignof__(long)=%d\n", __alignof__(long));
    printf("__alignof__(long long)=%d\n", __alignof__(long long));
    printf("__alignof__(float)=%d\n", __alignof__(float));
    printf("__alignof__(double)=%d\n", __alignof__(double));
    printf("__alignof__(mytype)=%d\n", __alignof__(mytype));
    printf("__alignof__(test)=%d\n", __alignof__(test));
    return 0;
}
