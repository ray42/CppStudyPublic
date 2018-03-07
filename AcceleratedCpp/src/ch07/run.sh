#!/bin/bash

##############################################
#PROG="ch07_p2_countingwords"
#make ${PROG}
#./${PROG} <<< "qqq qqq qqq qqq q qq q qq "

###############################################
#PROG="ch07_p3_reftable"
#make ${PROG}
#echo -e "Hello\nworld" | ./${PROG} 
#
##############################################
PROG="ch07_p4_sentences"
read -r -d '' VARIABLE << EOM
<noun> cat
<noun> dog
<noun> table
<noun-phrase> <noun>
<noun-phrase> <adjective> <noun-phrase>
<adjective> large
<adjective> brown
<adjective> absurd
<verb> jumps
<verb> sits
<location> on the stairs
<location> under the sky
<location> wherever it wants
<sentence> the <noun-phrase> <verb> <location>
EOM

make ${PROG}
echo -e "${VARIABLE}" | ./${PROG}

#./${PROG}

echo ""
echo ""


make clean-all
