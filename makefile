CC	= gcc
CFLAGS	= -I../include
LDLIBS	= -lrx32	
LDFLAGS = -L../lib

all: dbl-test1

dbl-test1: dbl-test1.o dbl-print.o dbl-init.o

.PHONY: clean cleanall

clean:
	$(RM) *.o *~ *.exe			# be careful, need a tab character

cleanall: clean
	$(RM) *.i *.tm *.out *.shar 

