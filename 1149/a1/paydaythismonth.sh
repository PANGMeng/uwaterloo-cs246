#!/bin/bash
answer() { 
	if [ $1 -eq 31 ]; then
		echo “This month: the ${1}st”
	else
		echo “This month: the ${1}th”
	fi
}
answer `cal | awk {print $6} | egrep "[0-9]" | tail -1`