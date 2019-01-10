#!/usr/bin/env python

# import required modules:
#
import os
import sys
import string
import collections

import nltk

from nltk.corpus import stopwords
from nltk.stem.porter import *

from sklearn.feature_extraction.text import TfidfVectorizer
from nltk.stem.porter import PorterStemmer

from sklearn.metrics.pairwise import linear_kernel


# create a stemmer
#
stemmer = PorterStemmer()

# stem the text
def stem_tokens(tokens, stemmer):
    stemmed = []
    for item in tokens:
        stemmed.append(stemmer.stem(item))
    return stemmed

# tokenize text with nltk library and stem_tokens function
def tokenize(text):
    tokens = nltk.word_tokenize(text)
    stems = stem_tokens(tokens, stemmer)
    return stems

# main function
#
def main(argv):
       
    # open dictionary for tokens
    #
    token_dict = {}

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
        lowers = file_contents.lower()
        file_contents = lowers.translate(None, string.punctuation)
        
        token_dict[line] = file_contents

    #print token_dict
     
    tfidf = TfidfVectorizer(tokenizer=tokenize, stop_words='english')
    tfs = tfidf.fit_transform(token_dict.values())
    
       
    # Exit gracefully
    #
    return 

# Begin gracefully
#
if __name__ == "__main__":
    main(sys.argv[0:])

# End of file
