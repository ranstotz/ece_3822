#!/bin/sh

# Random number generator. Inputs a text file of the mp3 list as the first argument 

# Start the infinite while loop
while true
do

# First, check if the song counter exists. If it does, that means the file was
# killed while executing and the shuffler will continue where it left off.
# If the file does not exist, that means it's the first time it is running and
# the counter starts at 1.
if [ ! -f ./counter.txt ]
then
song_counter=1
echo "$song_counter" >counter.txt
fi

# Shuffle a list of 1-100, index 0 and sends them to a text file. The list is 
# continuously appended to run infinitely.
shuf -i 0-99 >> shuffle.txt

# Begin for loop over 100 entries in the playlist.
for i in `seq 1 100`
do

# This 'sed' command accesses the the line of the shuffled text file according 
# to the counter.
randnum_index_from_counter=`sed "${song_counter}q;d" shuffle.txt`

# Access lines in the text file in argument 1, the mp3 list. Then print and rest 1 sec.
random_song=`sed "${randnum_index_from_counter}q;d" "$1"`
echo "$random_song"

# Increment song counter and overwrite the text file with the new counter.
song_counter=$((song_counter+1))
echo "$song_counter" >counter.txt

sleep 1
done

done
