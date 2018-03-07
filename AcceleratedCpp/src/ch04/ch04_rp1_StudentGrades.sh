#!/bin/bash
PROG="ch04_p1_StudentGrades"

# Make the program
make ${PROG}

# Run the program
./${PROG} <<< "q 1 2 4 5 6 7"

make clean-all
