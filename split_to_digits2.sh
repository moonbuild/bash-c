# !bin/bash

echo "Split to digits version2"
read -p "Enter a number: " num

digits=()

while [ $num -gt 0 ]; do
    digit=$((num%10))
    digits+=($digit)
    num=$((num/10))
done

for ((i=${#digits[@]}; i>-1 ;i--)); do
    echo "${digits[i]}"
done