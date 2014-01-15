#!/bin/bash

export UniName="testClient"
export UniAddr="127.0.0.1"
export UniPort="3102"
export UniCode="arm_gv"
export UniDebug=3

env | grep Uni

./testClient
