#!/bin/bash

############################################################################
# Section 1.2
make clean
PROG="ex1_4"
make ${PROG}

read -r -d '' VARIABLE << EOM
6 7
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
############################################################################
make clean
