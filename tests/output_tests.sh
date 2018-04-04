#!/bin/bash
#full test: [AarRltn]{1,7}

git clone https://github.com/asciimoo/exrex.git || true

arg1="ft_printf"
arg2="."
#arg3="..."

if [ "$(uname -s)" == "Darwin" ];
then
	python2.7 exrex/exrex.py -o opt.list '[A]?[a]?[r]?[R]?[l]?[t]?[n]?'
else
	python2.7 exrex/exrex.py -o opt.list '[A]?[a]?[r]?[l]?[n]?'
fi;

while read -r line;
do
	echo "diff for: [ ls -$line |$arg1| |$arg2| |$arg3| ]" && \
	./ft_ls "-$line" $arg1 $arg2 $arg3 2> /dev/null | tr -d ' ' > /tmp/diff1;
	r1=$?
	ls "-$line" $arg1 $arg2 $arg3 2> /dev/null | tr -d ' ' > /tmp/diff2;
	r2=$?
	if ! cmp /tmp/diff1 /tmp/diff2 >/dev/null 2>&1
	then
		printf "\e[31mKO\e[39m"
		PAGER=cat diff /tmp/diff1 /tmp/diff2
	else
		printf "\e[32mOK\e[39m"
	fi
	printf " - return codes: "
	if [ $r1 -eq $r2 ];
	then
		printf "\e[32mOK\e[39m\n"
	else
		printf "\e[31mKO\e[39m\n"
	fi;
done <opt.list;
