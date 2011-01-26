#ifndef _DEBUG_H_
#define _DEBUG_H_

enum DEBUG_LEVEL {SILENT = 0, INFO};
static enum DEBUG_LEVEL debug_level = INFO;
static enum DEBUG_LEVEL default_debug_level = INFO;

extern void debug_level_set(enum DEBUG_LEVEL l) {
    default_debug_level = l;
}

#define PINT(x) print_int(#x, (x))
extern void print_int(const char* name, int value) {
    if (debug_level <= default_debug_level) {
        fprintf(stderr, "PINT: %s = %d \n", name, value);
    }
}



#endif /* _DEBUG_H_ */
