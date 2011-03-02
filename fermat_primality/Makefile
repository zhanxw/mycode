all: main.c
	cc -std=c99 main.c -o main -O2
	cc -fopenmp -std=c99 main.c -o main.omp -O2	

TIMES=100
test: all
	rm -f res res.omp	
	./main $(TIMES) >res
	./main.omp $(TIMES) |sort -k1 -g >res.omp
	paste res res.omp
clean:
	rm -f main main.omp
