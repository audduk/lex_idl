#!/bin/bash

FILENAME=$1

[ "x$FILENAME" = "x" ] && FILENAME="./test.data"

#cat "./test.data"
echo
#echo
#cat "./test.data" | ./module
./tsm -t client $FILENAME