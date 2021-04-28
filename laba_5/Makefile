all: build mtest

build: main.cpp
	g++ -o main main.cpp -lm 
run:
	./main
mtest:
	g++ -o test -Dmain=_main main.cpp test.cpp
	./test
valgrind:
	valgrind --leak-check=full ./main
linter:
	cppcheck -q --enable=all --inconclusive main.cpp