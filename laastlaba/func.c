#include "main.h"

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