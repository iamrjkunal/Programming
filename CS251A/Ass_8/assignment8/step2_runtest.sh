#!/bin/bash
params=$(cat params.txt)
threads=$(cat threads.txt)
if [ ! -d "logfiles" ]; then
   mkdir logfiles # Control will enter here if $DIRECTORY doesn't exist.
fi

for param in $params
do
	for thread in $threads
	do
		/bin/bash ./log_for_each_file.sh $param $thread >  logfiles/$param"_"$thread".txt"
		echo  $param $thread
	done
done
