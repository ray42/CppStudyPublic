#!/bin/bash

PROG="$1"
FUNC="${PROG}_fun"

exer3-2_fun()
{
read -r -d '' VARIABLE << EOM
q 
   q w 
q w e r
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} bla bla
printf "\n"
printf "\n"

read -r -d '' VARIABLE << EOM
q w e r
EOM

echo -e "${VARIABLE}" | ./${PROG}
}

exer3-17_fun()
{
read -r -d '' VARIABLE << EOM
Qw we rt wr yy e w rtt e  r r e r rt r tw e r wer ew   h gf  dfg dg fg f g
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
}

exer3-20_fun()
{
read -r -d '' VARIABLE << EOM
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
}


exer3-24_fun()
{
read -r -d '' VARIABLE << EOM
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
}


#OUTPUT="$(type -t ${FUNC})"
if [ "$(type -t ${FUNC})" = "function" ]
then
  # We run the function
  make clean > /dev/null && \
  ./genmake.sh && \
  make ${PROG} && \
  ${FUNC}
else
  # There is no function for this program, so we run the program
  # directly.
  make clean > /dev/null && \
  ./genmake.sh && \
  make ${PROG} && \
  ./${PROG}
fi
