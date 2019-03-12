#!/bin/bash

for i in {1..25}
do
	echo $((1 + RANDOM % 1000)) >> tmp.tmp
done
	echo -n $(cat tmp.tmp | tr '\n' ' ')
	rm -rf tmp.tmp
   # echo "Welcome $i times"