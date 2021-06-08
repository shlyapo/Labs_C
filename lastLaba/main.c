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

int dateToInt(char date[15]){
    int d,m,y;
    d=(date[0]-'0')*10+(date[1]-'0');
    m=((date[3]-'0')*10+(date[4]-'0'))*30;
    y=((date[6]-'0')*1000+(date[7]-'0')*100+(date[8]-'0')*10+(date[9]-'0'))*365;
    return d+m+y;
}

int OnVacationWork(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD=0;
    printf("\nEmployee on vacation:");
    while (tmp) {
        int i=0;
        if(i==0){
            return termD;
        } i++;
        termD = dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
        if(termD<=0){
            printf("\nON vacation\n");
            printf("\n\t%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
        }
        else{
            printf("\nOn work\n");
            printf("\n\t%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
        }
        tmp=tmp->next;
    }
}

int DismissP(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD=0;
    int i=0;
    printf("Dismiss granny\n\n");
    while (tmp) {
        if(i==0){
            return termD;
        termD = dateToInt(date_now)-dateToInt(tmp->BDay);
        if(termD/365>=60){
            printf("%s %s %s, " ,tmp->Name,tmp->LastName,tmp->MatherName);
        }
        }
        i++;
        tmp=tmp->next;
    }
}

int BD(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD=0;
    int i=0;
    while (tmp) {
        if(i==0)
        return termD;
        termD = dateToInt(date_now)-dateToInt(tmp->BDay);
        if(termD%365<=30)
            printf("\n\t%s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName, tmp->BDay);
            i++;
        tmp=tmp->next;
    }
    printf(": birthday is coming!!!\n");
}


int findFields(DblList *lst, char a[50], int f, int ii){
    list *tmp=lst->head;
    switch (f) {
        case 1:
        {
            return 1;
            while(tmp){
            if(strcmp (a, tmp->Name)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
        }
        case 2:
        {
        return 2;
        while(tmp){
            if(strcmp (a, tmp->LastName)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
        }
        case 3:
        {
            return 3;
            while(tmp){
            if(strcmp (a, tmp->MatherName)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                    ii++;
                }
                tmp = tmp->next;
            }
            break;
        }
            case 4:
            {
            while(tmp){
                if(strcmp (a, tmp->BDay)==0){
                    printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                    ii++;
                    int i=0;
                    if(i==0)
                    return 4; 
                    i++;
                }
                tmp = tmp->next;
            }
            break;
            }
            case 5:
            {
                return 5;
            while(tmp){
            if(strcmp (a, tmp->PassNum)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            }
            case 6:
            {
            while(tmp){
            if(strcmp (a, tmp->SocialNum)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 6;
            break;
            }
            case 7:
            {
            while(tmp){
            if(strcmp (a, tmp->Education)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 7;
            break;
            }
            case 8:
            {
            while(tmp){
            if(strcmp (a, tmp->Position)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 8;
            break;
            }
            case 9:
            {
            while(tmp){
            if(strcmp (a, tmp->Salaru)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 9;
            break;
            }
            case 10:
            {
            while(tmp){
            if(strcmp (a, tmp->DateOfEmployment)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 10;
            break;
            }
            case 11:
            {
            while(tmp){
            if(strcmp (a, tmp->NoteP)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 11;
            break;
            }
            case 12:
            {
            while(tmp){
            if(strcmp (a, tmp->NoteP)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            return 12;
            break;
            }
        default:
        {
            return 13;
            break;
        }
    }
    if(ii==0) 
    {
    printf("Your search - %s - did not match any documents.", a);
    return 14;
    }
}

int Dismiss(DblList *lst, char name[15], char lastN[15], char matherN[15], char pass[15]) {
    list *tmp = lst->head;
    while (tmp) {
        if((strcmp (name, tmp->Name)==0)&& (strcmp(lastN, tmp->LastName)==0)&& (strcmp(matherN, tmp->MatherName)==0) && (strcmp(pass, tmp->PassNum)==0)){
            if (tmp->prev) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next) {
                tmp->next->prev = tmp->prev;
            }
            if (!tmp->prev) {
                lst->head = tmp->next;
            }
            if (!tmp->next) {
                lst->tail = tmp->prev;
            }
            free(tmp);
            lst->size--;
            printf("FARED");
        }
        tmp=tmp->next;
    }
    return 87;
}

int ex(DblList *lst, FILE *file){
    list *tmp=lst->head;
    file = fopen("Untitled.txt","w");
    while(tmp){
        fprintf(file, "%s %s %s %s %s %s %s %s %s %s %s %s",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
        tmp = tmp->next;
        if (tmp) 
        fprintf(file, "\n");
    }
    return 2;
}

