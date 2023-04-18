#!/bin/sh

DEV=/dev/ttyS7
SPEED=9600

stty -F $DEV speed $SPEED cs8
while [ true ]; do
   cat $DEV
done
