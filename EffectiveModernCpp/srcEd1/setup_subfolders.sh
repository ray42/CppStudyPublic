#!/bin/bash

# Folder to copy FRoM
FRM="ch1"
declare -a folders=(
"ch2"
"ch3"
"ch4"
"ch5"
"ch6"
"ch7"
"ch8")

for i in "${folders[@]}"
do
  mkdir $i
  cp -rf ${FRM}/* $i/
done

