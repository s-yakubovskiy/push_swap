#!/usr/bin/env bash
#ARG=$(ruby -e "puts (1..10).to_a.shuffle.join(' ')")
#./push_swap $ARG | wc -l
#ARG=$(ruby -e "puts (1..10).to_a.shuffle.join(' ')")
#./checker $ARG

#ARG=$(ruby -e "puts (1..18000).to_a.shuffle.join(' ')");
## echo $ARG;
# ./push_swap -v $ARG | ./checker -v $ARG

#echo $1
#




echo "Testing 100 elements in 100 rand tests. Checker output"
sleep 2
while [[ $i -lt 100 ]]
do
ARG1=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')");
 .././push_swap $ARG1 | .././checker -v $1 $ARG1
i=$[$i+1]
done

echo "Testing 500 elements in 50 rand tests. Checker output"
sleep 2
while [[ $j -lt 50 ]]
do
ARG2=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");
 .././push_swap $ARG2 | .././checker -v $1 $ARG2
j=$[$j+1]
done


echo "Testing 100 elements in 50 rand tests for avg"

sum=$(while [[ $k -lt 50 ]]
do
ARG3=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')");
# echo $ARG;
 .././push_swap $ARG3 | wc -l
k=$[$k+1]
done | awk 'NF{sum+=$1} END {print sum}')

echo "avg: $(($sum / 50))"
echo ""

echo "Testing 500 elements in 50 rand tests for avg"
sum=$(while [[ $x -lt 50 ]]
do
ARG4=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");
# echo $ARG;
 .././push_swap $ARG4 | wc -l
x=$[$x+1]
done | awk 'NF{sum+=$1} END {print sum}')

echo "avg: $(($sum / 50))"
echo ""





















#
#echo "Testing 500 elements in 50 rand tests"
#sum=$(while [[ $i -lt 50 ]]
#do
#ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");
## echo $ARG;
# ./push_swap $ARG | wc -l
#i=$[$i+1]
#done | awk 'NF{sum+=$1} END {print sum}')
#
#echo "avg: $(($sum / 50))"
#echo ""

