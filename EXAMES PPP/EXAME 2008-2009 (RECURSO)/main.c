#include <stdio.h>
#include <stdlib.h>

typedef struct  list_node  *my_lists;
typedef struct  list_node{
    struct  list_node_t  *address;
    struct  list_node  *next;
};
typedef struct  list_node_t{
    void  *value;
    struct  list_node_t  *next;
};

my_lists cria_my_list(){
    my_lists header, nova;
    struct list_node_t *novo, *antes;
    int i=0,j;
    header = (my_lists)malloc(sizeof(struct list_node));
    header->next=NULL;
    header->address=NULL;
    for (;i<10;i++){
        nova = (my_lists)malloc(sizeof(struct list_node));
        nova->next=header->next;
        header->next=nova;
        novo = (struct list_node_t*)malloc(sizeof(struct list_node_t));
        nova->address=novo;
        novo->value=i;
        novo->next=NULL;
        for (j=10;j>i;j--){
            novo = (struct list_node_t*)malloc(sizeof(struct list_node_t));
            novo->value=30-j-i;
            novo->next=nova->address;
            nova->address=novo;
        }
    }
    return header;
}

void print_tudo(my_lists lista){

    for (lista=lista->next;lista;lista=lista->next){
        for (;lista->address;lista->address=lista->address->next){
            printf("%d  ",lista->address->value);
        }
        printf("\n");
    }

}


int get_list_size(struct  list_node_t  *list){
    int length=0;
    for (list=list->next;list;list=list->next){
        length++;
    }
    return length;
}

int vencedor(int N,int M){
    int i=0;
    my_lists primeiro;
    struct list_node_t * aux,*antes;
    primeiro = (my_lists)malloc(sizeof(struct list_node));
    primeiro->next=NULL;
    primeiro->address = (struct list_node_t *)malloc(sizeof(struct list_node_t));
    primeiro->address->value=1;
    primeiro->address->next=NULL;
    antes=primeiro->address;
    for (i=2;i<N;i++){
        aux = (struct list_node_t *)malloc(sizeof(struct list_node_t));
        antes->next=aux;
        aux->next=NULL;
        aux->value=i;
        antes=aux;
    }
    antes->next=primeiro->address;
    aux=primeiro->address;
    while(aux->next!=aux){
        for (i=1;i<M;i++){
            aux=aux->next;
        }
        antes=aux->next;
        aux->next=antes->next;
        free(antes);
    }
    return aux->value;
}

void sort_list(my_lists lista){
    my_lists aux;
    struct list_node_t *outro_aux;
    aux=lista;
    int teste=1;
    if (aux->next && aux->next->next){
        while (teste==1){
            aux=lista;
            teste=0;
            for (;aux->next->next;aux=aux->next){
                if (get_list_size(aux->next->address)<get_list_size(aux->next->next->address)){
                    teste=1;
                    outro_aux=aux->next->address;
                    aux->next->address=aux->next->next->address;
                    aux->next->next->address=outro_aux;
                }
            }
        }
    }
}

int main(){
    my_lists teste;
    teste=cria_my_list();
    sort_list(teste);
    print_tudo(teste);
    return 0;
}
