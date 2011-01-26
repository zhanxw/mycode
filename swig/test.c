#include "test.h"

static int counter;

void inc(void) {
    counter++;
}

void prnt(void) {
    fprintf(stderr, "counter = %d\n", counter);
}
