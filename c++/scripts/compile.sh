#! /bin/bash

# Path argument must be the first specified argument
path="$1"
output="a.out"

shift # Shifts away one argument by default

while getopts o: flag
do
    case "${flag}" in
        o) output=${OPTARG};;
    esac
done
echo "output: $output";
g++ $path -o $output;
