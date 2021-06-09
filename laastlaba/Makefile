all: build mtest

build: main.c
	gcc main.c func.c -o main

run:
	./main

mtest:
	gcc -ftest-coverage -fprofile-arcs -O0 -o test test.c func.c

	./test