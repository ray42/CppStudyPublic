#!/bin/bash

make clean
PROG="ex1_20"
make ${PROG}

read -r -d '' VARIABLE << EOM
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
############################################################################
make clean
