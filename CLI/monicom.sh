#!/bin/sh

SPEED=9600

stty -F /dev/ttyACM0 speed $SPEED cs8
while [ true ]; do
   cat /dev/ttyACM0
done