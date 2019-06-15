#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASS 5


typedef struct no_viagem * ListViagens;
typedef struct no_viagem{
    int id;
    char *dest;
    ListViagens next;
} NoViagem;

typedef struct no_passageiro * ListPassageiros;
typedef struct no_passageiro{
    int id;
    char *nome;
    ListPassageiros next;
} NoPassageiro;

typedef struct bilhetes * ListBilhetes;
typedef struct bilhetes{
    ListViagens viagem;
    ListPassageiros passageiro;
    ListBilhetes next;
} NoBilhete;

int contaBilhetesViagem(int id, ListBilhetes header){
    int contador=0;
    for (header=header->next;header;header=header->next){
        if (header->viagem->id==id){
            contador++;
        }
    }
    return contador;
}

int adicionaBilhete (int id_viagem, int id_pass, ListBilhetes bilhetes, ListPassageiros passageiros, ListViagens viagens){
    int contador;
    ListPassageiros novo;
    ListViagens nova;
    ListBilhetes bil;
    contador=contaBilhetesViagem(id_viagem,bilhetes);
    if (contador<MAX_PASS && contador!=0){
        novo=passageiros;
        for (novo=novo->next;novo && novo->id!=id_pass;novo=novo->next){}
        if (!novo){
            return 0;
        }
        nova=viagens;
        for (nova=nova->next;nova && nova->id!=id_viagem;nova=nova->next){}
        bil = (ListBilhetes)malloc(sizeof(NoBilhete));
        bil->passageiro=novo;
        bil->viagem=nova;
        bil->next=bilhetes->next;
        bilhetes->next=bil;
        return 1;
    }
    return 0;
}

int comparaFicheiros(char *fich1,char *fich2){
    FILE *f1,*f2;
    char buffer1[1024],buffer2[1024];
    int i,j,contador=0;
    f1=fopen(fich1,"r");
    f2=fopen(fich2,"r");
    if (!f1 || !f2){
        return -1;
    }
    while (fgets(buffer1,1023,f1) && fgets(buffer2,1023,f2)){
        for (i=0;*(buffer1+i);i++){
            for (j=0;*(buffer2+j);j++){
                if (*(buffer1+i)==*(buffer2+j)){
                    break;
                }
            }
            if (*(buffer2+j)==0){
                break;
            }
        }
        if (*(buffer1+i)==0 && strlen(buffer1)==strlen(buffer2)){
            contador++;
        }
    }
    return contador;
}

int main()
{
    printf("%d\n",comparaFicheiros("teste.txt","teste2.txt"));
    printf("%d",atoi("123"));

    return 0;
}
