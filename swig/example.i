/* example.i */
%module example
%inline 
%{
    /* Global variable should be put here */
    extern double My_variable;
%}

/* it is OK to NOT list functions here, however, you will get warnings when compiling example_wrap.c file*/
%{
extern int fact(int n);
extern int my_mod(int x, int y);
extern char *get_time();
%}

/* Do NOT use %{ %} to enclose the following function AGAIN*/
/* You NEED to list functions here to make SWIG work*/
extern int fact(int n);
extern int my_mod(int x, int y);
extern char *get_time();

