#include <stdio.h>
#include <stdlib.h>
#define MAX 5


    /*tipo = 1 significa ser prioritário, e tipo = 0, é não prioritário*/
typedef struct noPassageiro * pontPass;
typedef struct passageiro {
    char nome[50];
    int tipo;
} Passageiro;
typedef struct noPassageiro{
    Passageiro p;
    struct noPassageiro *next;
} NoPassageiro;

int length_fila(pontPass fila){
    int length=0;
    for (fila=fila->next;fila;fila=fila->next){
        length++;
    }
    return length;
}
pontPass fila_adequada(pontPass * balcoes){
    int tamanho, iterador,fila;
    tamanho = length_fila(balcoes[0]);
    fila = 0;
    iterador = 1;
    for (;iterador < MAX;iterador ++){
        if (tamanho>length_fila(balcoes[iterador])){
            tamanho = length_fila(balcoes[iterador]);
            fila = iterador;
        }
    }
    return balcoes[fila];
}
void insert_pessoa (Passageiro *pessoa,pontPass fila){
    pontPass novo;
    novo = (NoPassageiro*)malloc(sizeof(NoPassageiro));

    novo->next=fila->next;
    novo->p=*pessoa;
    fila->next=novo;
}
void prioritario(Passageiro *pessoa,pontPass fila){
    for (;fila->next;fila=fila->next){
        if (fila->next->p.tipo == 0){
            insert_pessoa(pessoa,fila);
            return;
        }
    }
    insert_pessoa(pessoa,fila);
}
void nao_prioritario(Passageiro *pessoa,pontPass fila){
    for(;fila->next;fila=fila->next){}
    insert_pessoa(pessoa,fila);
}
void coloca_passageiro_na_fila(Passageiro *pessoa ,pontPass balcoes){
    pontPass *fila;
    fila = fila_adequada(balcoes);
    if (pessoa->tipo == 1){
        prioritario(pessoa,fila);
    }
    if (pessoa->tipo == 0){
        nao_prioritario(pessoa,fila);
    }
    return;
}
void print_tudo(pontPass *tudo){
    int iterador = 0;
    pontPass temp;
    for (;iterador<MAX;iterador++){
        temp = tudo[iterador];
        printf("BALCAO - %d:\n",iterador);
        for (temp=temp->next;temp;temp=temp->next){
            printf("%s\n",temp->p.nome);
        }
        printf("\n");
    }
}
void cria_tudo(pontPass *tudo){
    int i=0;
    pontPass novo;
    for (;i<MAX;i++){
        novo = (NoPassageiro*)malloc(sizeof(NoPassageiro));
        novo->p.nome[0]=0;
        novo->p.tipo=0;
        novo->next=NULL;
        tudo[i]=novo;
    }
}
char *custom_int2str(int i){
    char *algo;
    algo = (char*)malloc(sizeof(char)*4);
    *algo = i/100 + '0';
    i=i%100;
    *(algo + 1) = i/10 + '0';
    i=i%10;
    *(algo + 2) = i/1 + '0';
    *(algo + 3) = 0;
    return algo;
}
void coloca_tudo(pontPass *varios){
    char algo[4];
    int i = 0;
    for (;i<20;i++){
        Passageiro *novo;
        novo = (Passageiro*)malloc(sizeof(Passageiro));
        strcpy(novo->nome,custom_int2str(i));
        novo->tipo=0;
        if (i%5==0){
            novo->tipo=1;
        }
        coloca_passageiro_na_fila(novo,varios);
    }
}

void muda_prioritarios(pontPass *balcoes){
    pontPass aux;
    int i=1;
    if (balcoes[0]->next && balcoes[0]->next->p.tipo==0){
        if (2>=MAX && balcoes[1]->next && balcoes[1]->next->p.tipo==1 && balcoes[1]->next->next && balcoes[1]->next->next->p.tipo==1){
            aux=balcoes[1]->next->next;
            balcoes[1]->next->next=aux->next;
            aux->next=balcoes[0]->next;
            balcoes[0]->next=aux;
        }
    }
    for (;i<MAX-1;i++){
        if(balcoes[i]->next && balcoes[i]->next->p.tipo==0){
            if (balcoes[i-1]->next && balcoes[i-1]->next->p.tipo==1 && balcoes[i-1]->next->next && balcoes[i-1]->next->next->p.tipo==1){
                aux=balcoes[i-1]->next->next;
                balcoes[i-1]->next->next=aux->next;
                aux->next=balcoes[i]->next;
                balcoes[i]->next=aux;
            }
            else{
                if (balcoes[i+1]->next && balcoes[i+1]->next->p.tipo==1 && balcoes[i+1]->next->next && balcoes[i+1]->next->next->p.tipo==1){
                    aux=balcoes[i+1]->next->next;
                    balcoes[i+1]->next->next=aux->next;
                    aux->next=balcoes[i]->next;
                    balcoes[i]->next=aux;
                }
            }
        }
    }
    if (balcoes[i]->next && balcoes[i]->next->p.tipo==0){
        if (balcoes[i-1]->next && balcoes[i-1]->next->p.tipo==1 && balcoes[i-1]->next->next && balcoes[i-1]->next->next->p.tipo==1){
            aux=balcoes[i-1]->next->next;
            balcoes[i-1]->next->next=aux->next;
            aux->next=balcoes[i]->next;
            balcoes[i]->next=aux;
        }
    }
}


















int main(){
    int i;
    pontPass balcoes[MAX];
    cria_tudo(balcoes);

    coloca_tudo(balcoes);
    /*
    Passageiro *novo;
    novo = (Passageiro*)malloc(sizeof(Passageiro));
    strcpy(novo->nome,"teste1");
    novo->tipo=0;

    coloca_passageiro_na_fila(novo,balcoes);
    */
    muda_prioritarios(balcoes);
    print_tudo(balcoes);
    return 0;
}
