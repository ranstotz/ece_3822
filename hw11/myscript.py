#!/usr/bin/env python

# import required modules:
#
import os
import sys
import string
from collections import Counter, OrderedDict
from timeit import default_timer as timer


# main: this is the main function of this Python
#
def main(argv):

    # Declare local variables to store command line arguments from options
    #
    totalFilesInCorpus = 1000000
    ngram = 0;
    pattern = ""
    suffix = ".list"
    fileCounter = 0
    patternCount = 0
    totalWordCount = 0
    totalBigramCount = 0
    totalTrigramCount = 0
    bigramslist = []
    trigramslist = []
    # Start timer
    #
    start = timer()

    # Loop through command line arguments
    #
    for i in range(1, len(sys.argv)):
        
        # Check if help option invoked
        #
        if sys.argv[i] == '-help':
            print "synopsis: generates histogram of target words specified by target word '-pattern', it collects n words depending on option '-ngram'."
            print "desc: takes multiple lists of filenames and parses the filenames by word."
            print "example: produces histogram table."
            print "options: '-help- displays this message. '-pattern' accepts word as target. '-ngram' accepts number of n-grams for histogram."
            print "arguments: lists of filenames."
            print "man page: none "
            
            # Early return for help option
            #
            return
        # Check if '-ngram' option is invoked from command line
        #
        if sys.argv[i] == '-ngram':
         
            # Check target number specified by '-ngram' and save to variable
            #
            if sys.argv[i+1] == '1':
                ngram = 1
                print "ngram is 1"
            elif sys.argv[i+1] == '2':
                ngram = 2
                print "ngram is 2"
            elif sys.argv[i+1] == '3':
                ngram = 3
                print "ngram is 1"
            else: 
                print "Please specify -ngram argument as 1, 2, or 3."
                
                # Early return since no '-ngram' argument specified
                #
                return
        # Check if '-pattern' option is invoked from command line
        #
        if sys.argv[i] == '-pattern': 
            
            # Save target word specified by '-pattern'
            #
            pattern = sys.argv[i+1]
            print "this is the pattern: ", pattern
   
    # Loop through command line arguments to open files
    #
    for i in range(1, len(sys.argv)):
     
        # Check if argument ends with '.list' to only open those files
        #
        if sys.argv[i].endswith(suffix) == True:
            
            # Iterate over lines in the '.list' files
            #
            for line in open(sys.argv[i], 'r').readlines():

               # Strip linefeed
               #
               line = line.rstrip('\n')

               # Open file
               #
               fp = open(line, 'r')
               
               # Store file contents to variable
               #
               file_contents = fp.read()
               
               # Strip punctuation from string and convert to lowercase
               #
               table = string.maketrans("","")
               file_contents = file_contents.translate(table, string.punctuation).lower()
               # Split file string into a list of words for indexing purposes
               #
               file_list = file_contents.split()
               #print file_list
               
               # Store total words to a word counter variable
               # Total bigrams subtract 1, and trigrams 2
               #
               totalWordCount += len(file_list)
               totalBigramCount += totalWordCount - 1
               totalTrigramCount += totalWordCount - 2

               # Check if pattern word is in file list prior to any computation
               # to improve efficiency. This will pass over files without
               # matches. First convert pattern string into a list to use set
               #
               patternlist = []
               patternlist.append(pattern)
               
               if (len(set(file_list).intersection(patternlist)) > 0):
                      
                   # Increment file counter since match occured
                   #
                   fileCounter += 1
                   
                   # Check if ngram target is one, use counter to store filelist
                   # and look in the file list to count the number of matches
                   # Store matches to variable.
                   #
                   if (ngram == 1):
                       c = Counter(file_list)
                       patternCount += c[pattern] 
                       # print "this has", c[pattern], pattern
                       
                    # Bigrams
                   if (ngram == 2):
                       
                       # Get all indices from file_list that match target pattern
                       #
                       bIndices = [i for i, x in enumerate(file_list) if x == pattern]
                       # Create temp variable to store the string to be appended
                       # to bigramslist
                       #
                       bigramsholder = ""
                       
                       # Loop over the the bIndices list and store the word and
                       # the next word as a string to the bigramslist
                       #
                       for x in range(0, len(bIndices)):
                           # Store matching index and following index to the holder
                           try:
                               bigramsholder = file_list[bIndices[x]] + " " + file_list[bIndices[x] + 1]
                               # Append it to the list
                               bigramslist.append(bigramsholder)
                            
                               #Check for error
                           except IndexError:
                               pass
                           continue

                    # Trigrams
                   if (ngram == 3):
                        
                        # Get all indices from file_list that match target pattern
                        #
                        tIndices = [i for i, x in enumerate(file_list) if x == pattern]
                        # Create temp variable to store the string to be appended
                        # to bigramslist
                        #
                        trigramsholder = ""
                        
                        # Loop over the the bIndices list and store the word and
                        # the next word as a string to the bigramslist
                        #
                        for x in range(0, len(tIndices)):
                            # Store matching index and following index to the holder
                            try:
                                trigramsholder = file_list[tIndices[x] - 1] + " " + file_list[tIndices[x]] + " " + file_list[tIndices[x] + 1]
                                # Append it to the list
                                trigramslist.append(trigramsholder)
                                
                            #Check for error
                            except IndexError:
                                pass
                            continue
                                

 
               # Close file
               #
               fp.close()
  
    # Print data
    #
    
    print '%10s %40s' % ('Ngram', 'Frequency')
    print '%10s%20s%20s%20s' % (' ', 'No.', 'Percentage', 'Cumulative')
  
    if (ngram == 2):
        # Calculate Bigram data
        #
        # Store list to a Counter dictionary
        #
        bigramdict = Counter(bigramslist)
        
        # Sum total bigrams
        # 
        patternCount = sum(bigramdict.values())
        
        # Take top 10 bigrams, and sort them
        #
        newbigramdict = OrderedDict(bigramdict.most_common(10))
        
        # temp counter for cumulative calculation
        #
        tempcounter = 0
        
        # Print results
        #
        for key, value in newbigramdict.iteritems():
            tempcounter += value
            frequency = float(value)/float(patternCount)/100.0
            cumu = float(tempcounter)/float(patternCount)/100.0
            # Print data
            #
            print '%10s%20d%20lf%20lf' % (key, value, frequency, cumu)
        
    if (ngram == 3):
        # Calculate Bigram data
        #
        # Store list to a Counter dictionary
        #
        trigramdict = Counter(trigramslist)

        # Sum total bigrams
        #
        patternCount = sum(trigramdict.values())

        # Take top 10 bigrams, and sort them
        #
        newtrigramdict = OrderedDict(trigramdict.most_common(10))

        # temp counter for cumulative calculation
        #
        tempcounter = 0

        # Print results
        #
        for key, value in newtrigramdict.iteritems():
            tempcounter += value
            frequency = float(value)/float(patternCount)/100.0
            cumu = float(tempcounter)/float(patternCount)/100.0
            # Print data
            #
            print '%10s%20d%20lf%20lf' % (key, value, frequency, cumu)


    # End timer
    #
    end = timer()
    totaltime = end - start


    
    if (ngram == 1):
        percentageCount = float(patternCount)/float(totalWordCount)/float(100)
        print '%10s%20d%20lf%20d' % (pattern, patternCount, percentageCount, 100)

    # Print time to execute script
    #
    print "Time to execute script: ", totaltime

# begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[0:])

#
# end of file
