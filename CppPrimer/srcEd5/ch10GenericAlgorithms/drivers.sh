#!/bin/bash

exer10-33_fun()
{
echo "Running ${PROG}"
printf "\n"
./${PROG} exer33infile exer33outfileOne exer33outfileTwo
printf "\n"
echo "End of ${PROG}"
}

exer10-31_fun()
{
read -r -d '' VARIABLE << EOM
1 1 9 9 2 8 8 3 7 4 4 4 4 6 5
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
echo "End of ${PROG}"
}


exer10-29_fun()
{
read -r -d '' VARIABLE << EOM
1 9 2 8 3 7 4 6 5
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
echo "End of ${PROG}"
}

test_fun()
{
read -r -d '' VARIABLE << EOM
qwerty
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
echo "End of ${PROG}"
}
