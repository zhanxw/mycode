%module eg
%{
    extern int counter;
    extern void inc(void) ;
    extern void prnt(void) ;
%}

%include "test.h"
