#!/bin/bash

source ../library/os/env.sh
source ../library/fs/file.sh

source ./scripts/edk2.sh

function edk2_build()
{
    env_init
    env_check "gcc"

    #echo $ORIGINAL_PATH
    #echo $TOP_DIR

    edk2_run
}

edk2_build


