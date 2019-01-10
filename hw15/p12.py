#!/usr/bin/env python

# import required modules:
#
import os
import sys
import string
import collections

# main function
#
def main(argv):
    """
    with open(argv[1]) as f1:
        c1 = collections.Counter(f1.read().split())

    with open(argv[2]) as f2:
        c2 = collections.Counter(f2.read().split())
    print c2
    c2 += c1

    #print c1, c2

    shared_items = set(c1.items()) & set(c2.items())

    
    print (float(len(shared_items)))/float((len(c1)))
    print c1
    print c2
    """
    
    # open dictionary for word count (histogram)
    #
    wordcount = {}

    # open argv[1] as a list of file names in corpus
    # iterate over lines in list file
    #
    for line in open(argv[1], 'r'). readlines():
        
        # Strip linefeed
        #
        line = line.rstrip()

        # open file 
        # 
        fp = open(line, 'r')

        # store file contents to variable
        #
        file_contents = fp.read()

        # strip punctuation from string and convert to lowercase
        #
        table = string.maketrans("","")
        file_contents = file_contents.translate(table, string.punctuation).lower()
        
        # split file string into a list of words for dictionary
        #
        file_list = file_contents.split()

        # iterate through words in file and place in dictionary
        #
        for word in file_list:
            
            # check if word is in dictionary
            #
            if word not in wordcount:
                wordcount[word] = 1
            else:
                wordcount[word] += 1

    # Create a counter dictionary to use the .most_common method
    #
    countedwords = collections.Counter(wordcount)
    
    # print the most common words as the second command line arg
    #
    for word, count in countedwords.most_common(int(argv[2])):
        print word, ": ", count
        
    # Exit gracefully
    #
    return 

# Begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[0:])

# End of file
