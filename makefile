CC	= gcc
CFLAGS	= -I../include
LDLIBS	= -lrx32	
LDFLAGS = -L../lib

all: dbl_test1

dbl_test1: dbl_test1.o dbl_print.o dbl_init.o

.PHONY: clean cleanall

clean:
	$(RM) *.o *~ *.exe			# be careful, need a tab character

cleanall: clean
	$(RM) *.i *.tm *.out *.shar 

DONE: 	
