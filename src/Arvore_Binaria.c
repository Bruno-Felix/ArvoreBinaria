#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Arvore_Binaria.h"

int maior(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

//AÇÕES COM A ÁRVORE_______________________//


structArvore *loadTreeFromFile(char filename[25]){
    
    FILE *leitura;
    leitura = fopen(filename, "r");    
    if(leitura == NULL){
        printf("\n\nError: Fail to open File!\n\n");
    }

    structArvore *raiz = (structArvore*)(malloc(sizeof(structArvore)));
    char aux;

    fscanf(leitura, "%d%c", &raiz->numero, &aux);
    //printf("Raiz: %d\n", raiz->numero);
    raiz->altura = 1;
    raiz->num_left = NULL;
    raiz->num_right = NULL;

    structArvore *noAntigo;
    structArvore *novoNumero;

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

                    //printf("n > r && null: %d\n", novoNumero->numero);
                 }
                else{
                    noAntigo = noAntigo->num_right;

                    //printf("n > r &!= null: %d\n", novoNumero->numero);
                }
            }
            //Se o novo_nomero for menor que a raiz
            else{
                if(noAntigo->num_left == NULL){

                    noAntigo->num_left = novoNumero;
                    novoNumero->altura = noAntigo->altura + 1;

                    auxAv = 1;

                    //printf("n < r && null: %d\n", novoNumero->numero);
                }
                else{
                    noAntigo = noAntigo->num_left;

                    //printf("n < r != null: %d\n", novoNumero->numero);
                }
            }
        }
        //printf("altura: %d\n", novoNumero->altura);
    }
    return raiz;
}

void printInOrder(structArvore *novaArvore){
    
    if(novaArvore != NULL){
        printInOrder(novaArvore->num_left);

        printf(" %d", novaArvore->numero);

        printInOrder(novaArvore->num_right);
    }
}


void printPreOrder(structArvore *novaArvore){
 
    if(novaArvore != NULL){
        
        printf(" %d", novaArvore->numero);

        printPreOrder(novaArvore->num_left);
        printPreOrder(novaArvore->num_right);
    }
}

void printPosOrder(structArvore *novaArvore){
 
    if(novaArvore != NULL){
        printPosOrder(novaArvore->num_left);
        printPosOrder(novaArvore->num_right);

        printf(" %d", novaArvore->numero);
    }
}

int getHeight(structArvore *novaArvore){

    if((novaArvore == NULL) || (novaArvore->num_left == NULL && novaArvore->num_right == NULL)){
        return 0;
    }  
    else{
       return 1 + maior(getHeight(novaArvore->num_left), getHeight(novaArvore->num_right));
    }
}











//_________________________________________//
