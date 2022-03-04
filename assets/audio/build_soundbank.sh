#!/bin/bash

# set paths for commands. These are relative to the assets/audio folder.
MIDI2CSEQ="../../tools/gaudio/bin/midi2cseq"
SBC_SH="../../tools/gaudio/shell/sbc.sh"
OUT_FILE="music.sbk"
MUSIC_NAMES="music_names"
GZ=$(which gzip)

if [ ! -f "${MIDI2CSEQ}" ] ; then
    echo "missing midi2cseq. make tools/gaudio first"
    exit 1
fi

if [ ! -f "${SBC_SH}" ] ; then
    echo "missing sbc shell script from gaudio"
    exit 1
fi

if [ ! -f "${GZ}" ] ; then
    echo "missing system gzip binary (gzip from decomp will not compress .seq to matching binary)"
    exit 1
fi

if [ ! -f "${MUSIC_NAMES}" ] ; then
    echo "missing music names file, expecting: ${MUSIC_NAMES}"
    exit 1
fi

if [ ! -d "seq" ] ; then
    mkdir "seq"
fi

# For each MIDI file, convert to cseq. This will use a .pattern file if it exists.
for file in midi/*.midi
do
    PATTERN_FILENAME=$(echo  "${file}" | sed -e 's/midi$/pattern/')
    OUT_SEQ_FILENAME=$(basename -- "${file}" | sed -e 's/midi$/seq/')
    if [ "${file}" = "${OUT_SEQ_FILENAME}" ]; then
        echo "cannot determine what to rename file: ${file}"
        break
    fi
    if [ "${file}" = "${PATTERN_FILENAME}" ]; then
        echo "cannot determine what to name pattern from file: ${file}"
        break
    fi
    echo "run midi2cseq on \"${file}\""

    # some tracks don't have patterns, so only specify the pattern file if it exists.
    PATTERN_ARG=
    if [ -f "${PATTERN_FILENAME}" ] ; then
        # opt + arg are quoted, need explicit equals sign.
        PATTERN_ARG="--pattern-file=${PATTERN_FILENAME}"
    fi

    "${MIDI2CSEQ}" --in "${file}" "${PATTERN_ARG}" --out "seq/${OUT_SEQ_FILENAME}"
    EXIT_CODE=$?
    if [ ${EXIT_CODE} -ne 0 ]; then
        echo "midi2cseq failed with exit code ${EXIT_CODE}"
        exit ${EXIT_CODE}
    fi
done

# Use the sbc shell script to compile the soundbank.
# This requires system gzip (decomp gzip files for some reason)
# A list of filenames is needed to explain what files go into the soundbank
# The '-i' option is the path to the directory containing the sound files.
"${SBC_SH}" -z "${GZ}" -n "${MUSIC_NAMES}" -i seq -o "${OUT_FILE}"

# Print a status indicator if this matches the original ROM file or not.
ACTUAL=$(md5sum -b "${OUT_FILE}" | cut -c -32 | tr '[:upper:]' '[:lower:]')
EXPECTED="395b075324e91c6f95e3ee0fbc172928"

if [ "${ACTUAL}" != "${EXPECTED}" ] ; then
    echo "checksums differ: ${OUT_FILE}"
else
    echo "checksums match: ${OUT_FILE}"
fi