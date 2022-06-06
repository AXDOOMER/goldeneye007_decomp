#!/bin/bash

# This is a helper script to extract MIDI files from the .sbk.
# These will be placed in the assets/audio/midi folder.
# The resulting files can be used to rebuild a matching ROM.

# set paths for commands. These are relative to the assets/audio folder.
SBKSPLIT="../../tools/gaudio/bin/sbksplit"
CSEQ2MIDI="../../tools/gaudio/bin/cseq2midi"
INFLATE="../../tools/1172inflate.sh"

if [ ! -f "${SBKSPLIT}" ] ; then
    echo "missing sbksplit. make tools/gaudio first"
    exit 1
fi

if [ ! -f "${CSEQ2MIDI}" ] ; then
    echo "missing cseq2midi. make tools/gaudio first"
    exit 1
fi

if [ ! -f "${INFLATE}" ] ; then
    echo "missing inflate script: ${INFLATE}"
    exit 1
fi

# create output directories.
if [ ! -d "seqrz" ] ; then
    mkdir "seqrz"
fi
if [ ! -d "seq" ] ; then
    mkdir "seq"
fi
if [ ! -d "midi" ] ; then
    mkdir "midi"
fi

# Split soundbank into individual seq.rz files.
# Output to assets/audio/seqrz
# Use the `music_names` file in the assets/audio to name each music track.
"${SBKSPLIT}" --in music.sbk -p seqrz/ --names music_names

# Foreach each .seq.rz file, 1172 inflate it to assets/audio/seq/
for file in seqrz/*.seq.rz
do
    OUTPUT_FILENAME=$(basename -- "${file}" | sed -e 's/seq\.rz$/seq/')
    if [ "${file}" = "${OUTPUT_FILENAME}" ]; then
        echo "cannot determine what to rename file: ${file}"
        break
    fi
    GZ=$(which gzip) "${INFLATE}" "${file}" "seq/${OUTPUT_FILENAME}"
done

# Foreach each .seq, convert to midi.
# Place output in assets/audio/midi
# Save pattern markers with same file name but .pattern extension in the same folder.
# If conversion fails with fatal error print exit code.
for file in seq/*.seq
do
    OUT_MIDI_FILENAME=$(basename -- "${file}" | sed -e 's/seq$/midi/')
    OUT_PATTERN_FILENAME=$(basename --  "${file}" | sed -e 's/seq$/pattern/')
    if [ "${file}" = "${OUT_MIDI_FILENAME}" ]; then
        echo "cannot determine what to rename file: ${file}"
        break
    fi
    if [ "${file}" = "${OUT_PATTERN_FILENAME}" ]; then
        echo "cannot determine what to name pattern from file: ${file}"
        break
    fi
    echo "run cseq2midi on \"${file}\""
    "${CSEQ2MIDI}" --in "${file}" --export-invalid-loop --out "midi/${OUT_MIDI_FILENAME}" --pattern-file "midi/${OUT_PATTERN_FILENAME}"
    EXIT_CODE=$?
    if [ ${EXIT_CODE} -ne 0 ]; then
        echo "cseq2midi failed with exit code ${EXIT_CODE}"
        exit ${EXIT_CODE}
    fi
done
