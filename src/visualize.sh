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



echo "Parsing strings"
ARG1=$(ruby -e "puts (1..200).to_a.shuffle.join(' ')");
 .././push_swap $ARG1 | .././checker -v -p $1 $ARG1 > parse.txt
python3.7 visualize_psh_swp.py




