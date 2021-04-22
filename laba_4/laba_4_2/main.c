#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Check(char x)
{
 if (x>='A'&&x<='Z')    
 return 1;
 else  
 return 0;
}

int main()
{
    int n=1;
FILE *fp;
  {
  if ((fp = fopen("C:\\Пользователи\\sheks\\source\\repos\\второй семестр\\laba_4\\laba_4_2\\t.txt","r")) == NULL)
  {
    printf("Не удалось открыть файл");
    getchar();
  }
  else 
  n=0;
  }
  char s;
  int length;
  while ((fscanf(fp, "%c",&s)!=EOF))
  length++;
  char* mas = (char*)malloc(length* sizeof(char));
  int i;
  for(i=0; i<length; i++)
  fscanf(fp, "%c",&mas[i]);
  fclose (fp);
  FILE *ffp;
  while(n==0)
  {
  if ((ffp = fopen("C:\\Пользователи\\sheks\\source\\repos\\второй семестр\\laba_4\\laba_4_2\\t.txt","w")) == NULL)
  {
    printf("Не удалось открыть файл");
    getchar();
  }
  else
  n++;
  }
   for (i=0; i<length; i++)
   {
   if(i==0||(i!=0&&mas[i-1]=='.'))
   {
     if(Check(mas[i])==0)
     fprintf(ffp, "%c", toupper(mas[i]));
   }
   else if(mas[i]==' ')
   {
   fprintf(ffp, "%c", mas[i]);
   if(mas[i+1]==' ')
    { 
      while(mas[i+1]==' ')
      i++;
    }
   }
   else 
   fprintf(ffp, "%c", mas[i]);
   }
   fclose(ffp);
   free(mas[i]);
   return 0;
}