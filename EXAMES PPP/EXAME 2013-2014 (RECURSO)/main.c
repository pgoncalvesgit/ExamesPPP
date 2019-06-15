#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  ITEM_TYPE  char*


char **prof(char *nome){
    char **fim;
    char *name;
    char buffer[1024];
    int i=0;
    FILE *f1;
    fim=(char**)malloc(sizeof(char*)*50);
    f1 = fopen(nome,"r");
    while(fgets(buffer,1023,f1)){
        name=(char*)malloc(sizeof(char)*100);
        fgets(name,1023,f1);
        strtok(name,"\n");
        fgets(buffer,1023,f1);
        fgets(buffer,1023,f1);
        strtok(buffer,"\n");
        if (strcmp(buffer,"Professor Cat")==0){
            fim[i]=name;
            i++;
        }
        else{
            free(name);
        }
    }
    fclose(f1);
    f1 = fopen(nome,"r");
    while(fgets(buffer,1023,f1)){
        name=(char*)malloc(sizeof(char)*100);
        fgets(name,1023,f1);
        strtok(name,"\n");
        fgets(buffer,1023,f1);
        fgets(buffer,1023,f1);
        strtok(buffer,"\n");
        if (strcmp(buffer,"Professor Ass")==0){
            fim[i]=name;
            i++;
        }
        else{
            free(name);
        }
    }
    fclose(f1);
    f1 = fopen(nome,"r");
    while(fgets(buffer,1023,f1)){
        name=(char*)malloc(sizeof(char)*100);
        fgets(name,1023,f1);
        strtok(name,"\n");
        fgets(buffer,1023,f1);
        fgets(buffer,1023,f1);
        strtok(buffer,"\n");
        if (strcmp(buffer,"Professor Aux")==0){
            fim[i]=name;
            i++;
        }
        else{
            free(name);
        }
    }
    fclose(f1);
    fim[i]=NULL;
    return fim;
}

typedef  struct  node_type{
    ITEM_TYPE  condutor;
    struct  node_type  *next;
}QNODE_TYPE;
typedef  QNODE_TYPE  *QNODE_PTR;
typedef  struct  {
    QNODE_TYPE  *rear;
    QNODE_TYPE  *front;
}Q_TYPE;

void ultima(Q_TYPE ** semana,int dia){
    QNODE_PTR aux;
    if (semana[dia]->front!=NULL){
        if (semana[dia]->front!=semana[dia]->rear){
            aux=semana[dia]->front;
            semana[dia]->front=aux->next;
            semana[dia]->rear->next=aux;
            semana[dia]->rear=aux;
            aux->next=NULL;
        }
    }
}

void  condutores_apos_nrotacoes  (Q_TYPE*  dias[],  int  nrotacoes) {
    int i,k;
    for (;i<7;i++){
        for (;k<nrotacoes;k++){
            ultima(dias,i);
        }
        printf("%s",dias[i]->front->condutor);
    }
}





int main()
{
    int i=0;
    char **fim;
    fim = prof("teste.txt");
    while(fim[i]!=NULL){
        printf("%s\n",fim[i]);
        i++;
    }
    return 0;
}


