# !bin/bash

if [ ! $# -eq 2 ]; then
    echo "You need to enter two parameters, like so: "
    echo "~~ bash practice.sh 0 10 ~~"
    exit 1
elif [ $1 -ge $2 ]; then
    echo "The second argument should be greater than the first, like so: "
    echo "~~ bash practice.sh 0 10 ~~"
    exit 1
fi

arg1=$1
arg2=$2

for (( i=arg1; i<=arg2; i++ )); do
    echo $i
done