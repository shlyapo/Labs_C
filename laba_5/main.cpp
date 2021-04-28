 #include <iostream>
 #include <algorithm>
 #include "list.h"
 #include "main.h"
 
using namespace std;
 
 int *InsertionSort(int data[], int lenD)
{
  int key = 0;
  int i = 0;
  for(int j = 1; j<lenD; j++)
  {
    key = data[j];
    i = j-1;
    while(i>=0 && data[i]>key)
    {
      data[i+1] = data[i];
      i = i-1;
      data[i+1]=key;
    }
  }
  return data;
}

void ListGet(int q1[], int q2[], int ends1, int ends2)
{
    List L;
 int i=0, j=0, count=0;
 while(ends1>0&&ends2>0)
 { 
     int counter;
     if(q1[i]<q2[j])
     {
     L.AddTail(q1[i]);
     i++;
     ends1--;
     }
     else if(q1[i]==q2[j])
     {
        L.AddTail(q1[i]);
        L.AddTail(q2[j]);
        i++;
        j++;
        ends1--;
        ends2--;
     }
     else
     {
     L.AddTail(q2[j]);
     j++;
     ends2--;
     }
 }
 if(ends1==0)
 {
     while(ends2>-1)
     {
          L.AddTail(q2[j]);
          j++;
         ends2--;
     }
 }
 else 
 {
     while(ends1>-1)
     {
        
          L.AddTail(q1[i]);
     i++;
     ends1--;
     }
 }
 L.Print();
 L.DelAll();
}

 int main()
 {
 setlocale(LC_ALL,"rus");
 int ends1 = 0, ends2=0;
 int mas1[]={1, 3, 5, 7, 2, 8, 10};
 int mas2[]={ 5, 8, 15, 16, 8};
ends1=sizeof(mas1)/sizeof(int);
ends2=sizeof(mas2)/sizeof(int);
int *mas3=InsertionSort(mas1, ends1);
int *mas4=InsertionSort(mas2, ends2);
 ListGet(mas3, mas4, ends1, ends2);
 return 0;
 }