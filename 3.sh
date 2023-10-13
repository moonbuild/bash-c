echo "This program calculates sum of two numbers"
read -p "Enter Number 1: " num1
read -p "Enter Number 2: " num2

sum=$(( $num1+$num2 ))
echo "$num1+$num2 = $sum"