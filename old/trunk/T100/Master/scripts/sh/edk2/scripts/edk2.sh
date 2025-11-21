#!/bin/bash

echo $TOP_DIR

#source $TOP_DIR/../../../library/mirror/mirror.sh

#echo $TOP_DIR/library/mirror/mirror.sh

function edk2_mirror()
{
    echo $TOP_DIR

    source $TOP_DIR/../library/mirror/mirror.sh

    mirror_list[0]="111"

    mirror_sort mirror_list

    return 1
}

function edk2_down()
{
    source $TOP_DIR/../library/lock/lock.sh
    source $TOP_DIR/../library/download/function.sh

    lock_file "down"

    local result=$?

    if [ "$result" -ge 0 ] ; then
        down_file "wget" "site" "file"
        return 1
    else

        return 1
    fi

    return 1
}

function edk2_unpack()
{
    return 1
}

function edk2_make()
{
    return 1
}

function edk2_run()
{
    edk2_mirror

    local mirror_list=$?

    edk2_down mirror_list

    edk2_unpack

    edk2_make
}
