#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
    char Name[15], LastName[15], MatherName[15], BDay[11], PassNum[15], SocialNum[15], Education[30], Position[30],  DateOfEmployment[15], Salaru[10], NoteP[50], NoteM[50];
    struct list *next, *prev;
} list;

typedef struct DblList {
    size_t size;
    list *head;
    list*tail;
} DblList;

int ex(DblList *lst, FILE *file);
int findFields(DblList *lst, char a[50], int f, int ii);
int Dismiss(DblList *lst, char name[15], char lastN[15], char matherN[15], char pass[15]);
int OnVacationWork(DblList *lst, char date_now[15]);
int DismissP(DblList *lst, char date_now[15]);
int BD(DblList *lst, char date_now[15]);
int dateToInt(char date[15]);