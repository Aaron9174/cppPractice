#!/bin/bash
if [ ! -d "./build" ]; then
    echo "Build directory not found. Creating it..."
    mkdir ./build
fi
echo "Building Registration Service..."
g++ ./src/registrationService.cpp -o ./build/registrationService.o
echo "Build success!"
exit 0