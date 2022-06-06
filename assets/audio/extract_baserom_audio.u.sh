#!/bin/bash

# This is a helper script to extract the five base audio files (and nothing else) from ROM.
# The same result can be achieved by running the extract script in the root of the project.

# paths are relative to assets/audio
BASEROM_PATH="../../baserom.u.z64"
EXTRACTOR="../../tools/extractor/extractor"

if [ ! -f "${BASEROM_PATH}" ]; then
    echo "baserom not found, expected: ${BASEROM_PATH}"
    exit 1
fi

if [ ! -f "${EXTRACTOR}" ]; then
    echo "extractor not found, expected: ${EXTRACTOR}"
    exit 1
fi

"${EXTRACTOR}" "${BASEROM_PATH}" audio_filelist.csv