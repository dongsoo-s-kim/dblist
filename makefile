CC	= gcc
X86	= $(patsubst MINGW%,%,$(MSYSTEM))
CFLAGS	= -g -I../include
LDLIBS	= -lrx$(X86)	
LDFLAGS = -L../lib
DMAIN	= -D__MAIN__
OBJS	= dbl-alloc.o dbl-init.o dbl-print.o generator.o
LIBRARY	= libdbl$(X86).a
HEADER	= dblist.h
%-main.o: %.c
	$(CC) -c $(CFLAGS) $(DMAIN) $< -o $@

lib: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar r $@ $(OBJS)

install: $(LIBRARY) $(HEADER)
	cp $(LIBRARY) ../lib
	cp $(HEADER)  ../include


dbl-test1: dbl-test1.o dbl-print.o dbl-init.o dbl-alloc.o
shift-main: shift-main.o dbl-alloc.o dbl-init.o dbl-print.o
generator-main: generator-main.o dbl-print.o dbl-init.o dbl-alloc.o

.PHONY: clean cleanall

clean:
	$(RM) *.o *~ *.exe			# be careful, need a tab character

cleanall: clean
	$(RM) *.i *.tm *.out *.shar *.a




