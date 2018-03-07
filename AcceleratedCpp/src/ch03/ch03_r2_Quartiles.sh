#!/bin/bash
BIN_DIR="./../bin/"
PROG="ch03_e2_Quartiles"
EXE="${BIN_DIR}/${PROG}"

# Make the program
make FILE=${PROG}

# Run the program
${EXE} <<< "1 2 3 4 5 6 7 8 9 10 11 12"
${EXE} <<< "1 2 3 4 5 6 7 8 9 10"
${EXE} <<< "1 2 3 4 5 6 7 8 9 10 11"
${EXE} <<< "1 2 3 4 5 6 7 8 9"

make clean-all
