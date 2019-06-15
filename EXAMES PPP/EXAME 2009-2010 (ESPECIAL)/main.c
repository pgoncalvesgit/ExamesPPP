#include <stdio.h>
#include <stdlib.h>

typedef struct List * lista;
typedef struct List{
    int num;
    lista next;
}Lista;

lista cria_lista(){
    lista header, nova;
    int i=0;
    header = (lista)malloc(sizeof(Lista));
    header->next=NULL;
    header->num=0;
    for (;i<10;i++){
        nova = (lista)malloc(sizeof(Lista));
        nova->next=header->next;
        header->next=nova;
        nova->num=i;
    }
}

lista ordena(lista header){
    lista header_nova,nova,aux;
    int aux_num,teste=1;
    header_nova = (lista)malloc(sizeof(Lista));
    header_nova->next=NULL;
    header_nova->num=0;
    for(header=header->next;header;header=header->next){
        for (aux=header_nova; aux->next && aux->next->num!=header->num ;aux=aux->next){}
        if (aux->next==NULL){
            nova = (lista)malloc(sizeof(Lista));
            nova->num=header->num;
            nova->next=header_nova->next;
            header_nova->next=nova;
        }
    }
    aux=header_nova;
    if (aux->next){
        while (teste==1){
            teste=0;
            aux=header_nova;
            for (;aux->next->next;aux=aux->next){
                if (aux->next->num>aux->next->next->num){
                    teste=1;
                    aux_num=aux->next->num;
                    aux->next->num=aux->next->next->num;
                    aux->next->next->num=aux_num;
                }
            }
        }
    }
    return header_nova;
}
void print_tudo(lista header){
    for(header=header->next;header;header=header->next){
        printf("%d\n",header->num);
    }
}

typedef struct conta * especial;
typedef struct conta{
    int num;
    int contador;
    especial next;
}Conta;


especial contador(lista header){
    lista aux;
    especial novo_header,aux_novo,novo;
    novo_header=(especial)malloc(sizeof(Conta));
    novo_header->next=NULL;
    novo_header->num=0;
    novo_header->contador=0;
    for (aux=header->next;aux;aux=aux->next){
        for (aux_novo=novo_header->next;aux_novo;aux_novo=aux_novo->next){
            if (aux_novo->num==aux->num){
                aux_novo->contador++;
            }
        }
        if (aux_novo==NULL){
            novo=(especial)malloc(sizeof(Conta));
            novo->num=aux->num;
            novo->contador=1;
            novo->next=novo_header->next;
            novo_header->next=novo;
        }
    }
    return novo_header;
}

int maior_numero(lista header){
    especial novo,aux;
    int max_cont=0,min=0;
    novo=contador(header);
    aux=novo;
    for (novo=novo->next;novo;novo=novo->next){
        if (max_cont<novo->contador){
            max_cont=novo->contador;
        }
        if (min<novo->num){
            min=novo->num;
        }
    }
    novo=aux;
    for (novo=novo->next;novo;novo=novo->next){
        if (novo->contador==max_cont && novo->num<min){
            min=novo->num;
        }
    }
    return min;
}
typedef struct aux * auxilia;
typedef struct aux{
    char a;
    auxilia next;
}Aux;

int verifica(){
    FILE *f1;
    int i=0;
    char buffer[1024];
    char aux;
    auxilia header, ajuda,outra_ajuda;
    header=(auxilia)malloc(sizeof(Aux));
    header->a=0;
    header->next=NULL;
    ajuda=header;
    f1 =fopen("funcao.txt","r");
    while (fgets(buffer,1023,f1)){
        for (i=0;*(buffer+i);i++){
            header=ajuda;
            if (*(buffer+i)=='{' || *(buffer+i)=='}' || *(buffer+i)=='[' || *(buffer+i)==']' || *(buffer+i)=='(' || *(buffer+i)==')'){
                if (header->next){
                    for (;header->next->next;header=header->next){}
                }
                if (header->next && ((header->next->a=='{' && *(buffer+i)=='}') || (header->next->a=='(' && *(buffer+i)==')') ||
                    (header->next->a=='[' && *(buffer+i)==']'))){
                    outra_ajuda = header->next;
                    header->next=NULL;
                    free(outra_ajuda);
                }
                else{
                    outra_ajuda=(auxilia)malloc(sizeof(Aux));
                    outra_ajuda->a=*(buffer+i);
                    outra_ajuda->next=NULL;
                    if (header->next){
                        header->next->next=outra_ajuda;
                    }
                    else{
                        header->next=outra_ajuda;
                    }
                }
            }
        }
    }
    if (header->next!=NULL){
    printf("header: %c %d\n",header->next->next->a,header->next->next->next);
        return 0;
    }
    return 1;
}


int main()
{
    lista aqui;
    aqui=cria_lista();
    printf("%d",maior_numero(aqui));
    printf("\n\n");
    print_tudo(ordena(aqui));
    printf("\n\n");
    printf("%d",verifica());
    return 0;
}
