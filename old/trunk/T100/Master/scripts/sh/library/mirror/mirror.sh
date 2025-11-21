#!/bin/bash

function mirror_sort()
{
    local mirror_list=$1

    for mirror_url in ${mirror_list[@]}
    do
        echo "mirror url : $mirror_url"
    done
    return 1
}
