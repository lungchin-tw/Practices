#!/bin/bash

set -x


function receiver {
    vx=( "$1" )
    echo "1st Arg: "${vx[@]}

    echo "for loop:"
    for elem in ${vx[@]}
    do
        echo "elem: "$elem
    done

    sleep 3s

    vy=( "$2" )
    echo "1st Arg: "${vy[@]}

    echo "for loop:"
    for elem in ${vy[@]}
    do
        echo "elem: "$elem
    done
}


ax=( 1, 2, 3 )
ay=( 10, 20, 30 )

receiver "$(echo ${ax[@]})" "$(echo ${ay[@]})"

empty='';
if [ -z "$empty" ]
then
    echo "\$var is empty"
else
    echo "\$var is NOT empty"
fi