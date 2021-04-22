#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GetS(int n, int b)
{
    int length = 0;
    while(n > 0)
    {
        n /= b;
        length++;
    }
    return length;
}

char* ItoB(int n, int b)
{
    int length=GetS(n, b);
    char * s = calloc(length, sizeof(char));
    if(s == NULL)
        exit(2);
    while(n > 0)
    {
        char c;
        int temp;
        temp = n % b;
        if(temp >=10)
        {
           temp-=10;
           c = 'A' + temp;  
        }
        else
            c = '0' + temp;
        s[length] = c;
        n /= b;
        length++;
    }
    char temp;
    int j;
    for(j = 0; j < length / 2; j++)
    {
        temp = s[length - j - 1];
        s[length - j - 1] = s[j];
        s[j] = temp;
    }
    return s;
}

int main()
{
    printf("%s","Введите число n и основание системы счисления b:");
    int n, b, length;
    scanf("%d %d", &n, &b);
    if(b > 37)
        exit(0);
    char* s=ItoB(n, b);
    printf("%s\n", s);
    while(s!=NULL)
    free(s);
    return 0;
}