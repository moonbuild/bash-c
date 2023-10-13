# !/bin/bash

echo "Split ot digits version 1"
read -p "Enter a number: " num
num_str="$num"

for((i=0;i<${#num_str};i++)); do
    echo "${num_str:i:1}"
done
