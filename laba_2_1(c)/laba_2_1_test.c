#include "laba_2_1.h"
#include <assert.h>

void test()
{
assert(Parameters(50, 50, 50, 50)==4);
assert(Parameters(50, 50, 50, 60)==5);
assert(Parameters(50, 50, 50, 110)==6);
}

#undef main

int main() 
{
    test();
}

