# !/bin/bash

echo "Is prime or not?"

if [ $# -ne 1 ]; then
    echo "Pass an argument"
    exit 1
fi
num=$1
if [ $num -le 1 ]; then
    echo "NOt a Prime"
    exit 0;
fi

for ((i=2;i*i<=num;i++)); do
    if [ $((num%i)) -eq 0 ]; then
        echo "NOT a Prime"
        exit 0;
    fi
done
echo "IS a Prime"