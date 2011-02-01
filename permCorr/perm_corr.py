#!/usr/bin/python
import sys, os
from numpy import *
from random import shuffle

def usage():
    print("%s " % sys.argv[0] )

if __name__ == '__main__':
    
    x = loadtxt('inputX', dtype='d')
    y = loadtxt('inputY', dtype = 'd')
    mx = mean(x)
    my = mean(y)
    x = x-mx
    y = y-my
    xstd = sqrt(sum(x*x))
    ystd = sqrt(sum(y*y))

    ntime = int(sys.argv[1])
    ret = empty(ntime)
    for i in xrange(ntime):
        shuffle(y)
        ret[i] = sum(x*y) 
    ret /= (xstd*ystd)

        
