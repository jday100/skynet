#!/bin/bash

function file_exists()
{
    local   result = 0;
    if [ -e $1 ]; then
        result = 1;
    fi

    return $result;
}
