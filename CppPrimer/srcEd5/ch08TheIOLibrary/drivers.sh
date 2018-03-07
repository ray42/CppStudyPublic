#!/bin/bash

exer8-11_fun()
{
read -r -d '' VARIABLE << EOM
morgan 2015552368 8625550123
drew 9735550130
lee 6095550132 2015550175 8005550000
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
echo "End of ${PROG}"
}

exer8-1_fun()
{
read -r -d '' VARIABLE << EOM
this is a word
another word.
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
echo "End of ${PROG}"
}


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




