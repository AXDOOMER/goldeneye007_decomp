#!/bin/bash

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

if [ ! -d "seq" ] ; then
    mkdir "seq"
fi

"${SBKSPLIT}" --in music.sbk -p seq/ --names music_names

for file in seq/*.seq.rz
do
    OUTPUT_FILENAME=$(echo "${file}" | sed -e 's/seq\.rz$/seq/')
    if [ "${file}" = "${OUTPUT_FILENAME}" ]; then
        echo "cannot determine what to rename file: ${file}"
        break
    fi
    GZ=$(which gzip) "${INFLATE}" "${file}" "${OUTPUT_FILENAME}"
done

for file in seq/*.seq
do
    OUT_MIDI_FILENAME=$(echo "${file}" | sed -e 's/seq$/midi/')
    OUT_PATTERN_FILENAME=$(echo "${file}" | sed -e 's/seq$/pattern/')
    if [ "${file}" = "${OUT_MIDI_FILENAME}" ]; then
        echo "cannot determine what to rename file: ${file}"
        break
    fi
    if [ "${file}" = "${OUT_PATTERN_FILENAME}" ]; then
        echo "cannot determine what to name pattern from file: ${file}"
        break
    fi
    echo "run cseq2midi on \"${file}\""
    "${CSEQ2MIDI}" --in "${file}" --out "${OUT_MIDI_FILENAME}" --pattern-file "${OUT_PATTERN_FILENAME}"
    EXIT_CODE=$?
    if [ ${EXIT_CODE} -ne 0 ]; then
        echo "cseq2midi failed with exit code ${EXIT_CODE}"
        exit ${EXIT_CODE}
    fi
done