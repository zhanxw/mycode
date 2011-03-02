CFLAGS = -g -O0
all: main
ExactLogisticRegression.o: ExactLogisticRegression.cpp ExactLogisticRegression.h
	g++ $(CFLAGS) -c $< -Ilibsrc
main.o:	main.cpp
	g++ $(CFLAGS) -c $< -Ilibsrc
main: main.o  ExactLogisticRegression.o
	g++ $(CFLAGS) -o main $^ libsrc/lib-goncalo.a -lz -lm -lgmpxx -lgmp
clean:
	rm -f *.o main
