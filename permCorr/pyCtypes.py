#!/usr/bin/python
import os, sys
from ctypes import *

def usage():
    print("%s " % sys.argv[0] )

class VEC_P(Structure):
    _fields_ = [ ("value", c_void_p), # double*
                 ("len", c_uint),
                 ("cap", c_uint)]

if __name__ == '__main__':
    os.system('cc -std=c99  -shared -fPIC -o libtest.so libtest.c -lm')
    t= CDLL('libtest.so')
    t.main()
    sys.exit(1)

    # rest is not execed.
    x = VEC_P()
    vector_new = t.vector_new
    vector_new.restype= VEC_P
    x = vector_new(4)
    print x
    print dir(x)

    t.vector_print(x)

    print "read..."
    vector_read = t.vector_read
    vector_read.argtypes = [VEC_P, c_char_p]
    inFileName = create_string_buffer("inputX", 8)
    vector_read(x, "inputX")
    print "read again"
    vector_read(x, inFileName)
    #t.vector_read(x, "inputX")

    
