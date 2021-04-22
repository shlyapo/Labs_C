#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void test()
{
float ** matrix = calloc(2, sizeof(float *));
int i;
for(i=0; i<2; i++)
matrix[i] = calloc(2, sizeof(float));
matrix[0][0]=0.0;
matrix[0][1]=3.0;
matrix[1][0]=4.0;
matrix[1][1]=6.0;
assert(Pr(matrix, 2)==0);
matrix[1][0]=2.0;
matrix[1][1]=0.0;
assert(Pr(matrix, 2)==0);
matrix[0][0]=0.5;
matrix[1][1]=0.5;
assert(Pr(matrix, 2)==1);
}

#undef main

int main()
{
    test();
}