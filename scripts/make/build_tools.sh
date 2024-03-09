#!/bin/bash

# no arguments

make -s -C tools >&2

retVal=$?
if [ $retVal -ne 0 ]; then
    echo "Failed to build tools"
fi
exit $retVal