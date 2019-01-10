/* 
Author: Ryan Anstotz
Date: 02/20/2018
Title: ECE 3822 HW07

Description: This program loops over all file lists (as arguments) and opens each file,
reads the file line by line, and prints the corresponding filename to stdout, and then 
displays the output of each file. Output may look like the following:

Opening file1.list:
000000: firstfile.txt
******
[the contents of firstfile.txt are displayed here...]
******
000001: secondfile.txt
******
[the contents of secondfile.txt are displayed here...]
******

Options: This program supports a "-help" option that displays a help message if any of
the arguments are incorrect or if the user types "-help" as an argument.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare size of each line in the text file (the filepath)
//
#define NSIZE 256

// Function prototype
//
void help_option(void);

int main(int argc, char** argv) {

  // Create "-help" option. If user types "-help" as a command line argument, give
  // this message.
  //
  for (int i=1; i < argc; i++) { 
    if ( ! strcmp(argv[i], "-help")) {
      help_option();
      return(-1);
    }
  }
  
  // Display this message if no files are specified
  //
  if (argc < 2) {
    fprintf(stdout, "\nPlease specify files as arguments. \n");
    return (-1);
  }
  
  // Loop over all files in arguments, open each file, print the file line by line
  // and display the output of each file. Begin at first argument (text file).
  //
  for (int i=1; i < argc; i++) {
    fprintf(stdout, "Opening %s\n", argv[i]);
    char buffer[NSIZE];
    FILE *fp;
    fp = fopen(argv[i], "r");
    int lineIndex = 0;
    
    while (EOF != fscanf(fp, "%255[^\n]\n", buffer)) {
      
      fprintf(stdout, "%010d: %s\n",lineIndex, buffer);
      lineIndex ++;
    }
    fclose(fp);
  }

  return (0);
}

void help_option(void) {
  // Display below help option if invoked
  //

  fprintf(stdout, "\nname: my_cat.exe \n"
              "synopsis: my_cat.exe [options] files \n"
              "desc: open each command line argument with a file list, loop over f\
ile list and print the filename and contents to the user. \n"
              "example: Opening file1.list:\n"
              "000000: firstfile.txt\n"
              "******\n"
              "[the contents of firstfile.txt are displayed here...]\n"
              "******\n"
              "000001: secondfile.txt \n"
              "options: -help: displays this message. \n"
              "arguments: filenames as arguments with a filepath in each line of t\
ext. \n"
              "man page: none \n"
	  );
}



















