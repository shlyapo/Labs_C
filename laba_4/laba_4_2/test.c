#include <assert.h>
#include "main.h"

int test()
{  
    assert(Check('a')==0);
    assert(Check('C')==1);
    assert(Check('Z')==1);
}
 #undef main

 int main()
 {
     test();
 }