#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5


typedef struct passageiro{
    char * nome;
    char * origem;
    char * destino;
}Passageiro;

typedef struct carruagem{
    int classe;
    int num_lug;
    Passageiro * * lugares;
}Carruagem;

typedef struct lnode * List;
typedef struct lnode{
    Carruagem info;
    List next;
}List_node;

typedef struct passlistnode * PassList;
typedef struct passlistnode{
    Passageiro * passag;
    PassList next;
}Passlist_node;

List cria_header_list(){
    List header;
    Carruagem *primeira;
    header = (List_node*)malloc(sizeof(List_node));
    primeira = (Carruagem*) malloc(sizeof(Carruagem));
    header->info = *primeira;
    header->next = NULL;
    return header;
}
void cria_comboio(List header){
    List novo;
    Carruagem *nova;
    int i=0;
    for (;i<2;i++){
        novo = (List_node*)malloc(sizeof(List_node));
        nova = (Carruagem*)malloc(sizeof(Carruagem));
        nova->classe=1;
        novo->info = *nova;
        novo->next = header->next;
        header->next = novo;
    }
}
void constroi_carruagens(List header){
    int i,j;
    Passageiro *novo;
    for (i=0;i<3;i++){
        header->info.num_lug=i;
        header->info.lugares = (Passageiro*)malloc(sizeof(Passageiro)*i);
        for (j=0;j<i;j++){
            novo = (Passageiro*)malloc(sizeof(Passageiro));
            header->info.lugares[j]=novo;
            novo->origem = "LOL";
            if (j==0){
                novo->nome = "Primeiro";
                novo->destino = "Don't Starve";
            }
            else{
                novo->nome = "Segundo";
                novo->destino = "CS-GO";
            }
        }
        header=header->next;
    }
}
PassList cria_header_pass_list(){
    PassList aux;
    aux=(Passlist_node*)malloc(sizeof(Passlist_node));
    aux->passag=NULL;
    aux->next=NULL;
    return aux;
}
PassList passageirosParaDestino (List comboio, char * destino){
    int i=0;
    PassList aux, header;
    header = cria_header_pass_list();
    for(;comboio;comboio=comboio->next){
        for(i=0;i<comboio->info.num_lug;i++){
            if (comboio->info.lugares[i] && strcmp(comboio->info.lugares[i]->destino, destino) == 0){
                aux = (Passlist_node*)malloc(sizeof(Passlist_node));
                aux->next=header->next;
                header->next=aux;
                aux->passag=comboio->info.lugares[i];
            }
        }
    }
    return header;
}


PassList passageirosParaDestino_Judao (List comboio, char * destino){
    int i =0;
    PassList aux = (PassList) malloc(sizeof(Passlist_node));
    aux->next = NULL;
    aux->passag = NULL;
    for(;comboio;comboio= comboio->next){
        for(i=0;i< comboio->info.num_lug ;i++){
            if(comboio->info.lugares[i] != NULL && strcmp(destino,comboio->info.lugares[i]->destino) == 0){
                PassList aux2 = (PassList) malloc(sizeof(Passlist_node));
                aux2->passag = comboio->info.lugares[i];
                aux2->next = aux->next;
                aux->next = aux2;
            }
        }
    }
    return aux;
}


void print_tudo(PassList passageiros){
    for (passageiros=passageiros->next;passageiros;passageiros=passageiros->next){
        printf("%s\n",passageiros->passag->nome);
    }
}

int main()
{
    List header;
    header = cria_header_list();
    cria_comboio(header);
    constroi_carruagens(header);

    print_tudo(passageirosParaDestino_Judao(header, "CS-GO"));


    return 0;
}














typedef struct corridas{
    int num;
    char nome[100];
    int menor;
    int maior;
    int soma;
}Corridas;

Corridas *encontra_pessoa(int id){
    FILE *f1;
    int iterador=0,soma=0,aux;
    char buffer[1024];
    const char sep[] = "\n";
    Corridas *novo;
    novo=(Corridas*)malloc(sizeof(Corridas));
    novo->maior=0;
    novo->menor=0;
    f1=fopen("teste.txt","r");
    while (fgets(buffer,1023,f1)){
        aux=atoi(buffer);
        if (id==aux){
            novo->num=id;
            fgets(buffer,1023,f1);
            strtok(buffer,sep);
            strcpy(novo->nome,buffer);
            fgets(buffer,1023,f1);
            fgets(buffer,1023,f1);
            aux=atoi(buffer);
            if (novo->menor>aux || novo->menor==0){
                novo->menor=aux;
            }
            if (novo->maior<aux){
                novo->maior=aux;
            }
            soma+=aux;
        }
        else{
            for (iterador=0;iterador<3;iterador++){
                fgets(buffer,1023,f1);
            }
        }
    }
    novo->soma=soma;
    if (novo->menor==0){
        strcpy(novo->nome,"not found");
        novo->maior=0;
        novo->soma=0;
    }
    return novo;
}


void fim(Corridas *corrida){
    FILE *f2;
    f2 = fopen("final.txt","w");
    fprintf(f2,"%d\n%s\n%d\n%d\n%d",corrida->num,corrida->nome,corrida->menor,corrida->maior,corrida->soma);
}




int main2(){

    Corridas *corrida;
    corrida = encontra_pessoa(1234);
    printf("%d\n%s\n%d\n%d\n%d",corrida->num,corrida->nome,corrida->menor,corrida->maior,corrida->soma);
    fim (corrida);

    return 0;
}
