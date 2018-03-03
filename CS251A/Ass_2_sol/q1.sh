#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
com_count=0
str_count=0
count=0

total=`find "$1" -name '*.c' | wc -l`
find "$1" -name '*.c' | while read line; do
	output=`awk -f $2 $line`
	
	str=`echo $output | cut -d" " -f1`
	com=`echo $output | cut -d" " -f2`
	
	str_count=$((str+str_count))
	com_count=$((com+com_count))
	count=$((count+1))
	
	if [ $count -eq $total ]
	then
		echo $str_count "strings and" $com_count "lines of comments"
	fi
done
