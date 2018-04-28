#!/bin/bash
threads=$(cat threads.txt)
params=$(cat params.txt)
if [ ! -d "inputfiles" ]; then
   mkdir inputfiles # Control will enter here if $DIRECTORY doesn't exist.
fi

#processing for graph type a
for thread in $threads
do
    cat logfiles/*_$thread.txt > inputfiles/$thread"_type_a.txt"
done


#processing for graph type  b
for thread in $threads
do
    /bin/bash ./generate_avg_for_thread.sh $thread >  inputfiles/$thread"_type_b.txt"
done

#processing for graph type c
/bin/bash ./generate_speed_up.sh  >  inputfiles/type_c.txt

#processing for graph type d
/bin/bash ./generate_speed_up_var.sh >  inputfiles/type_d.txt
