#!/bin/bash

BIN_DIR="./../bin/"

make FILE=$1
"$BIN_DIR"$1

#make clean
make clean-all

