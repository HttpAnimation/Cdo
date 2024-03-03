gcc -c main.c -o main.o
gcc -c echo.c -o echo.o
gcc -c read.c -o read.o
gcc -c ls.c -o ls.o
gcc -c clear.c -o clear.o
gcc -c exit.c -o exit.o

gcc main.o echo.o read.o ls.o clear.o exit.o -o CDo
