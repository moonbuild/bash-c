# !/bin/bash

echo "Display prime numbers"

if [ $# -ne 1 ]; then
    echo "Pass an argument"
    exit 1
fi

num=$1

if [ $num -le 1 ]; then
    echo "Not valid"
    exit 1;
elif [ $num -eq 2 ]; then
    echo "2"
    exit 0;
fi

for ((i=2;i<num;i++)); do 
    isprime=true
    for ((j=2;j*j<=i;j++)); do
        if [ $((i%j)) -eq 0 ]; then
            isprime=false
            break
        fi
    done
    if [ "$isprime" == "true" ]; then
        echo $i
    fi
done