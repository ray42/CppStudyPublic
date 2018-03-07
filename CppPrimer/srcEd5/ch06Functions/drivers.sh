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

exer6-4_fun()
{
read -r -d '' VARIABLE << EOM
0 1 2 3 11 12 13 y 14 y 15 n
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"
}

exer6-25_fun()
{
./${PROG} 1 2 3 4 5 6
}



