#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

int main() {
    FILE *file;
    struct tm *u;
    char date_now[15];
    time_t t=time(NULL);
    u=localtime(&t);
    strftime(date_now, 10, "%d.%m.%Y",u);
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
    int key=0;
    while(key!=-1)
    {
    printf("\nMenu\n");
    printf("\t1. Find person; \n");
    printf("\t2. Dismiss; \n");
    printf("\t3. Recruit; \n");
    printf("\t4. Term of the work; \n");
    printf("\t5. On work & on vacation; \n");
    printf("\t6. BDay; \n");
    printf("\t7. DismissP; \n");
    printf("\t0. Exit; \n");
    scanf("%d", &key);
    switch (key) {
        case 0:
        {
            int h;
            h=ex(lst, file);
            fclose(file);
            key=-1;
            break;
        }
        case 1:
        {
            char a[50];
            int f;
            printf("\nWhat field is being searched: ");
            scanf("%d", &f);
            printf("\nWhat to find: ");
            scanf("%s", &a);
            int l;
            l=findFields(lst, a, f, 0);
            break;
        }
        case 2:
        {
            printf("\nDismiss\n\tEnter the full name & PassNum (Name LastName MatherName PassNum): ");
            char name[15], lastN[15], matherN[15], pass[15];
            scanf("%s %s %s %s", name, lastN, matherN, pass);
            int s;
            s=Dismiss(lst, name, lastN, matherN, pass);
            break;
        }
        case 3:
        {
            list *tmp = (list*)malloc(sizeof(list));
            printf("\nEnter\t");
            printf("1. Name, 2. LastName, 3. MatherName, 4. BDay, 5. PassNum, 6. SocialNum, 7. Education, 8. Position, 9. Salaru, 10. DateOfEmployment, 11. NoteP, 12. NoteM.");
            printf("\n");
            scanf ("%s %s %s %s %s %s %s %s %s %s %s %s", tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
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
            break;
        }
        case 4:
        {
        printf("\tEnter the name & LastName (Name LastName): ");
        char name[15], lastN[15];
        scanf("%s %s", name, lastN);
            list *tmp = lst->head;
            while (tmp) {
            if((strcmp (name, tmp->Name)==0)&& (strcmp(lastN, tmp->LastName)==0)){
            printf("\n%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
            float termD;
            termD = dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
            int termDInt=dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
            if(termD<=0){
            printf("Employee on vacation");
            }
            else {
                printf("Term of the work is %f days or %f m or %f y\n" , termD , termD/30 , termD/365);
                if(termD>=182) 
                printf("Needs a vacation %d weeks", (termDInt)*2);
            }
            }
            tmp=tmp->next;
             }
            break;
        }
        case 5:
        {
            int st;
            st =OnVacationWork(lst, date_now);
            break;
        }
        case 6:
        {
            int z;
            z=BD(lst, date_now);
        }
        case 7:
        {
            int y;
            y=DismissP(lst, date_now);
            break;
        }
        default:
        {
        key=0;
            break;
        }
    }
    }
    return 0;
}