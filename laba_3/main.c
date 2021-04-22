#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Pr(float **matrNew, int n)
{ 
    int i;
      for(i = 0; i < n; i++)
    {
        if(fabs(matrNew[i][i]) < 0.0001)
            return 0;
    }
            return 1;
}

void Add(float ** matr, int size, int x, int y, float n)
{
    int i;
    for(i = 0; i < size; i++)
        matr[x][i] += matr[y][i] * n;
}

void Inc(float ** matr, int size, int x, float n)
{
    int i;
    for(i = 0; i < size; i++)
        matr[x][i] *= n;
}

void printMatrix(float ** matrix, int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        printf("%f ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    printf("%s", "Введите n: ");
    int n, i, j;
    scanf("%d", &n);
    printf("%s\n", "Введите матрицу nxn:");
    float ** matr = calloc(n, sizeof(float *));
    float ** matrNew = calloc(n, sizeof(float *));
    if(matr == NULL || matrNew == NULL)
    {
        exit(2);
    }
    for(i = 0; i < n; i++)
    {
        matr[i] = calloc(n, sizeof(float));
        matrNew[i] = calloc(n, sizeof(float));
        if(matr[i] == NULL || matrNew[i] == NULL)
        {
           exit(2);
        }
        for(j = 0; j < n; j++)
        {
            scanf("%f", &matr[i][j]);
            if(i == j)
            {
            matrNew[i][j] = 1;
            }
        }     
    }
    if(Pr(matr, n)==0)
    exit(0);
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            float x = matr[j][i] / matr[i][i] * (-1);
            Add(matr, n, j, i, x);
            Add(matrNew, n, j, i, x);
        }
    }
    if(Pr(matrNew, n)==0)
    exit(0);
    for(i = 0; i < n; i++)
    {
        float x = 1 / matr[i][i];
        Inc(matr, n, i, x);
        Inc(matrNew, n, i, x);
    }
    for(i = n - 1; i > 0; i--)
    {
        for(j = i - 1; j >= 0; j--)
        {
            float x =  matr[j][i] / matr[i][i]  * (-1);
            Add(matr, n, j, i, x);
            Add(matrNew, n, j, i, x);
        }   
    }
     printMatrix(matrNew, n);
     int k;
     for(k=0; k<n; k++)
     free(matr[k]);
     free(matr);
      for(k=0; k<n; k++)
     free(matrNew[k]);
     free(matrNew);
    return 0;
}
