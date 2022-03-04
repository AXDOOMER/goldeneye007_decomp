#!/bin/bash

# This is a helper script to extract .aifc files from the sfx .tbl.
# These will be placed in the assets/audio/aifc_sfx folder.
# The resulting files can be used to rebuild a matching ROM.

# set paths for commands. These are relative to the assets/audio folder.
TBl2AIFC="../../tools/gaudio/bin/tbl2aifc"

OUT_DIR="aifc_sfx/"

if [ ! -f "${TBl2AIFC}" ] ; then
    echo "missing tbl2aifc. make tools/gaudio first"
    exit 1
fi

# create output directories.
if [ ! -d "${OUT_DIR}" ] ; then
    mkdir "${OUT_DIR}"
fi

# Extract .inst file from input .ctl and .tbl.
# Extract all sfx to .aifc files from input .tbl.
# Use the "sfx_names" file to determine filenames.
# Write the output to "${OUT_DIR}".
# When the .inst file is written, the sort order of each entity as read from
# the input file is included as a property. This is used by gic
# to rebuild a matching rom.
"${TBl2AIFC}" --ctl sfx.ctl --tbl sfx.tbl --names=sfx_names --inst="${OUT_DIR}"sfx.inst --dir="${OUT_DIR}"

