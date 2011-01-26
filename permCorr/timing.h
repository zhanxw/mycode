#ifndef _TIMING_H_
#define _TIMING_H_

#include <time.h>

static time_t start, end;

extern void timing_start(void) {
    time(&start);
}

extern void timing_stop(void) {
    time(&end);
}

extern void timing_diff(void) {
    fprintf(stdout, "Elapsed time: %f\n", difftime(end, start));
}

#endif /* _TIMING_H_ */
