#include <stdio.h>
#include <stdlib.h>
#define MAX 4


typedef struct lnode *List;
typedef struct lnode{
    int info,counter;
    List next;
} List_node;

typedef struct node{
    int info;
    struct node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
}Queue;

int fputints(const char *name, int a[], int num){
        FILE *fp = fopen(name, "wb");
        int cnt = -1;
        if (fp != NULL)
        cnt = fwrite(a, sizeof(int), num, fp);
        fclose(fp);
        return cnt;
}

List ex2(int a[], int length){
    List header,aux,novo;
    int i;
    header = (List)malloc(sizeof(List_node));
    header->info=0;
    header->counter=0;
    header->next=NULL;
    for (i=0;i<length;i++){
        for (aux=header;aux->next;aux=aux->next){
            if (aux->next->info==a[i]){
                aux->next->counter++;
                break;
            }
        }
        if (aux->next==NULL){
            novo = (List)malloc(sizeof(List_node));
            novo->counter=1;
            novo->info=a[i];
            novo->next=header->next;
            header->next=novo;
        }
    }
    return header;
}
void print_tudo(List header){
    for (header=header->next;header;header=header->next){
        printf("Info:%d Contador:%d\n",header->info,header->counter);
    }
}




void print_filas(Queue * * filas, int length){
    int i,teste=1;
    Node *aux;
    aux=(Node*)malloc(sizeof(Node));
    aux->info=1;
    filas[0]->front=aux;
    filas[0]->rear=aux;
    aux->next=NULL;
    aux=(Node*)malloc(sizeof(Node));
    aux->info=2;
    aux->next=filas[0]->front;
    filas[0]->front=aux;
    while (teste==1){
        teste=0;
        for(i=0;i<MAX-1;i++){
            if (filas[i]->front){
                teste=1;
                aux = filas[i]->front;
                filas[i]->front=aux->next;
                if (aux->next==NULL){
                    filas[i]->rear=NULL;
                }
                aux->next = NULL;
                if (filas[i+1]->rear){
                    filas[i+1]->rear->next = aux;
                    filas[i+1]->rear = aux;
                }
                else{
                    filas[i+1]->rear=filas[i+1]->front=aux;
                }
            }
        }
        aux = filas[MAX-1]->front;
        if (aux!=NULL){
            teste=1;
            filas[MAX-1]->front = aux->next;
            if (aux->next==NULL){
                filas[MAX-1]->rear=NULL;
            }
            printf("%d\n",aux->info);
        }
    }
}


int main(){
    int i;
    Queue * filas[MAX];
    for (i=0;i<MAX;i++){
        filas[i]=(Queue*)malloc(sizeof(Queue));
        filas[i]->front=NULL;
        filas[i]->rear=NULL;
    }
    print_filas(filas,MAX);
    return 0
}
