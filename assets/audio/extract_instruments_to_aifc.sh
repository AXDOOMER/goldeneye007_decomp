#!/bin/bash

# This is a helper script to extract .aifc files from the isntruments .tbl.
# These will be placed in the assets/audio/aifc_instruments folder.
# The resulting files can be used to rebuild a matching ROM.

# set paths for commands. These are relative to the assets/audio folder.
TBl2AIFC="../../tools/gaudio/bin/tbl2aifc"

OUT_DIR="aifc_instruments/"

if [ ! -f "${TBl2AIFC}" ] ; then
    echo "missing tbl2aifc. make tools/gaudio first"
    exit 1
fi

# create output directories.
if [ ! -d "${OUT_DIR}" ] ; then
    mkdir "${OUT_DIR}"
fi

# Extract .inst file from input .ctl and .tbl.
# Extract all instruments to .aifc files from input .tbl.
# Don't use any filenames.
# Write the output to "${OUT_DIR}".
# When the .inst file is written, the sort order of each entity as read from
# the input file is included as a property. This is used by gic
# to rebuild a matching rom.
"${TBl2AIFC}" --ctl instruments.ctl --tbl instruments.tbl --inst="${OUT_DIR}"instruments.inst --dir="${OUT_DIR}"

