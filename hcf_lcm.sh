function find_hcf(){
    local a=$1
    local b=$2
    while [ $b -ne 0 ]; do
        local temp=$b
        b=$((a%b))
        a=$temp
    done
    echo $a
}

function find_lcm(){
    local a=$1
    local b=$2
    local res=$(find_hcf 12 18)
    local product=$((a*b))
    local lcm=$((product/res))
    echo $lcm
}
res2=$(find_lcm 12 18)
echo $res2
