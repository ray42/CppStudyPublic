#!/bin/bash

############################################################################
# Section 1.1
make clean
make ex1_1 ex1_2

printf "\n"
echo "Running ex1_1 and echo $\? to see exit status:"
./ex1_1
echo $?
printf "\n"
echo "Running ex1_2 and echo $\? to see exit status:"
./ex1_2
echo $?

############################################################################




make clean
