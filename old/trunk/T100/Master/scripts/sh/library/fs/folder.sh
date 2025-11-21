#!/bin/bash

function folder_exists()
{
    local   result = 0;
    if [ -d $1 ]; then
        result = 1;
    fi

    return $result;
}
