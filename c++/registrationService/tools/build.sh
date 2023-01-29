#!/bin/bash
g++ ../src/registrationService.cpp -o ../build/registrationService.o
cp ../src/loginCredentials.txt ../build
exit 0