#!/bin/bash
BIN_DIR="./../bin/"
PROG="ch03_e3_DistinctWords"
EXE="${BIN_DIR}/${PROG}"

# Make the program
make FILE=${PROG}

# Run the program
${EXE} <<< "q"
${EXE} <<< "q q"
${EXE} <<< "q q w"
${EXE} <<< "w q q"
${EXE} <<< "q w q"
${EXE} <<< "q w q w"

make clean-all
