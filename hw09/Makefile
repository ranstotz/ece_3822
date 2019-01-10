# file: GNUMakefile
#

# define a target for the application
#
all: charcopy.exe

# define a target to link the application
#
charcopy.exe: charcopy.o
	g++ -g -lm charcopy.o -o charcopy.exe

# define targets to compile the source code
#
charcopy.o: charcopy.cc Makefile
	g++ -O2 -c charcopy.cc -o charcopy.o

# define a target to clean the directory
#
clean:
	rm -f charcopy.o charcopy.exe

#
# end of file
