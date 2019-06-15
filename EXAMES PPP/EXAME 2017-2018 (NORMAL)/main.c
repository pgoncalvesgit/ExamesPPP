#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void texto(char ficheiro[], char palavra[]){
    char buffer[1024];
    int tudo,aux,linha=0,fim;
    char *teste,*outro;
    FILE *f1;
    f1 = fopen(ficheiro,"r");
    while (fgets(buffer,1023,f1)){
        linha++;
        teste=buffer;
        outro=teste;
        tudo = strlen(teste);
        fim=tudo;
        strtok(teste," \n");
        if (strcmp(teste,palavra)==0){
            printf("Linha %d: %s ",linha,teste);
            aux=strlen(teste)+1;
            tudo-=aux;
            if (tudo!=0){
                teste+=aux;
                strtok(teste," \n");
                printf("%s ",teste);
            }
            printf("\n");
        }
        else{
            while(*teste){
                aux=strlen(teste)+1;
                teste+=aux;
                strtok(teste," \n");
                if (strcmp(teste,palavra)==0){
                    teste-=aux;
                    printf("Linha %d: %s ",linha,teste);
                    teste+=aux;
                    printf("%s ",teste);
                    tudo-=aux;
                    aux=strlen(teste)+1;
                    tudo-=aux;
                    if (tudo!=0){
                        teste+=aux;
                        strtok(teste," \n");
                        printf("%s ",teste);
                    }
                    printf("\n");
                    *teste=0;
                }
            }
        }
        for (;fim;fim--){
            outro[fim]=0;
        }
    }
}







int main()
{
    texto("chuva.txt","chuva");
    return 0;
}
