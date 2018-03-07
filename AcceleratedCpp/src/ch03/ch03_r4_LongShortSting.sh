#!/bin/bash
BIN_DIR="./../bin/"
PROG="ch03_e4_LongShortString"
EXE="${BIN_DIR}/${PROG}"

# Make the program
make FILE=${PROG}

# Run the program
${EXE} <<< "q"
echo ""
${EXE} <<< "q q"
echo ""
${EXE} <<< "q w"
echo ""
${EXE} <<< "w q"
echo ""
${EXE} <<< "ll q w"
echo ""
${EXE} <<< "w q ll"
echo ""
${EXE} <<< "q w pp q w ll"
echo ""

make clean-all
