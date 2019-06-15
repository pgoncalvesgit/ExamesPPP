#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef  struct  no_disciplina  *  ListDisciplinas;
typedef  struct  no_disciplina{
    char  *  nome;
    struct  no_apont_aluno  *  alunos;
    ListDisciplinas  next;
}NoDisciplina;

typedef  struct  no_aluno  *  ListAlunos;
typedef  struct  no_aluno{
    char  *  nome;
    int  numero;
    struct  no_apont_disciplina  *  disciplinas;
    ListAlunos  next;
}NoAluno;

typedef  struct  no_apont_disciplina  *  ListApontDisciplinas;
typedef  struct  no_apont_disciplina{
    ListDisciplinas  disciplina;
    ListApontDisciplinas  next;
}NoApontDisciplina;

typedef  struct  no_apont_aluno  *  ListApontAlunos;
typedef  struct  no_apont_aluno{
    ListAlunos  aluno;
    ListApontAlunos  next;
}NoApontAluno;

void  criaListApontDisciplinas(ListDisciplinas disc){
    struct no_apont_aluno *aux;
    ListApontDisciplinas cria;
    for(;disc;disc=disc->next){
        for (aux=disc->alunos;aux;aux=aux->next){
            cria=(ListApontDisciplinas)malloc(sizeof(NoApontDisciplina));
            cria->next=aux->aluno->disciplinas;
            cria->disciplina=disc;
            aux->aluno->disciplinas=cria;
        }
    }

}

void cut (char *nome_fich, int li, int ci, int lf, int cf){
    FILE *f1;
    int i=0,k,length=0;
    char buffer[1024];
    f1 = fopen(nome_fich,"r");
    while(fgets(buffer,1023,f1)){
        length++;
    }
    fclose(f1);

    if(li<0){
        li++;
    }
    while (li<=0){
        li+=length;
    }
    if (lf<0){
        lf++;
    }
    while (lf<=0){
        lf+=length;
    }
    f1 = fopen(nome_fich,"r");
    while (fgets(buffer,1023,f1)){
        i++;
        if (i>=li && i<=lf){
            for (k=ci-1;k<cf;k++){
                printf("%c",buffer[k]);
            }
            printf("\n");
        }
        else{
            if (i==li){
                i=0;
                for (k=ci-1;k<cf;k++){
                    printf("%c",buffer[k]);
                }
                fseek (f1, 0L, SEEK_SET);
                li--;
                printf("\n");
            }
        }

    }
    fclose(f1);
}

int media_calc(int *v, int n){
    float media;
    int i=0;
    for(i=0;i<n;i++){
        *(v+i)=i;
        media=media+*(v+i);
    }
    media=media/n;
    return media;
}

int  main(){
    /*int  *v,i,n,j,*aux,outro;
    float media;
    n=10;
    v=(int*)malloc(sizeof(int)*n);
    aux=(int*)malloc(sizeof(int)*n);
    for (j=0;j<n;j++){
        aux[j]=NULL;
    }
    media=media_calc(v,n);
    printf("media:%f\n",media);
    for(i=0;i<n;i++){
        if(*(v+i)>=media){
            for (j=0;*(aux+j);j++){
                if (*(aux+j)==*(v+i)){
                    break;
                }
            }
            if (*(aux+j)==NULL){
                *(aux+j)=*(v+i);
            }
        }
    }
    for (i=0;i<n && *(aux+i);i++){
        for (j=0;j<n-i-1 && *(aux+j+1);j++){
            if (*(aux+j) < *(aux+j+1)){
                outro=*(aux+j);
                *(aux+j)=*(aux+j+1);
                *(aux+j+1)=outro;
            }
        }
    }
    for (i=0;i<n && *(aux+i);i++){
        printf("%d\n",*(aux+i));
    }*/
    FILE *f1;
    char buffer[]="Aqui está uma string que eu criei\n e quero testar oq mete no ficheiro\n";
    f1 = fopen("teste_aqui.txt","w");
    fputs(buffer,f1);
    printf("teste:%s",buffer);


    return  0;
}
