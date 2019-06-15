#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int mes, dia, ano;
}Data;
typedef struct aluno{
    int num;
    char *nome;
    Data *nasicimento;
} ITEM_TYPE;
typedef struct lnode *List;
typedef struct lnode {
    ITEM_TYPE info;
    List next;
} List_node;

typedef  struct  sublistnode  *  SubList;
typedef  struct  sublistnode  {
    ITEM_TYPE  *aluno;
    SubList  next;
}Sublist_node;

int a(char *id){
    int i=0,soma=0;
    for (;*(id+i);i++){
        if (*(id+i)>='A'){
            *(id+i) = *(id+i)-'A'+10;
        }
        else{
            *(id+1) = *(id+i)-'0';
        }
    }
    *id*=2;
    if(*id>=10){
        *id-=9;
    }
    if (*id){
        for (i=0;*(id+2*i+1) && *(id+2*i+1);i++){
            *(id+2*i+1)*=2;
            if (*(id+2*i+1)>=10){
                *(id+2*i+1)-=9;
            }
        }
    }
    for (i=0;*(id+i);i++){
        soma+=*(id+i);
    }
    if (soma%10==0){
        return 1;
    }
    return 0;
}

void  alunosDoMes  (List  lista,  int  mes,  SubList  sublista){
    SubList novo;
    for (lista=lista->next;lista;lista=lista->next){
        if (lista->info.nasicimento->mes==mes){
            novo=(SubList)malloc(sizeof(Sublist_node));
            novo->next=sublista->next;
            novo->aluno=&lista->info;
            sublista->next=novo;
        }
    }
}

List cria_lista(){
    int i=0;
    List header,novo;
    header=(List)malloc(sizeof(List_node));
    header->info.nasicimento=NULL;
    header->info.nome=NULL;
    header->info.num=0;
    header->next=NULL;
    for (;i<7;i++){
        novo=(List)malloc(sizeof(List_node));
        novo->info.nasicimento=(Data*)malloc(sizeof(Data));
        novo->info.nasicimento->ano=2000;
        novo->info.nasicimento->mes=2;
        novo->info.nasicimento->dia=1;
        novo->info.num=1234;
        novo->info.nome="teste";
        novo->next=header->next;
        header->next=novo;
    }
    novo=(List)malloc(sizeof(List_node));
    novo->info.nasicimento=(Data*)malloc(sizeof(Data));
    novo->info.nasicimento->ano=2000;
    novo->info.nasicimento->mes=12;
    novo->info.nasicimento->dia=27;
    novo->info.num=2;
    novo->info.nome="algo";
    novo->next=header->next;
    header->next=novo;
    for (i=0 ;i<3;i++){
        novo=(List)malloc(sizeof(List_node));
        novo->info.nasicimento=(Data*)malloc(sizeof(Data));
        novo->info.nasicimento->ano=2000;
        novo->info.nasicimento->mes=5;
        novo->info.nasicimento->dia=10;
        novo->info.num=4321;
        novo->info.nome="aqui";
        novo->next=header->next;
        header->next=novo;
    }
    return header;
}


int main(){
    int i=0;
    char teste[]="123456789ZZ1";
    printf("%d\n",a(teste));
    SubList header;
    header=(SubList)malloc(sizeof(Sublist_node));
    header->aluno=NULL;
    header->next=NULL;

    alunosDoMes(cria_lista(),5,header);
    for(header=header->next;header;header=header->next){
        printf("%d\n",header->aluno->num);
    }


    return 0;
}
