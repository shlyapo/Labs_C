#include <assert.h>
#include "main.h"

int test()
{  
    assert(GetS(10, 3)==3);
    assert(GetS(21, 2)==5);
    assert(GetS(13, 6)==2);
}
 #undef main

 int main()
 {
     test();
 }