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

exer4-22_fun()
{
echo -e "100" | ./${PROG} foo bar
echo -e "91" | ./${PROG} foo bar
echo -e "90" | ./${PROG} foo bar
echo -e "76" | ./${PROG} foo bar
echo -e "75" | ./${PROG} foo bar
echo -e "60" | ./${PROG} foo bar
echo -e "59" | ./${PROG} foo bar
echo -e "0" | ./${PROG} foo bar
}



