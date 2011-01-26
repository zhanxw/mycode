CFLAGS=-std=c99 -g
all: main
OBJS := main.o

# link
main: $(OBJS)
	cc $(OBJS) -o $@

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)


%.o: %.c
	cc -c $(CFLAGS) $*.c -o $*.o
	cc -MM $(CFLAGS) $*.c > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

clean: 
	rm -f *.o main
