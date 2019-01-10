#!/bin/bash

if [[ $@ == *-help* ]]
then
    echo "name: convert.sh
synopsis: convert.sh [options] files
desc: converts text file, specifically a text file with with lines containing paths to text files, into a script that creates the format for each filename by line in the text file to be copied to a new directory. This does not actually copy any text. 
example: convert.sh /dir1/dir2/mytext.txt

options:
    -help: display this help message

arguments: path to text document is first argument and location of the new directory that will be placed after each line of text in the document is the second argument. 

man page: none"    
fi

# Initialize file_num as a counter
file_num=0

# While loop reads each line of text from the first argument, then prints a 
# modified line of text including the input from the second argument.
while read p; do
printf "cp %b %b/f%08d.txt\n" "$p" "$2" "$file_num"
file_num=$((file_num+1))

done <$1


