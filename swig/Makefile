all:
	swig -python interface.i
	cc -c -fPIC -I/usr/include/python2.6 test.c
	cc -c -fPIC -I/usr/include/python2.6 interface_wrap.c
	ld -share test.o interface_wrap.o -o _eg.so
	python -m eg -c 'print dir(eg)'
