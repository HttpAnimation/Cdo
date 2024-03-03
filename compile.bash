#!/bin/bash

# Function to compile CDo
compile_CDo() {
    gcc -c main.c -o main.o
    gcc -c echo.c -o echo.o
    gcc -c read.c -o read.o
    gcc -c ls.c -o ls.o
    gcc -c clear.c -o clear.o
    gcc -c exit.c -o exit.o
    gcc -c host.c -o host.o
    gcc -c help.c -o help.o
    gcc -c mkdir.c -o mkdir.o
    gcc -c rm.c -o rm.o
    gcc -c ping.c -o ping.o
    gcc -c v.c -o v.o
    # Link object files to create the executable
    gcc main.o v.o ping.o echo.o read.o ls.o clear.o exit.o host.o help.o mkdir.o rm.o -o Cdo
}

# Check if the -c flag is provided
if [[ $1 == "-c" ]]; then
    compile_CDo
else
    echo "Usage: bash compile.bash -c"
    echo "The -c flag is required to compile the CDo program"
fi
