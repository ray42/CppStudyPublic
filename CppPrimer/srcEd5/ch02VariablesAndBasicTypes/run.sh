#!/bin/bash

PROG="$1"
FUNC="${PROG}_fun"

sales_data_test_fun()
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
