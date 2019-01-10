#!/usr/bin/env python

# import required modules:
#
import os
import sys
import string
from collections import OrderedDict

# factorial recursion example
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)

# define a function to multiply 2 numbers recursively using +/- operators only
#
def product(n, m):
    if m == 0:
        return 0
    print n, m
    return n + product(n, m-1)

# flatten dictionary
#
def flatten_dict(d):
    # function to parse keys and values
    #
    def expand(key, value):
        
        # check if value is a dictionary, if so recurse to flatten_dict
        # until value is not a dictionary instance
        #
        if isinstance(value, dict):
            # add a . to the key with the key in the nested dict 
            return [ (key + '.' + k, v) for k, v in flatten_dict(value).items() ]
        else:
            return [ (key, value) ]

    # list comprehension to iterate over items in the dictionary (d)
    # and a nested for loop to parse the keys/values in expand.
    #
    items = [ item for k, v in d.items() for item in expand(k, v) ]

    #mydict = dict(items)
    #sorteddict = OrderedDict(sorted(mydict.items(), key=lambda x: x[1]))
    #return sorteddict
    return dict(items)

# unflatten dict
#
def unflatten_dict(d):
    
    # function to add key
    def addk(res,key,value):
        # check if the length of key is 1, if so, no '.' delimiter exists
        if len(key) == 1:
            res[key[0]] = v
        # if longer than 1, '.' exists 
        else:
            # initialize the root key level
            kinit = key[0]
            # set the remainder of the key string as 'key'
            key = key[1:]
            # check if entry exists in d[kinit]
            try:
                res[kinit] = addk(res[kinit],key,value)
            # if they do not exist
            except KeyError:
                # set result 1 as value
                res1 = value
                # iterate through the remainder of the string
                for k1 in key:
                    # set key from after '.' char and res1 (value)
                    res1 = {k1:res1}
                    # set the first character in the key as res1
                    res[kinit] = res1
        return res

    # open dictionary
    res = {}

    # iterage through items in dictionary passed to function
    for k,v in d.items():
        # split the key with '.' as delimiter
        key = k.split('.')
        # pass key and value to the addk (add key) function
        res = addk(res,key,v)
    
    # sort by key
    mydict = res
    sorteddict = OrderedDict(sorted(mydict.items(), key=lambda x: x[0]))
    return sorteddict

    #return res

# treemap function
#
def treemap(func, mylist):
    # open list to store data
    #
    result = []
    
    # iterate through list passed as function parameter
    #
    for i in mylist:
        # if the type is int (e.g. not a list), append it to the result list
        #
        if type(i) == int:
            result.append(func(i))
            
        # else the type is a list and the function recurses until an integer
        # is detected. The function passed is applied
        #
        else:
            result.append(treemap(func, i))

    return result

# tree_reverse function
#
def tree_reverse(mylist):

    # reverse the list
    #
    mylist.reverse()
    
    # open list to store data
    #
    result = []

    # iterate over list
    #
    for i in mylist:
        
        # check if type is list, if so recurse and append
        #
        if type(i) == mylist:
            result.append(tree_reverse(i))
        
        # else, append the entry (integer)
        #
        else: 
            result.append(i)
            
    return result
    


# main function
#
def main(argv):

    #print product(8, 4)
    #print flatten_dict({'a': 1, 'b': {'x': 2, 'y': 3}, 'c': 4})
    #print unflatten_dict({'a': 1, 'b.x': 2, 'b.y': 3, 'c': 4})
    #print treemap(lambda x: x*x, [1, 2, [3, 4, [5]]])
    
    print tree_reverse([[1, 2], [3, [4, 5]], 6])
    # Exit gracefully
    #
    return 

# Begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[0:])

# End of file
