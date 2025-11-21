#!/bin/bash

function env_init()
{
    export readonly ORIGINAL_PATH=$PATH
    export readonly TOP_DIR=$( cd "$( dirname "${BASH_SHOURCE[0]}" )" && pwd )
}

function env_check()
{
    local app_list=( $1 )

    echo -n "-> Checking for necessary tools... "
    for item in ${app_list[@]};
    do
        command -v "$item" > /dev/null 2>&1
        [[ $? != 0 ]] && {
            error="$_err $item"
        }
    done
    [[ -n $error ]] && {
        echo "Some of necessary tools not found: $error"
    } || {
        echo "done"
    }
}
