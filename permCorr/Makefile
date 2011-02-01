CC=cc

MKL_HEADER_DIR=/home/zhanxw/intel/mkl/include
MKL_LIB_DIR=/home/zhanxw/intel/mkl/lib/intel64
MKL_LIBS=$(MKL_LIB_DIR)/libmkl_intel_lp64.a $(MKL_LIB_DIR)/libmkl_intel_thread.a $(MKL_LIB_DIR)/libmkl_core.a /home/zhanxw/intel/composerxe-2011.1.107/compiler/lib/intel64/libiomp5.a

CFLAGS=-std=c99 -O2 -I$(MKL_HEADER_DIR)
LIBS=$(MKL_LIBS) -lm -lpthread
all: main
OBJS := main.o

# link
main: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)


%.o: %.c
	$(CC) -c $(CFLAGS) $*.c -o $*.o
	$(CC) -MM $(CFLAGS) $*.c > $*.d
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
	./pyCtypes.py

