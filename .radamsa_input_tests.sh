#!/bin/bash

i=0;
delay=0.25

while [ $? -lt 127 ] && [ $i -ne 200 ];
do
	tmp=$(echo "." | radamsa)
	opts=$(echo -e "\n--\n-a\n-r\n-t\n-G\n-l\n-A\n-n" | shuf -n 1)
	printf "\033[31mTesting |%s||%s|\n\033[0m" "$opts" "$tmp";
	(echo "$tmp" | xxd) || true
	./ft_ls "$opts" "$tmp";
	sleep $delay;
	i=$[$i+1];
done;

if [ $i -eq 200 ];
then
	printf "\e[32mSuccess\033[0m";
	exit 0;
else
	exit 1;
fi;