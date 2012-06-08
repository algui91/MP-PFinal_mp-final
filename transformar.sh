#!/bin/bash

trans=./datos/*.trf
ima=./datos/*.pgm

for img in $ima
do
   for i in $trans
   do
      file=`basename $img"_"$i`".png"
      echo "ejecutando... ./bin/transformar $img $i $file"
      ./bin/transformar $img $i $file
   done
done
   
