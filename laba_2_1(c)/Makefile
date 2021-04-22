all: build mtest

build: laba_2_1.c
	gcc laba_2_1.c -o main -lm -std=c89
run:
	./main
mtest:
	gcc -o test -Dmain=_main laba_2_1.c laba_2_1_test.c -lm
	./test
valgrind:
	valgrind --leak-check=full ./main
linter:
	cppcheck -q --enable=all --inconclusive laba_2_1.c