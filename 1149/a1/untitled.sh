#!/bin/bash
usage() {
	echo "improper usage"
}
if [ $# -ne 1 ]; then
	usage
exit 1
elif [ ${1} -lt 1 ]; then
	usage
	exit 1
fi
x=1
while [ $x -le $1 ]; do
	echo $x
	x=$((x+1))
done