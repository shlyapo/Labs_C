#include <assert.h>
#include "main.h"

int test() 
{
    FILE *file;
    FILE *ff;
    char name[15]={"K"};
    char lastN[15]={"K"}; 
    char matherN[15]={"W"};
    char pass[15]={"123456"};
    if ((file = fopen("Untitled.txt","r+")) == NULL){
        printf("Error! opening file");
    }
    DblList *lst = (DblList*) malloc(sizeof(DblList));
    lst->size = 0;
    lst->head = lst->tail = NULL;
    while(!feof(file)){
        list *tmp = (list*)malloc(sizeof(list));
    if(tmp==NULL) 
    printf("ERROR. x00911");
    fscanf (file, "%s%s%s%s%s%s%s%s%s%s%s%s", tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
    tmp->next = NULL;
    tmp->prev = lst->tail;
    if (lst->tail) {
        lst->tail->next = tmp;
    }
    lst->tail = tmp;
    
    if (lst->head == NULL) {
           lst->head = tmp;
       }
       lst->size++;
    }
     char a[]={"P"};
     char a1[]={"p"};
     char a2[]={"p"};
     char a3[]={"12.03.1999"};
     char a4[]={"1234"};
     char a5[]={"125"};
     char a6[]={"BSU"};
     char a7[]={"Boss"};
     char a8[]={"200"};
     char a9[]={"31.04.1999"};
     char a10[]={"10"};
     char a11[]={"0"};
     char a12[]={"655656"};
     char a13[]={"77"};
     DblList *l = (DblList*) malloc(sizeof(DblList));
    l->size = 0;
    l->head = l->tail = NULL;
    assert(ex(lst, file)==2);
    assert(Dismiss(lst, name, lastN, matherN, pass)==87);
    assert(findFields(lst, a, 1, 0)==1);
    assert(findFields(lst, a1, 2, 0 )==2);
    assert(findFields(lst, a2, 3, 0)==3);
    assert(findFields(lst, a3, 4, 0)==4);
    assert(findFields(lst, a4, 5, 0)==5);
    assert(findFields(lst, a5, 6, 0)==6);
    assert(findFields(lst, a6, 7, 0)==7);
    assert(findFields(lst, a7, 8, 0)==8);
    assert(findFields(lst, a8, 9, 0)==9);
    assert(findFields(lst, a9, 10, 0)==10);
    assert(findFields(lst, a10, 11, 0)==11);
    assert(findFields(lst, a11, 12, 0)==12);
    assert(findFields(lst, a12, 111, 0)==13);
    assert(findFields(lst, a13, 4, 0)==14);
    assert(BD(lst, a9)==0);
    assert(DismissP(lst, a9)==0);
    assert(OnVacationWork(lst, a9)==0);
    assert(dateToInt(a9)==729786);
} 

#undef main

int main() 
{
    test();
    return 0;
}