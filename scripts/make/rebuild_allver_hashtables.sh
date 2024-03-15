#!/bin/bash

# execute from the root source control directory.
dirname=$(pwd)
shopt -s extglob           # enable +(...) glob syntax
result=${dirname%%+(/)}    # trim however many trailing slashes exist
result=${result##*/}       # remove everything before the last / that still remains
result=${result:-/}        # correct for dirname=/ case

if [ $result = "scripts" ] ; then
    cd ..
fi

./scripts/make/build_hashtable.sh -v u -o scripts/ge007.u-test_basis.csv
./scripts/make/build_hashtable.sh -v j -o scripts/ge007.j-test_basis.csv
./scripts/make/build_hashtable.sh -v e -o scripts/ge007.e-test_basis.csv