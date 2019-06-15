#include <stdio.h>
#include <stdlib.h>

typedef struct Deputado *lista;
typedef struct Deputado{
    char nome[50];
    char distrito[20];
    lista next;
}deputado;

typedef struct Politica * auxi;
typedef struct Politica{
    char nome[10];
    int numero;
    lista deputados;
}politica;

auxi vetor[17];


void b(char sigla[]){
    int i=0,j=0,k;
    char fim[22];
    FILE *f1;
    lista aux;

    strcpy(fim,"eleitos");
    for (;i<17;i++){
        if (strcmp(sigla,vetor[i]->nome)==0){
            for (j=7;*(vetor[i]->nome + j - 7);j++){
                *(fim+j) = *(vetor[i]->nome + j - 7);
            }
            *(fim+j)='.';
            *(fim+j+1)='t';
            *(fim+j+2)='x';
            *(fim+j+3)='t';
            *(fim+j+4)=0;
            aux=vetor[i]->deputados;
            f1=fopen(fim,"w");
            for(;aux;aux=aux->next){
                fprintf(f1,"%s\n",aux->nome);
                printf("%s\n",aux->nome);
            }
            fclose(f1);
        }
    }
}

void c(auxi vetor[],char sigla[],char nome[], char distrito[]){
    lista dep, aux;
    int i=0;
    dep=(lista)malloc(sizeof(deputado));
    strcpy(dep->distrito,distrito);
    strcpy(dep->nome,nome);
    for (;i<17;i++){
        if (strcmp(sigla,vetor[i]->nome)==0){
            if (vetor[i]->deputados!=NULL){
                for (aux=vetor[i]->deputados;aux->next;aux=aux->next){}
                aux->next=dep;
                dep->next=NULL;
            }
        }
    }
}

void d(auxi vetor[],char distrito[]){
    int i=0,j,iaux=0,contador_definitivo=0, contador=0,auxiliar[17];
    lista dep,aux;
    for (;i<17;i++){
        auxiliar[i]=0;
    }
    for (i=0;i<17;i++){
        dep=vetor[i]->deputados;
        for (;dep;dep=dep->next){
            if (strcmp(dep->distrito,distrito)==0){
                contador++;
            }
        }
        if (contador==contador_definitivo && contador>0){
            iaux++;
            auxiliar[iaux]=i;
        }
        if (contador>contador_definitivo){
            contador=0;
            iaux=0;
            contador_definitivo=contador;
            auxiliar[0]=i;
            for (j=1;j<17;j++){
                auxiliar[j]=0;
            }
        }
    }
    for (i=0;i<iaux+1;i++){
        printf("%s\n",vetor[auxiliar[i]]->nome);
    }
}

int main()
{
    lista novo;
    int i=0;
    char r[]="r";
    for(;i<17;i++){
        vetor[i]=(auxi)malloc(sizeof(politica));
        *vetor[i]->nome=0;
        vetor[i]->deputados=NULL;
        vetor[i]->numero=0;
    }
    strcpy(vetor[2]->nome,"r");
    vetor[2]->numero=2;
    novo=(lista)malloc(sizeof(deputado));
    strcpy(novo->nome,"Gustavo");
    novo->next=NULL;
    strcpy(novo->distrito,"Coimbra");
    vetor[2]->deputados=novo;
    novo=(lista)malloc(sizeof(deputado));
    strcpy(novo->nome,"Alex");
    novo->next=vetor[2]->deputados;
    strcpy(novo->distrito,"Coimbra");
    vetor[2]->deputados=novo;

    c(vetor,r,"Gilberto","Coimbra");
    b(r);
    d(vetor,"Coimbra");





    return 0;
}
