#!/usr/bin/env python

# import required modules:
#
import os
import sys
import string
import csv
from timeit import default_timer as timer
import random

# main function
#
def main(argv):

    # support a help function
    #
    for args in argv:
        if args == '-help':
            print "\nsynopsis: this program reads .csv files, sorts a column by alphabetical order, times the runs, and prints the output to stdout. It also supports this help function.\n"
            
            # exit program if '-help' called
            # 
            sys.exit()
            
    # loop through command line arguments, read .csv files into memory,
    # sort the lastnames column, then print to stdout. 
    # first open lists to store data
    #
    randomlist = []
    websitelist = []
    lastnamelist = []
    firstlist = []
    addnumlist = []
    addstreetlist = []
    data = {}
    # start argument loop
    #
    for i in argv:
        
        with open(i, 'rU') as infile:
            # read file as dict
            reader = csv.DictReader(infile)
            
            for row in reader:
                for header, value in row.items():
                    try:
                        data[header].append(value)
                    except KeyError:
                        data[header] = [value]
    
    # set lists as imported data from .csv files
    #
    randomlist = data['randnum']
    websitelist = data['website']
    lastnamelist = data['lastname']
    firstlist = data['firstname']
    addnumlist = data['addressnumber']
    addstreetlist = data['addressstreet']
   
    # zip lists together as prep for sorting
    # initialize master list to append tuples
    #
    masterlist = []
    for i in zip(randomlist, websitelist, lastnamelist, firstlist, addnumlist, addstreetlist):
        masterlist.append(i)
    
    # sort list by last name
    #
    start = timer()
    sortedmasterlist = sorted(masterlist, key=lambda last: last[2])
    end = timer()
    print end-start
    # print the last names to stdout
    #
    #for x in sortedmasterlist:
    #    print x[2]
        
    
    
    # Exit gracefully
    #
    return

# Begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[1:])

# End of file
