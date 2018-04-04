#!/bin/bash

i=0;
delay=0.25

while [ $? -lt 127 ] && [ $i -ne 200 ];
do
	sleep $delay;
	((i = i + 1))
	tmp=$(echo "." | ./radamsa/bin/radamsa)
	if [ "$(uname -s)" == "Linux" ];
	then
		opts=$(echo -e "\n--\n-a\n-r\n-t\n-G\n-l\n-A\n-n" | shuf -n 1 2> /dev/null);
	else
		opts=$(echo -e "\n--\n-a\n-r\n-t\n-G\n-l\n-A\n-n" | gshuf -n 1 2> /dev/null);
	fi;
	printf "\033[31mTesting |%s||%s|\n\033[0m" "$opts" "$tmp";
	(echo "$tmp" | xxd) || true
	./ft_ls "$opts" "$tmp";
done;

if [ $i -eq 200 ];
then
	printf "\e[32mSuccess\033[0m";
	exit 0;
else
	exit 1;
fi;