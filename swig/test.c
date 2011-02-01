#include <stdio.h>
#include <stdlib.h>

#include "test.h"

static int counter = 0;

void inc(void) {
    counter++;
}

void prnt(void) {
    fprintf(stderr, "t: counter = %d\n", counter);
}
