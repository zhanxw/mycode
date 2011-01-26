CFLAGS = -g -O0
all: main
LogisticRegression.o: LogisticRegression.cpp LogisticRegression.h
	g++ $(CFLAGS) -c $< -Ilibsrc
main.o:	main.cpp
	g++ $(CFLAGS) -c $< -Ilibsrc
main: main.o LogisticRegression.o
	g++ $(CFLAGS) -o main $^ libsrc/lib-goncalo.a -lz -lm
clean:
	rm -f *.o main
