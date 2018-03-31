#!/bin/bash
#full test: [AarRltn]{1,7}
python2.7 exrex/exrex.py -o opt.list '[A]?[a]?[r]?[R]?[l]?[t]?[n]?'
while read line;
do
	echo "diff for: [ls -$line .]" && \
	./ft_ls "-$line" . 2> /dev/null | tr -d ' ' > /tmp/diff1;
	ls "-$line" .  2> /dev/null | tr -d ' ' > /tmp/diff2;
	if ! cmp /tmp/diff1 /tmp/diff2 >/dev/null 2>&1
	then
		printf "\e[31mKO\e[39m\n"
		PAGER=cat diff /tmp/diff1 /tmp/diff2
	else
		printf "\e[32mOK\e[39m\n"
	fi
done <opt.list;