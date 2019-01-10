#!/bin/bash

export trigrams=`find $1 -type f -exec cat {} + | tr -sc 'a-zA-Z' '\012' | tr 'A-Z' 'a-z' | awk -- 'first!=""&&second!="" {print first,second,$0; } {first=second; second=$0;}' | wc -l`

find $1 -name '*.txt' -exec cat {} \; | tr '[:upper:]' '[:lower:]' | tr -sc 'a-z' '\n' |   awk -- 'first!=""&&second!="" { print first,second,$0; } { first=second; second=$0; }' | sort | uniq -c | sort -nr | awk -v trigrams=$trigrams 'BEGIN { format = "%-30s %-15s %-15s %-15s\n"; printf format, " ", " ", "Frequency", " "; printf format, "Trigram", "No.", "Percentage", "Cumulative"} {printf format, $2" "$3" "$4, $1, $1/trigrams, (sum+=$1)/trigrams}'
