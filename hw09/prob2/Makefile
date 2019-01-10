# file: GNUMakefile
#

# define a target for the application
#
all: example.exe

# define a target to link the application
#
example.exe: example.o
	g++ -lm example.o -o example.exe

# define a target to compile the application
#
example.o: example.cc example.h
	g++ -O2 -c example.cc -o example.o

# define a target to clean the directory
#
clean:
	rm -f example.o example.exe

#
# end of file
