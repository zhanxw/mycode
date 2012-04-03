#CFLAGS = -g -O0 -I./libgmp/include -DINCLUDE_LIBSTATGEN
CFLAGS = -O2 -I./libgmp/include -DINCLUDE_LIBSTATGEN
all: main cotmp
ExactLogisticRegression.o: ExactLogisticRegression.cpp ExactLogisticRegression.h
	g++ $(CFLAGS) -c $< -Ilibsrc
main.o:	main.cpp
	g++ $(CFLAGS) -c $< -Ilibsrc
main: main.o  ExactLogisticRegression.o 
	g++ -static $(CFLAGS) -o main $^ libsrc/lib-goncalo.a -L./libgmp/lib -lz -lm -lgmpxx -lgmp 
comp.o:	comp.cpp
	g++ $(CFLAGS) -I../logistic -c $< -Ilibsrc
comp: comp.o  ExactLogisticRegression.o ../logistic/LogisticRegression.o
	g++ -static $(CFLAGS) -o comp $^ libsrc/lib-goncalo.a -L./libgmp/lib -lz -lm -lgmpxx -lgmp
compGraph: comp
	./comp > comp.output
	graph -x 2 -y 4 -l "wald exact" -o comp.png comp.output
	echo "comp" |mutt zhanxw@umich.edu -s "comp" -a comp.png
clean:
	rm -f *.o main
