CFLAGS=-std=c99 -O2
LIBS=-lm
all: main
OBJS := main.o

# link
main: $(OBJS)
	gcc $(OBJS) -o $@ $(LIBS)

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)


%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CFLAGS) $*.c > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

clean: 
	rm -f *.o main

test: main inputX inputY
	#R --vanilla < generateData
	./main 100 inputX inputY
