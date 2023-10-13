# !/bin/bash

echo "Reverse digits version 1"
read -p "Enter a number: " num
num_str="$num"

for ((i=${#num_str};i>-1;i--)); do
    echo "${num_str:i:1}"
done