#!/bin/bash

exer7-1_fun()
{
# ISBN #unit_sold price
read -r -d '' VARIABLE << EOM
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"

# Output is:
# ISBN, #unit_sold totalRevenue avgPrice
# 0-201-78345-X 5 110 22
}

exer7-3_fun()
{
# ISBN #unit_sold price
read -r -d '' VARIABLE << EOM
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"

# Output is:
# ISBN, #unit_sold totalRevenue avgPrice
# 0-201-78345-X 5 110 22
}

exer7-7_fun()
{
# ISBN #unit_sold price
read -r -d '' VARIABLE << EOM
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"

# Output is:
# ISBN, #unit_sold totalRevenue avgPrice
# 0-201-78345-X 5 110 22
}

exer7-11_fun()
{
# ISBN #unit_sold price
read -r -d '' VARIABLE << EOM
0-201-78345-X 3 20.00
EOM

printf "\n"
printf "\n"
echo -e "${VARIABLE}" | ./${PROG}
printf "\n"
printf "\n"

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




