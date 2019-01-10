# file: GNUMakefile
#

# define a target for the application
#
all: mytest.exe

# define a target to link the application
#
mytest.exe: mytest.o mytest_00.o
	g++ -g -lm mytest.o mytest_00.o -o mytest.exe

# define targets to compile the source code
#
mytest.o: mytest.cc mytest.h Makefile
	g++ -O2 -c mytest.cc -o mytest.o

mytest_00.o: mytest_00.cc mytest.h Makefile
	g++ -O2 -c mytest_00.cc -o mytest_00.o

# define a target to clean the directory
#
clean:
	rm -f mytest.o mytest_00.o mytest.exe

#
# end of file
