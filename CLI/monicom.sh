#!/bin/sh

DEV=/dev/$1

if [ "$#" -eq 2 ] ; then
   SPEED=$2
else
   SPEED=9600
fi

sudo chmod 777 $DEV

stty -F $DEV speed $SPEED cs8
while [ true ]; do
   cat $DEV
done
