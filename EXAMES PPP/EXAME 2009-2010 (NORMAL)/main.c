#include <stdio.h>
#include <stdlib.h>

typedef struct lnode *List;
typedef struct lnode{
    char * key;
    int key_counter;
    List next;
}List_node;

int decrementa_lista(List lista, char *chave, int n){
    List aux;
    int num;
    for (;lista->next;lista=lista->next){
        if (strcmp(lista->next->key,chave)==0){
            if (n>lista->next->key_counter){
                aux = lista->next;
                num=aux->key_counter;
                lista->next=aux->next;
                free(aux);
                return num;
            }
            lista->next->key-=n;
        }
    }
}

int main()
{
    List header,novo;
    int i=0;
    header=(List)malloc(sizeof(List_node));
    header->key=header->next=NULL;
    header->key_counter=0;

    for (;i<10;i++){
        novo=(List)malloc(sizeof(List_node));
        novo->key="teste";
        novo->key_counter=i;
        novo->next=header->next;
        header->next=novo;
    }
    printf("%d\n",decrementa_lista(header,"teste",11));
    printf("%d\n",decrementa_lista(header,"teste",11));
    printf("%d\n",decrementa_lista(header,"teste",11));

    return 0;
}
