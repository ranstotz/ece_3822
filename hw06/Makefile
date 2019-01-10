# file: GNUMakefile
#

# define a target for the application
#
all: hw_06.exe

# define a target to link the application
#
hw_06.exe: f_00.o f_01.o f_02.o
	g++ -g -lm f_00.o f_01.o f_02.o -o hw_06.exe

# define targets to compile the source code
#
f_00.o:	f_00.cc f_00.h Makefile
	g++ -O2 -c f_00.cc -o f_00.o

f_01.o: f_01.cc f_00.h Makefile
	g++ -O2 -c f_01.cc -o f_01.o

f_02.o: f_02.cc f_00.h Makefile
	g++ -O2 -c f_02.cc -o f_02.o

# define a target to clean the directory
#
clean:
	rm -f f_00.o f_01.o f_02.o hw_06.exe

#
# end of file
