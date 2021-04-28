#include <assert.h>
#include "main.h"

int test() 
{
    Node *Tree2=0;
    Node *Tree3=0;
    int mas[5]={1,5,2,3,7};
    int mas2[6]={5,9,2,7,5,4};
    for(int i=0; i<5; i++)
     Add(mas[i], Tree2);
     for(int i=0; i<6; i++)
     Add(mas2[i], Tree3);
    assert(Check(Tree2)==0);
    assert(Check(Tree3)==1);
    Delete(Tree2);
    Delete(Tree3);
} 

#undef main

int main() 
{
    test();
}