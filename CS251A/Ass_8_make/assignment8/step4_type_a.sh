#!/bin/bash
threads=$(cat threads.txt)
if [ ! -d "graphs" ]; then
   mkdir graphs # Control will enter here if $DIRECTORY doesn't exist.
fi
for thread in $threads
do
    inputf="inputfiles/"$thread"_type_a.txt"
    outputf="graphs/"$thread"_type_a.eps"
    echo $inputf
    echo $outputf
    gnuplot -e "output_file='$outputf';input_file='$inputf'" step4_type_a.p
done
