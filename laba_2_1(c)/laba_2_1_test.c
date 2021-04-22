#include "laba_2_1.h"
#include <assert.h>

void test()
{
assert(Decision(230000, 160000, 360, 20)==52000);
assert(Decision(402000, 301000, 320, 40)==88200);
assert(Decision(780000, 615000, 200, 60)==153000);
}

#undef main

int main() 
{
    test();
}