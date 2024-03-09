#!/bin/bash

SHA1SUM=$1
OUTCODE=$2

# quote to allow space
if [ -z "${SHA1SUM}" ]; then echo "$0: missing argument: SHA1SUM"; exit 1; fi
if [ -z "${OUTCODE}" ]; then echo "$0: missing argument: OUTCODE"; exit 1; fi

# no quotes on SHA1SUM to allow padding command line arguments from parent
${SHA1SUM} -c ge007.${OUTCODE}.sha1
retVal=$?

if [ $retVal -ne 0 ]; then
    echo -e "\n\n"
    echo -e "\033[41m\033[37m                                                                                \033[0m"
    echo -e "\033[41m\033[37m    ERROR: NOT MATCH!                                                           \033[0m"
    echo -e "\033[41m\033[37m                                                                                \033[0m"
    echo -e "\n\n"

    RESPONSE=0
    read -t 5 -p "Do you want to check Source Files (y/n)? " choice
    case "$choice" in 
    y|Y ) RESPONSE=1; ;;
    n|N ) RESPONSE=2; ;;
    * ) RESPONSE=3; ;;
    esac

    if [ $RESPONSE -eq 1 ]; then
        echo "Please wait while we determine which files are affected..."
        # scripts file relative to root source control directory
        ./scripts/test_files.sh -c -i scripts/ge007.${OUTCODE}-test_basis.csv
    fi

else
    echo -e "\n\n"
    echo -e "\033[42m\033[37m                                                                                \033[0m"
    echo -e "\033[42m\033[37m    MATCH!                                                                      \033[0m"
    echo -e "\033[42m\033[37m                                                                                \033[0m"
    echo -e "\n\n"
fi

exit $retVal
