#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Arvore_Binaria.h"

//Auxiliar_________________________________//
int maior(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

//FUNÇÕES_COM__A_ÁRVORE________________________//

//LoadTreeFromFile
structArvore *loadTreeFromFile(char filename[25]){
    
    //Leitura
    FILE *leitura;
    leitura = fopen(filename, "r");    
    if(leitura == NULL){
        printf("\n\nError: Fail to open File!\n\n");
    }

    //Inserção da Raiz
    structArvore *raiz = (structArvore*)(malloc(sizeof(structArvore)));
    char aux;

    fscanf(leitura, "%d%c", &raiz->numero, &aux);
    //printf("Raiz: %d\n", raiz->numero);
    raiz->altura = 1;
    raiz->num_left = NULL;
    raiz->num_right = NULL;

    structArvore *noAntigo;
    structArvore *novoNumero;

    //Inserção dos Demais nós
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

    //Retorno do endereço da raiz da árvore
    return raiz;
}

//Print In/Pos/Pre Order
void printInOrder(structArvore *Arvore){
    
    if(Arvore != NULL){
        printInOrder(Arvore->num_left);

        printf(" %d", Arvore->numero);

        printInOrder(Arvore->num_right);
    }
}
void printPreOrder(structArvore *Arvore){
 
    if(Arvore != NULL){
        
        printf(" %d", Arvore->numero);

        printPreOrder(Arvore->num_left);
        printPreOrder(Arvore->num_right);
    }
}
void printPosOrder(structArvore *Arvore){
 
    if(Arvore != NULL){
        printPosOrder(Arvore->num_left);
        printPosOrder(Arvore->num_right);

        printf(" %d", Arvore->numero);
    }
}

//GetHeight
int getHeight(structArvore *Arvore){

    if((Arvore == NULL) || (Arvore->num_left == NULL && Arvore->num_right == NULL)){
        return 0;
    }  
    else{
       return 1 + maior(getHeight(Arvore->num_left), getHeight(Arvore->num_right));
    }
}

//SearchValue
void searchValue(structArvore *Arvore, int valorBusca){

    structArvore *Busca = Arvore;
    structArvore *Pai = NULL;
    structArvore *Irmao = NULL;
    
    int auxNivelNo = 0;
    
    int auxSV = 0;
    int auxEncontradoDir = 0;
    int auxEncontradoEsq = 0;

    while(auxSV == 0){
        
        //Nível do Nó:
        auxNivelNo ++;
        
        //Se o valorBusca for igual ao Nó atual(Arvore)
        if(Arvore->numero == valorBusca){

            printf("\n\n - Nó Encontrado:\n\n");
            printf("    Nó: %d:\n\n", Arvore->numero);
            printf("    Nível do Nó: %d;\n", auxNivelNo);
            if(Pai == NULL){
                printf("    O nó é a Raiz da Árvore.\n");
            }
            else{
                printf("    Nó Pai: %d;\n", Pai->numero);
            }
            
            if(Pai != NULL && Irmao != NULL){
                printf("    Nó Irmão: %d.\n", Irmao->numero);
            }

            auxSV = 1;
            auxEncontradoDir = 1;
            auxEncontradoEsq = 1;
        }
        //Se o valorBusca for maior que o Nó atual(Arvore)
        else if(valorBusca > Arvore->numero){
            
            Pai = Arvore;
        
            if(Arvore->num_left != NULL){
                Irmao = Arvore->num_left;
            }
            else{
                Irmao = NULL;
            }
            
            if(Arvore->num_right != NULL){
                Arvore = Pai->num_right;
            }
            else{
                auxSV = 1;
                auxEncontradoDir = 0;
            }
        }
        //Se o valorBusca for menor que o Nó atual(Arvore)
        else if(valorBusca < Arvore->numero){
            
            Pai = Arvore;
            if(Arvore->num_right != NULL){   
                Irmao = Arvore->num_right;
            }
            else{
                Irmao = NULL;
            }
            
            if(Arvore->num_left != NULL){
                Arvore = Pai->num_left;
            }
            else{
                auxSV = 1;
                auxEncontradoEsq = 0;
            }
        }
    }
    //Caso o valorBusca não esteja presente na Árvore
    if(auxEncontradoEsq == 0 && auxEncontradoDir == 0){
        system("clear");
        printf("-------------------------------------------------\n");
        printf("              [4] - SearchValue\n");
        printf("-------------------------------------------------\n\n\n");

        printf("O valor %d não está presente na Árvore.", valorBusca);
    }
}

structArvore *removeValue(structArvore *Arvore, int valorRemover){

    structArvore *auxRV;

    if(Arvore == NULL){
        printf("\nO valor %d não está presente na Árvore.", valorRemover);
        return Arvore;
    }

   if(valorRemover > Arvore->numero){

        Arvore->num_right = removeValue(Arvore->num_right, valorRemover);
    }
    else if(valorRemover < Arvore->numero){
        
        Arvore->num_left = removeValue(Arvore->num_left, valorRemover);
    }

    else if(valorRemover == Arvore->numero){
        
        if(Arvore->num_left == NULL){
            
            printf("\n\nNúmero Removivo.");
            
            auxRV = Arvore->num_right;

            free(Arvore);

            return auxRV;
        }

        else if(Arvore->num_right == NULL){

            printf("\n\nNúmero Removivo.");
            
            auxRV = Arvore->num_left;
        
            free(Arvore);
            
            return auxRV;
        }
        
        structArvore *aux1 = Arvore->num_right;
    
        /* if(aux1 == NULL){
            structArvore *auxRV = NULL;
        } */

        int feito = 0;

        while(feito == 0){
            if(aux1->num_left == NULL){
                auxRV = aux1;
                feito = 1;
            }
            else{
                aux1 = aux1->num_left;
            }
        }
        
        Arvore->numero = auxRV->numero;
        Arvore->num_right = removeValue(Arvore->num_right, auxRV->numero);
    }

    return Arvore;
}

//_________________________________________//