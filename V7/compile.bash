#!/bin/bash

# Compile CDo
gcc -c main.c -o main.o
gcc -c echo.c -o echo.o
gcc -c read.c -o read.o
gcc -c ls.c -o ls.o
gcc -c clear.c -o clear.o
gcc -c exit.c -o exit.o
gcc -c host.c -o host.o # Add this line to compile host.c

# Link object files to create the executable
gcc main.o echo.o read.o ls.o clear.o exit.o host.o -o CDo

# Optionally, you can remove the intermediate object files if you want
# rm *.o
