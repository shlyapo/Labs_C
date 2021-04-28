#include <assert.h>
#include "main.h"

int test() 
{
    int mas[5]={1,5,2,3,7};
    int mas2[6]={5,9,2,7,5,4};
    int mas3[2]={7,4};
    int *mas11=InsertionSort(mas, 5);
    int *mas22=InsertionSort(mas2, 6);
    int *mas33=InsertionSort(mas3, 2);
    assert(mas11[2]==3);
    assert(mas22[3]==5);
    assert(mas33[0]==4);
} 

#undef main

int main() 
{
    test();
}