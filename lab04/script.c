#! /bin/bash

# si número de parámetros distinto 1
if [ $# ­ne 1 ]; 
then
echo "El número de parámetros debe de igual a 1"
ayuda
exit 1
fi
ESTA_CONECTADO=`who | grep $1`
if [ ­z "$ESTA_CONECTADO" ]; 
then
echo "NO"
else
echo "SI"
fi
