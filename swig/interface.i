%module eg
%{
    extern void inc(void) ;
    extern void prnt(void) ;
    extern void t2_inc(void) ;
    extern void t2_prnt(void) ;
%}

%include "test.h"
%include "test2.h"
