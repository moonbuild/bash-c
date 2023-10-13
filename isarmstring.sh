# !/bin/bash

echo "Is Number Armstrong?"

read -p "Enter a number: " num
num_str="$num"
num_length=${#num_str}
sum=0
for ((i=0;i<$num_length;i++)); do
    digit=${num_str:i:1}
    sum=$((sum+digit**num_length))
done

if [ $num -eq $sum ]; then
    echo "Armstrong number"
else
    echo "Not armstrong number"
fi