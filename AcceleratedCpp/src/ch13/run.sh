#!/bin/bash

############################################################################
#make clean
#PROG="ch13_2_test"
#make ${PROG}
#./${PROG}
############################################################################


############################################################################
#make clean
#PROG="ch13_3_test"
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
#
############################################################################

#make clean
#PROG="ch13_4_test"
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
#
#make clean
#PROG="ch13_5_test"
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

############################################################################

make clean
PROG="ch13_e2"
make ${PROG}
read -r -d '' VARIABLE << EOM
CorePointer 11 12 13 14 15 16 17 18
GradPointer 21 22 23 24 25 26 27 28
CoreObject 31 32 33 34 35 36 37 38
GradObject 41 42 43 44 45 46 47 48
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"





make clean
