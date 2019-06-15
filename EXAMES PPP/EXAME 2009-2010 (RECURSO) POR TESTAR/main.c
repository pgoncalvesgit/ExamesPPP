#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void  insere_jogo(List  l,  char*  paisA,  char*  paisB,  int  golosA,  int  golosB){
    int i,j=1;
    Pont_jogo novo;
    novo = (Pont_jogo)malloc(sizeof(Jogo_node));
    novo->g1=golosA;
    novo->g2=golosB;
    for (l=l->next;l;l=l->next){
        if (strcmp(l->nome,paisA)==0 || strcmp(l->nome,paisB)==0){
            for(i=0;i<3;i++){
                if (l->jogos[i]==NULL){
                    l->jogos[i]=novo;
                    if (j==1){
                        j=2;
                        novo->p1=l;
                    }
                    else{
                        novo->p2=l;
                    }
                    i=3;
                }
            }
        }
    }
}

int pontos(List l, char *nome){
    int g1,g2,pontos=0,i;
    for (l=l->next;l;l=l->next){
        if(strcmp(l->nome,nome)==0){
            for(i=0;i<3;i++){
                if (l->jogos[i]->p1==l){
                    g1=l->jogos[i]->g1;
                    g2=l->jogos[i]->g2;
                }
                else{
                    g2=l->jogos[i]->g1;
                    g1=l->jogos[i]->g2;
                }
                if (g1>g2){
                    pontos+=3;
                }
                if (g1==g2){
                    pontos+=1;
                }
            }
        }
    }
    return pontos;
}


Pont_jogo  mais_golos(List  l,  char  grp){
    int max=-1,i=0,golos;
    List aux;
    aux=l;
    for (l=l->next;l;l=l->next){
        if (l->grupo==grp){
            for (i=0;i<3;i++){
                golos = l->jogos[i]->g1+l->jogos[i]->g2;
            }
            if (max<golos){
                max=golos;
            }
        }
    }
    l=aux;
    for (l=l->next;l;l=l->next){
        if(l->grupo==grp){
            for (i=0;i<3;i++){
                if (max==l->jogos[i]->g1+l->jogos[i]->g2){
                    return l->jogos[i];
                }
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}
