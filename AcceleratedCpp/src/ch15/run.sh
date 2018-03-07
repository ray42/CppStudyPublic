#!/bin/bash

#############################################################################
#make clean
#PROG="ch15_1_test"
#make ${PROG}
#read -r -d '' VARIABLE << EOM
#U C 11 12 13 14 15 16 17 18
#G B 21 22 23 24 25 26 27 28
#G A 31 32 33 34 35 36 37 38
#EOM
#
#printf "\n"
#printf "\n"
#echo -e "${VARIABLE}" | ./${PROG}
#printf "\n"
#printf "\n"
#############################################################################

############################################################################
make clean
PROG="ch15_test_protection"
make ${PROG}
read -r -d '' VARIABLE << EOM
U C 11 12 13 14 15 16 17 18
G B 21 22 23 24 25 26 27 28
G A 31 32 33 34 35 36 37 38
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
############################################################################




make clean
