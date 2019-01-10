#!/usr/bin/env python

# import required modules:
#
import os
import sys
import string
import random
from random import shuffle
from pathlib2 import Path
import linecache
import time

# This class shuffles songs without repeating and keeps track of where
# it left off. See '-help' option for more details.
#
class shuffler:
    
    # define constructor, take arguments as parameters
    #
    def __init__(self):
        
        self.argv_a = []
        # end of constructor
        
    # Method to print arguments from command line provided
    #
    def printArgs(self):
        print "Arguments provided are: ", self.argv_a
        return
        
    # Set command line arguments provided, do not include script name
    #
    def setter(self, commandArgs):
        
        # Set data
        #
        self.argv_a = commandArgs[1:]
        return
            
    # Check for a '-help' option and print help information
    #
    def check_options(self):
        for args in self.argv_a:
            if args == '-help':
                print "\nsynopsis: This class shuffles the files in the provided command line argument path, then plays each song unrepeated until all songs have been played. Then it will reshuffle the songs and continue the same process.\n"
                print "desc: see above.\n"
                print "example: provide a path /songs/. Will capture the length of files in that directory and begin the shuffle.\n"
                print "options: supports a '-help' option as shown here.\n"
                print "arguments: path to files to be shuffled and '-help'.\n"
                print "man page: none.\n"
        
                # Exit program if help argument provided
                #
                sys.exit()
        return

    # Method to play the shuffler
    #
    def play(self):
        
        # Get file list from data path in command line argument
        #
        for root, dir, files in os.walk(self.argv_a[0]):
            
            # store the files from the path as a list in 'mysongs'
            #
            mysongs = files

        # Start an infinite loop
        #
        while True:
            # Check if counter file exists, if not, generate one to hold the counter
            # in a scratch file. Also check if the counter has surpassed the number
            # of songs
            #
            my_file = Path("./counter.txt")
            if not my_file.is_file() or open("./counter.txt").readline() >= str(len(mysongs)):
                
                # Set counter to 1 for first line in a file
                #
                songcounter = 1
                
                # Write (or overwrite) song counter to file. Open, write, close the file.
                #
                counterOut = open("./counter.txt", "w")
                counterOut.write(str(songcounter))
                counterOut.close()
                
                # Shuffle songs and write (or overwrite them) to a file line by line for each song
                #
                # Shuffle the list of songs fromt the arguments
                #
                shuffledList = mysongs
                random.shuffle(shuffledList)
                shuffleOut = open("./shuffle.txt", "w")
                
                # Write shuffled list into file
                #
                for i in shuffledList:
                    shuffleOut.write("%s\n" % i)
                    
            # Loop over songs in list
            #
            for j in range(0, len(mysongs)):
                
                # Get counter for index from file, cast to int, then print counter
                #
                tempCounter = int(open("./counter.txt").readline())
                print tempCounter
                
                # Get random song from the shuffle.txt file according to 
                # the counter above
                #
                currentSong = linecache.getline("./shuffle.txt", tempCounter)
                
                # Print the song 
                #
                print currentSong
                
                # Increment counter, overwrite scratch file, and close
                #
                songcounter = tempCounter
                songcounter += 1
                
                counterOut = open("./counter.txt", "w")
                counterOut.write(str(songcounter))
                counterOut.close()
                
                # Sleep for 1 second as to print 1 song per second
                #
                time.sleep(1)
            
        # Exit gracefully
        return

# main: this is the main function of this Python script
#
def main(argv):

    # Create instance of the shuffler class
    #
    myshuffle = shuffler()
    
    # Set the command line arguments as the input for the class
    #
    myshuffle.setter(argv)
    
    # Check if the help option is invoked
    #
    myshuffle.check_options()
    
    # Print the arguments provided to the class from the setter method
    #
    myshuffle.printArgs()
    
    # Play the shuffler
    #
    myshuffle.play()
    
    # End gracefully 
    #
    return
    
# begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[0:])

#
# end of file
