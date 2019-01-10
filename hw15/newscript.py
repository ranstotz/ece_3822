#!/usr/bin/env python
# -*- coding: utf-8 -*- 

# import required modules:
#
import os
import sys

import string
import collections
from operator import itemgetter
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
       
    # open list for tokens
    #
    corpus = []

    # open argv[1] as a list of file names in corpus
    # iterate over lines in list file
    #
    for line in open(argv[1], 'rb'). readlines():
        
        # Strip linefeed
        #
        line = line.rstrip()

        # open file 
        # 
        fp = open(line, 'rb')

        # store file contents to variable
        #
        file_contents = fp.read()
        #file_contents = file_contents.decode('utf8', 'ignore')

        # strip punctuation from string and convert to lowercase
        #
        table = string.maketrans("","")

        file_contents = file_contents.translate(table, string.punctuation).lower()
        
        corpus.append((line, file_contents))

    #print token_dict
     
    # vectorize the documents
    tfidf = TfidfVectorizer(tokenizer=tokenize, stop_words='english')

    # transform them into a tfidf matrix
    tfs = tfidf.fit_transform([content for file, content in corpus])
    
    #function to find similar documents
    #
    def find_similar(tfidf_matrix, index, top_n = 5):
        cosine_similarities = linear_kernel(tfidf_matrix[index:index+1], tfidf_matrix).flatten()
        related_docs_indices = [i for i in cosine_similarities.argsort()[::-1] if i != index]
        return [(index, cosine_similarities[index]) for index in related_docs_indices][0:top_n]
        
    # open list to store the most common files from each element in the first 
    # for loop
    #
    list_of_indices = []
    
    for i in range(0, len(corpus)):
        sims = []
        for index, score in find_similar(tfs, i):
            sims.append((score, index))
        list_of_indices.append([i, max(sims, key=itemgetter(1))[1], max(sims, key=itemgetter(1))[0]])
    
    # store [index, index, and similarity] of the two most common files
    most_sim = max(list_of_indices, key=lambda item:item[2])

    # print the indices and similarity of the most similar docs
    print "[index1, index2, similarity coefficient] of most similar docs"
    print most_sim

    # print filenames of most similar docs
    #
    print "\nmost similar docs are..."
    print corpus[most_sim[0]][0]
    print "\nand\n"
    print corpus[most_sim[1]][0]
    
    # Exit gracefully
    #
    return 

# Begin gracefully
#
if __name__ == "__main__":
    
    main(sys.argv[0:])

# End of file
