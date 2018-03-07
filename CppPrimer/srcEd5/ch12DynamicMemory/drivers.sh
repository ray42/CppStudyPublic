#!/bin/bash
exer12-30_fun()
{
read -r -d '' VARIABLE << EOM
A
B
C
D
E
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

echo "Running ${PROG}"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG} foo bar
printf "\n"
echo "End of ${PROG}"
}
