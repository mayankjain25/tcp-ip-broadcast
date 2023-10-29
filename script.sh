#!/bin/bash

c=1

while [[ c -ne 10 ]];
do
    ./client
    (( c++ ))
done
