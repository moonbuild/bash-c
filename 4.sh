# !/bin/bash
echo "This programm differnetiates between odd and even"
read -p "Enter a Number: " num

if (( num%2 == 0 )); then
    echo "It is an even number"
else
    echo "Odd number"
fi