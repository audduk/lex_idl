#!/bin/bash

echo !!! "1+2=3" !!!
echo "1+2" | ./calc

echo !!! 3+5*6=33 !!!
echo "3+5*6" | ./calc

echo !!! "(3+5)*6=48" !!!
echo "(3+5)*6" | ./calc

echo !!! "(4+(3+5)*6)/2=26" !!!
echo "(4+(3+5)*6)/2" | ./calc

echo !!! "r=10; 5*r=50" !!!
echo "r=10" | ./calc

echo ; echo "TEST FROM FILE"; echo
cat "./test.data" | ./calc