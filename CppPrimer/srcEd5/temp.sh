#!/bin/bash

#declare -a folders=("ch05Statements"
#"ch06Functions"
#"ch07Classes"
#"ch08TheIOLibrary"
#"ch09SequentialContainers"
#"ch10GenericAlgorithms"
#"ch11AssociativeContainers"
#"ch12DynamicMemory"
#"ch13CopyControl"
#"ch14OverloadedOperationsAndConversions"
#"ch15ObjectOrientatedProgramming"
#"ch16TemplatesAndGenericProgramming"
#"ch17SpecializedLibraryFacilities"
#"ch18ToolsForLargePrograms"
#"ch19SpecializedToolsAndTechniques")
#
declare -a folders=(
"ch09SequentialContainers"
"ch10GenericAlgorithms"
"ch11AssociativeContainers"
"ch12DynamicMemory"
"ch13CopyControl"
"ch14OverloadedOperationsAndConversions"
"ch15ObjectOrientatedProgramming"
"ch16TemplatesAndGenericProgramming"
"ch17SpecializedLibraryFacilities"
"ch18ToolsForLargePrograms"
"ch19SpecializedToolsAndTechniques")

for i in "${folders[@]}"
do
#  rm -rf $i/*
  cp ch08TheIOLibrary/drivers.sh $i/
#  cp ch04Expressions/genmake.sh $i/
#  cp ch04Expressions/run.sh $i/
#  cp ch04Expressions/test.cpp $i/
done

