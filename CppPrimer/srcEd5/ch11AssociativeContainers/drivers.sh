#!/bin/bash

exer11-20_fun()
{
read -r -d '' VARIABLE << EOM
q Q q Q
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
echo "End of ${PROG}"

###

read -r -d '' VARIABLE << EOM
q Q q Q
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
echo "End of ${PROG}"
}

exer11-8_fun()
{
read -r -d '' VARIABLE << EOM
q Q q Q
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
echo "End of ${PROG}"

###

read -r -d '' VARIABLE << EOM
q Q q Q
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
echo "End of ${PROG}"
}


exer11-3_fun()
{
read -r -d '' VARIABLE << EOM
q Q q Q
EOM

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
echo "End of ${PROG}"

###

read -r -d '' VARIABLE << EOM
q Q q Q
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
