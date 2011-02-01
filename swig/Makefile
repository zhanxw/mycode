all: main swig example

main: test.h test.c main.c test2.h test2.c
	cc -Wall -c -I/usr/include/python2.6 test.c
	cc -Wall -c -I/usr/include/python2.6 test2.c
	cc -Wall -c main.c
	cc -Wall main.o test.o test2.o -o main

swig: interface.i test.c test2.c
	swig -python interface.i
	cc -Wall -c -fPIC -I/usr/include/python2.6 test.c
	cc -Wall -c -fPIC -I/usr/include/python2.6 test2.c
	cc -Wall -c -fPIC -I/usr/include/python2.6 interface_wrap.c
	cc -Wall -shared test.o test2.o interface_wrap.o -o _eg.so

example:
	swig -python example.i
	cc -Wall -c -fPIC -I/usr/include/python2.6 example.c
	cc -Wall -c -fPIC -I/usr/include/python2.6 example_wrap.c
	cc -Wall -shared example.o example_wrap.o -o _example.so

test: main swig example
	./main
	python -c 'import eg; eg.prnt(); eg.inc(); eg.prnt(); eg.t2_prnt(); eg.t2_inc(); eg.t2_prnt()'
	python -c 'import example; print example.cvar.My_variable; print example.my_mod(7,3); print example.fact(4); print example.get_time()'
clean:
	rm -f *.o main # clean C files
	rm -f *_wrap.c eg.py* example.py* *.so # clean SWIG files
