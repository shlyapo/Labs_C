all: build mtest

build: main.c
	gcc main.c -o main -lm -std=c89
run:
	./main
mtest:
   gcc -ftest-coverage -fprofile-arcs -O0 -o test test.c main.c

	./test
