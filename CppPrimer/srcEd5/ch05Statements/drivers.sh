#!/bin/bash

test_fun()
{
read -r -d '' VARIABLE << EOM
qwerty
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
printf "\n"
}

exer5-23_fun()
{
read -r -d '' VARIABLE << EOM
6 2 3 4 5 6
EOM

printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
}

exer5-24_fun()
{
read -r -d '' VARIABLE << EOM
6 2 3 0 5 6
EOM

printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
}

exer5-25_fun()
{
read -r -d '' VARIABLE << EOM
6 2 3 0 y 5 6
EOM

printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
}

