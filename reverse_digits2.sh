# !/bin/bash
echo "Reverse digits version 2"
if [ $# -ne 1 ]; then
    echo "Pass an argument"
    exit 1
fi

num=$1
while [ $num -gt 0 ]; do
    digit=$((num%10))
    num=$((num/10))
    echo $digit
done