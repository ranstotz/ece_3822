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

    '''
    # This example writes a list as a row to a new .csv file
    mylist = [1, 4, 2, 9]
    secondlist = [7, 7, 7, 5]
    thirdlist = ['hi', 'my', 'name', 'is']
    
    # open file, zip lists, and write them as rows
    with open("mycsv1.csv", 'wb') as myfile:
        wr = csv.writer(myfile, dialect='excel')
        for i in zip(mylist, secondlist, thirdlist):
            wr.writerow(i)
    '''
    # open list to write 100,000 websites to memory from csv
    #
    websitelist = []

    # open file in universal line ending mode
    with open("100kwebsites.csv", 'rU') as infile:
        # read the file as a dict for each row ({header : value})
        reader = csv.DictReader(infile)
        webdata = {}
        for row in reader:
            for header, value in row.items():
                try:
                    webdata[header].append(value)
                except KeyError:
                    webdata[header] = [value]
        
    # store 100,000 websites to a list to later use
    #
    websitelist = webdata['website']
    
    # insert column header
    #
    websitelist.insert(0,'website')
    #print len(websitelist)
    #print websitelist
    
    # open list to write 100,000 last names to a list
    #
    lastlist = []
    
    # open file with 100,000 last names and write them to the list
    #
    with open("last_names.csv", 'rU') as infile:
        # read the file as a dict for each row ({header : value})
        reader = csv.DictReader(infile)
        lastdata = {}
        for row in reader:
            for header, value in row.items():
                try:
                    lastdata[header].append(value)
                except KeyError:
                    lastdata[header] = [value]

    lastlist = lastdata['name']
    # insert column header
    lastlist.insert(0, 'lastname')
    # Convert names to lowercase
    #
    lastlist = [x.lower() for x in lastlist]
    #print lastlist
    
    # open list to write 100,000 first names to a list
    #
    firstlist = []

    # open file with 100,000 last names and write them to the list
    #
    with open("first_names.csv", 'rU') as infile:
        # read the file as a dict for each row ({header : value})
        reader = csv.DictReader(infile)
        firstdata = {}
        for row in reader:
            for header, value in row.items():
                try:
                    firstdata[header].append(value)
                except KeyError:
                    firstdata[header] = [value]

    # get items from dictionary and place in list
    firstlist = firstdata['name']
    # insert column header
    firstlist.insert(0, 'firstname')
    # Convert names to lowercase
    #
    firstlist = [x.lower() for x in firstlist]
    #print firstlist
    
    # open lists to write 100,000 address numbers and streets
    #
    addnumlist = []
    addstreetlist = []
    
    # open file with 100,000 last names and write them to the list
    #
    with open("addresses_philly.csv", 'rU') as infile:
        # read the file as a dict for each row ({header : value})
        reader = csv.DictReader(infile)
        adddata = {}
        for row in reader:
            for header, value in row.items():
                try:
                    adddata[header].append(value)
                except KeyError:
                    adddata[header] = [value]

    # get items from dictionary and place in list
    addnumlist = adddata['number']
    addstreetlist = adddata['street']

    # insert column headers
    addnumlist.insert(0, 'addressnumber')
    addstreetlist.insert(0, 'addressstreet')

    # Convert streets to lowercase
    #
    addstreetlist = [x.lower() for x in addstreetlist]
    #print addstreetlist

    # generate list of 100,000 random numbers between 0 and 100
    #
    randomlist = []
    for i in range(100000):
        randomlist.append(random.randint(0,100))
                          
    # insert column header
    #
    randomlist.insert(0, 'randnum')

    #print len(randomlist)
    
    # break down data into lists of 3, 100, 1000, and full length (100,000)
    # then write to new .csv file. Include headers for later processing.
    # 3
    #
    websitelist3 = websitelist[0:4]
    lastlist3 = lastlist[0:4]
    firstlist3 = firstlist[0:4]
    addnumlist3 = addnumlist[0:4]
    addstreetlist3 = addstreetlist[0:4]
    randomlist3 = randomlist[0:4]
    
    # open file, zip lists, and write them as rows
    #
    with open("mythree.csv", 'wb') as myfile:
        wr = csv.writer(myfile, dialect='excel')
        for i in zip(randomlist3, websitelist3, lastlist3, firstlist3, addnumlist3, addstreetlist3):
            wr.writerow(i)

    # 100
    #
    websitelist100 = websitelist[0:101]
    lastlist100 = lastlist[0:101]
    firstlist100 = firstlist[0:101]
    addnumlist100 = addnumlist[0:101]
    addstreetlist100 = addstreetlist[0:101]
    randomlist100 = randomlist[0:101]

    # open file, zip lists, and write them as rows
    #
    with open("myhundred.csv", 'wb') as myfile:
        wr = csv.writer(myfile, dialect='excel')
        for i in zip(randomlist100, websitelist100, lastlist100, firstlist100, addnumlist100, addstreetlist100):
            wr.writerow(i)


    # 1000
    #
    websitelist1000 = websitelist[0:1001]
    lastlist1000 = lastlist[0:1001]
    firstlist1000 = firstlist[0:1001]
    addnumlist1000 = addnumlist[0:1001]
    addstreetlist1000 = addstreetlist[0:1001]
    randomlist1000 = randomlist[0:1001]

    # open file, zip lists, and write them as rows
    #
    with open("mythousand.csv", 'wb') as myfile:
        wr = csv.writer(myfile, dialect='excel')
        for i in zip(randomlist1000, websitelist1000, lastlist1000, firstlist1000, addnumlist1000, addstreetlist1000):
            wr.writerow(i)


    # 100,000
    #
    # open file, zip lists, and write them as rows
    #
    with open("my100k.csv", 'wb') as myfile:
        wr = csv.writer(myfile, dialect='excel')
        for i in zip(randomlist, websitelist, lastlist, firstlist, addnumlist, addstreetlist):
            wr.writerow(i)

    '''
    # write columns
    with open("testcol.csv", 'wb') as myfile:
        writer = csv.writer(myfile, delimiter=',')
        for i in mylist:
            writer.writerow([i])
    '''

    # Exit gracefully
    #
    return 

# Begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[0:])

# End of file
