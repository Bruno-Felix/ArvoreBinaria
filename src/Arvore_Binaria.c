#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Arvore_Binaria.h"


//AÇÕES COM A ÁRVORE_______________________//


structArvore *loadTreeFromFile(char filename[25]){
    
    FILE *leitura;
    leitura = fopen(filename, "r");    
    if(leitura == NULL){
        printf("\n\nError: Fail to open File!\n\n");
    }

    structArvore *raiz = (structArvore*)(malloc(sizeof(structArvore)));
    structArvore *noAntigo;
    structArvore *novoNumero;
    char aux;

    fscanf(leitura, "%d%c", &raiz->numero, &aux);
    printf("Raiz: %d\n", raiz->numero);
    raiz->altura = 1;
    raiz->num_left = NULL;
    raiz->num_right = NULL;


    while(!feof(leitura)){
        
        novoNumero = (structArvore*)(malloc(sizeof(structArvore)));

        fscanf(leitura, "%d%c", &novoNumero->numero, &aux);
        //printf("%d\n", novoNumero->numero);
        novoNumero->num_left = NULL;
        novoNumero->num_right = NULL;

        int auxAv = 0;
        noAntigo = raiz;

        while(auxAv == 0){
            //Se o novo_nomero for maior que a raiz
            if(novoNumero->numero > noAntigo->numero){
                if(noAntigo->num_right == NULL){
                    
                    noAntigo->num_right = novoNumero;
                    novoNumero->altura = noAntigo->altura + 1;

                    auxAv = 1;

                    printf("n > r && null: %d\n", novoNumero->numero);
                 }
                else{
                    noAntigo = noAntigo->num_right;

                    printf("n > r &!= null: %d\n", novoNumero->numero);
                }
            }
            //Se o novo_nomero for menor que a raiz
            else{
                if(noAntigo->num_left == NULL){

                    noAntigo->num_left = novoNumero;
                    novoNumero->altura = noAntigo->altura + 1;

                    auxAv = 1;

                    printf("n < r && null: %d\n", novoNumero->numero);
                }
                else{
                    noAntigo = noAntigo->num_left;

                    printf("n < r != null: %d\n", novoNumero->numero);
                }
            }
        }
    }
    return raiz;
}

void showTree(structArvore *novaArvore){
 
    if(novaArvore != NULL){
        showTree(novaArvore->num_left);
        printf(" %i", novaArvore->numero);
        showTree(novaArvore->num_right);
    }
}
    











//_________________________________________//
