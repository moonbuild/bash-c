# !/bin/bash
echo "PROGRAM: N natural numbers"
echo 
if [ $# -ne 1 ]; then
    echo "Pass an argument"
    exit 1
fi
num=$1
for((i=1; i<=$num;i++));
do
    echo $i;
done