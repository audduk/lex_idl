#!/bin/bash

export UniName="testServer"
export UniAddr="127.0.0.1"
export UniPort="3102"
export UniCode="arm_gv"
export UniDebug=3

env | grep Uni

LD_LIBRARY_PATH=$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
export PATH=$PATH

env | grep PATH

./testServer
