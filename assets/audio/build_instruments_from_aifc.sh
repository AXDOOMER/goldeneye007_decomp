#!/bin/bash

# This is a helper script to build the instruments.ctl and instruments.tbl files.
# It requires as input an .inst file, and all associated .aifc files.
# This is designed to be used with `extract_instruments_to_aifc`, which will result in a matching ROM.

# set paths for commands. These are relative to the assets/audio folder.
GIC="../../tools/gaudio/bin/gic"
INST_FILE="aifc_instruments/instruments.inst"
OUT_FILE_BASE="instruments"

if [ ! -f "${GIC}" ] ; then
    echo "missing gic. make tools/gaudio first"
    exit 1
fi

if [ ! -f "${INST_FILE}" ] ; then
    echo ".inst file not found: ${INST_FILE}"
    exit 1
fi


# use gaudio instrument compiler to build instruments.ctl and instruments.tbl.
# The .inst file contains metadata (.ctl) and path to .aifc (.tbl).
# gic accepts the filename prefix ("instruments") then automatically sets the extension.
# The "--sort-meta" option tells gic that the meta property specifying sort
# order should be used to explain how elements should be placed in the resulting
# files. This is required for a matching ROM, but can otherwise be excluded.
"${GIC}" --in="${INST_FILE}" --out="${OUT_FILE_BASE}" --sort-meta



# Print a status indicator if this matches the original ROM file or not.
OUT_FILE="${OUT_FILE_BASE}.ctl"
ACTUAL=$(md5sum -b ${OUT_FILE} | cut -c -32 | tr '[:upper:]' '[:lower:]')
EXPECTED="7f61155038897232d63b337bebc49fc8"

if [ "${ACTUAL}" != "${EXPECTED}" ] ; then
    echo "checksums differ: ${OUT_FILE}"
else
    echo "checksums match: ${OUT_FILE}"
fi

OUT_FILE="${OUT_FILE_BASE}.tbl"
ACTUAL=$(md5sum -b ${OUT_FILE} | cut -c -32 | tr '[:upper:]' '[:lower:]')
EXPECTED="0b2f3335bd7a1cac0973d16a5d397ee0"

if [ "${ACTUAL}" != "${EXPECTED}" ] ; then
    echo "checksums differ: ${OUT_FILE}"
else
    echo "checksums match: ${OUT_FILE}"
fi
