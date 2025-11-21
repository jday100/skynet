#!/bin/bash

function down_file()
{
    source $TOP_DIR/../library/net/wget.sh

    local down_type=$1
    local down_url=$2
    local down_name=$3

    wget_get down_url down_name

    return 1
}
