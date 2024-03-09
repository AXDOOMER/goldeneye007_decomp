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

SRC=
CONTINUE_ON_ERROR=0
VERBOSE=0

usage() {
    echo "checks md5s generated from make_test_files_basis.sh"
    echo ""
    echo "$0 usage:"
    echo ""
    echo "    $0 -i file [-c]"
    echo ""
    echo "    -c                       continue on error"
    exit 0;
}

[ $# -eq 0 ] && usage
while getopts "i:chv" arg; do
  case $arg in
    i)
        SRC="${OPTARG}"
      ;;
    c)
        CONTINUE_ON_ERROR=1
      ;;
    v)
        VERBOSE=1
      ;;
    h | *) # Display help.
      usage
      exit 0
      ;;
  esac
done

if [ "${SRC}" = "" ] ; then
    usage
fi

if [ ! -f "${SRC}" ]; then
    echo "File not found: ${SRC}"
    exit 1
fi

OLDIFS=$IFS
IFS=","
MATCHING=1
NOFILES=1
TMP=$(mktemp /tmp/ge_test_files.XXXXXX)
TMP2=$(mktemp /tmp/ge_test_files.XXXXXX)

while read MD5 SECTION FILE
do
    if [ ! -f "${SRC}" ]; then
        echo "File not found: ${SRC}"
        continue
    fi
    if [ -f $FILE ]; then
        mips-linux-gnu-objcopy -j "${SECTION}" -O binary "${FILE}" "${TMP}"
        ACTUAL=$(md5sum -b "${TMP}" | cut -c -32 | tr '[:upper:]' '[:lower:]')
        EXPECTED=$(echo "${MD5}" | tr '[:upper:]' '[:lower:]')
        FILENAME=$(echo $FILE | sed -E -e 's/build\/[uje]\/src\//src\//g;');
        VERSION=$(echo $FILE | sed -E -e 's/build\/([uje])\/.*/\1/g;');
        if [ ! -f "build/${VERSION}-match/${FILENAME}" ]; then
            NOFILES=0
        fi

        if [ "${ACTUAL}" != "${EXPECTED}" ] ; then
            MATCHING=0
            #if [ "${SECTION}" == ".data" ] || [ "${SECTION}" == ".rodata" ] ; then
            #    echo -e "\033[93m\033[1A";
            #fi
            echo "checksums differ, section'${SECTION}', file: '${FILE}'.\nComparing Files..."
            if [ -f "build/${VERSION}-match/${FILENAME}" ]; then
                mips-linux-gnu-objcopy -j "${SECTION}" -O binary "build/${VERSION}-match/${FILENAME}" "${TMP2}"
                (diff -y --suppress-common-lines <(xxd -c8 $TMP) <(xxd -c8 $TMP2) && echo -e "\033[92mFiles Identical!") || \
                (\
                    echo -e "\033[91mDifference Found, Dumping assembly! (${FILE}New.mips)" && touch "${FILE}New.mips" &&  touch "${FILE}Match.mips" &&  \
                    mips-linux-gnu-objdump --all-headers --disassemble --debugging --source --full-contents --line-numbers "build/${VERSION}-match/${FILENAME}" > "${FILE}Match.mips" && \
                    mips-linux-gnu-objdump --all-headers --disassemble --debugging --source --full-contents --line-numbers "${FILE}" > "${FILE}New.mips" \
                );
            else
                echo -e "\033[93mNo Previously matching files to compare... Please run this test again on a matching build to generate."
            fi


            if [ ${CONTINUE_ON_ERROR} -eq 0 ] ; then
                IFS=$OLDIFS
                rm -f "${TMP}"
                rm -f "${TMP2}"
                exit 1
            fi
        else
            if [ ${VERBOSE} -eq 1 ]; then
                echo -e "\033[92mpass: section'${SECTION}' ${FILE}"
            fi
        fi
        echo -e "\033[m\033[1A"
    fi
done < "${SRC}"

if [ ${MATCHING} -eq 1 ] && [ ${NOFILES} -eq 1 ] ; then
    cp -r build/${VERSION}/* build/${VERSION}-match
    ./make_test_files_basis.sh "ge007.${VERSION}-test_basis.csv" -v ${VERSION}
fi

IFS=$OLDIFS
rm -f "${TMP}"
rm -f "${TMP2}"

exit 0
