#include "test2.h"

#include <stdio.h>
#include <stdlib.h>



static int counter = 0;

void t2_inc(void) {
    counter++;
}

void t2_prnt(void) {
    fprintf(stderr, "t2: counter = %d\n", counter);
}
