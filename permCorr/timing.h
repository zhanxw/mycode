#ifndef _TIMING_H_
#define _TIMING_H_

#ifdef __linux
#include <sys/time.h>

 struct timeval start, end;

extern void timing_start(void) {
    gettimeofday(&start, (struct timezone *)NULL);
}

extern void timing_stop(void) {
    gettimeofday(&end, (struct timezone *)NULL);
}

extern void timing_diff(void) {
    double s = (double)start.tv_sec + start.tv_usec*0.000001;
    double e = (double)end.tv_sec + end.tv_usec*0.000001;
    fprintf(stdout, "Elapsed time: %f\n", e-s);
}

#else    // #ifdef __linux

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

#endif
#endif /* _TIMING_H_ */
