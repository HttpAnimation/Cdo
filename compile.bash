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
    # Remove source and object files
    rm *.c *.h *.o *.md
    echo "CDo compiled successfully and source files removed."
elif [[ $# -eq 0 ]]; then
    compile_CDo
    echo "CDo compiled successfully. To remove source and object files, use 'bash compile.bash -c'"
else
    echo "Usage: bash compile.bash [-c]"
    echo "Options:"
    echo "  -c  Compile the CDo program and remove source and object files"
fi
