#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Arvore_Binaria.h"


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
    if(raiz == NULL){
        printf("Erro na alocação de memoria da Raiz(loadTreeFromFile)\n");
        exit(0);
    }
    char aux;

    fscanf(leitura, "%d%c", &raiz->numero, &aux);

    raiz->num_left = NULL;
    raiz->num_right = NULL;


    structArvore *noAntigo;
    structArvore *novoNumero;
    //Inserção dos Demais nós
    while(!feof(leitura)){
        
        novoNumero = (structArvore*)(malloc(sizeof(structArvore)));


        fscanf(leitura, "%d%c", &novoNumero->numero, &aux);
        if(novoNumero == NULL){
            printf("Erro na alocação de memoria da novoNumero(loadTreeFromFile)\n");
            exit(0);
        }
        
        novoNumero->num_left = NULL;
        novoNumero->num_right = NULL;

        int auxAv = 0;
        noAntigo = raiz;

        //Alocando no Seu devido Lugar da Árvore
        while(auxAv == 0){
            //Se o novo_nomero for maior que a raiz
            if(novoNumero->numero > noAntigo->numero){
                //Se o noAntigo for a Raiz
                if(noAntigo->num_right == NULL){
                    
                    noAntigo->num_right = novoNumero;

                    auxAv = 1;
                 }
                else{
                    noAntigo = noAntigo->num_right;
                }
            }
            //Se o novo_nomero for menor que a raiz
            else{
                //Se o noAntigo for a Raiz
                if(noAntigo->num_left == NULL){

                    noAntigo->num_left = novoNumero;

                    auxAv = 1;
                }
                else{
                    noAntigo = noAntigo->num_left;
                }
            }
        }
    }

    //Retorno do endereço da raiz da árvore
    return raiz;
}


//ShowTree
void showTree(structArvore *Arvore){
    int nivel = 0;
    //Busca a altura e multiplica por 2
    int alturaArvore = (getHeight(Arvore)*2) + 1;
    char **matrizArvore = criarMatriz(alturaArvore);

    salvaMatrizShow(Arvore, matrizArvore, 0, 0, 0);
    printaMatriz(matrizArvore, alturaArvore, nivel);
}

char **criarMatriz(int alturaArvore){
    
    //Cria a matrizArvore
    char **matrizArvore = (char **)malloc(alturaArvore*sizeof(char *));
    if(matrizArvore == NULL){
        printf("erro alocacao matrizArvore\n");
        exit(0);
    }

    for (int i = 0; i < alturaArvore; i++) {
        
        //Cria as linhas da matrizArvore
        matrizArvore[i] = (char *)malloc(150 * sizeof(char));
        if(matrizArvore[i] == NULL){
            printf("erro alocacao matrizArvore[i]\n");
            exit(0);
        }
        //Preenche as matriz com espaços
        sprintf(matrizArvore[i], "%100s", "");
    }
  
    return matrizArvore;
}

int salvaMatrizShow(structArvore *raiz, char **matrizArvore, int dirEsquerda, int desloc, int nivel) {

    int largura = 5;
    char auxVetorNos[10];
    
    //Se o nó apontado para a esquerda ou direita for NULL, ou seja, a folha
    if(raiz == NULL){
        return 0;
    }
    //Preenche um vetor com todos os auxVetorNos que passarem na recursividade
    sprintf(auxVetorNos, " %3d ", raiz->numero);
    
    //Inicia a recursividade pela esquerda, buscando nós pela esquerda até a folha
    int esquerda  = salvaMatrizShow(raiz->num_left, matrizArvore, 1, desloc, nivel + 1);
    
    //Depos de finalizar a recursividade pela esquerda, busca nós direita até a folha
    int direita = salvaMatrizShow(raiz->num_right, matrizArvore, 0, (desloc + esquerda + largura), (nivel + 1));
    
    //Quando as duas recursividades serem feitas, o nó será nulo
    //Então se inicia o preechimente da matrizArvore com os nós gravados no vetor auxVetorNos:
    for (int i = 0; i < largura; i++){
       
        matrizArvore[(2*nivel)][(desloc + esquerda + i)] = auxVetorNos[i];
    }

    return esquerda + largura + direita;
}

void printaMatriz(char **matrizArvore, int altura, int nivel){

    //Recebe matrizArvore e inicia uma matriz por for printando os dados da matriz
    // " " para espaços e "c" para nós

    for (int i = 0; i < altura; i++) {

        if(i%2 == 0){
            printf("Nível %d: ", 1 + (nivel + i)/2);
        }
        for(int j = 0; j < 100; j++){
            printf("%c", matrizArvore[i][j]);
        }
        //A cada linha, um "\n"
        printf("\n");
    }
}


//IsFull
int isFull(structArvore *Arvore){

    //Se a Árvore é vazia
    if (Arvore == NULL){
        return 0;
    }

    //Caso ideal de achar a folha
    if ((Arvore->num_left == NULL) && (Arvore->num_right == NULL)){
		return 1;
    } 

    //Percorrendo a Árvore em busca das folhas
    else if (Arvore->num_left != NULL && Arvore->num_right != NULL){
		 if (isFull(Arvore->num_left) == 1 && isFull(Arvore->num_right) == 1){
            return 1;
        }
    }
    //Caso todos os nós não satisfaça o Critério da Árvore Cheia
    return 0;
}


//Print In/Pos/Pre Order
void printInOrder(structArvore *Arvore){
    
    if(Arvore != NULL){
        //Começa a Recursividade pela Esquerda, Caso chegue em NULL, printa o nó pai, no caso a folha pela esquerda:
        printInOrder(Arvore->num_left);
        
        //Caso um nó seja printado acima, printa o nó pai e até mesmo a Raiz:
        printf(" %d", Arvore->numero);

        //Caso o nó pai seja printado, inicia a recursividade pela direita do nó até chegar em NULL,
        //assim printando o nó pai , finalizando a recursividade
        printInOrder(Arvore->num_right);
    }
}
void printPreOrder(structArvore *Arvore){
 
    if(Arvore != NULL){
        //Inicia printando o nó atual, no caso um nó pai e até mesmo a Raiz:
        printf(" %d", Arvore->numero);

        //Após o pai ser printado, inicia a recursividade pela esquerda eté NULL 
        //printando o nó pai, no caso a folha pela esquerda:
        printPreOrder(Arvore->num_left);
        //Após a recursividade pela esquerda encerrar, inicia a recursividade pela direita:
        printPreOrder(Arvore->num_right);
    }
}
void printPosOrder(structArvore *Arvore){
 
    if(Arvore != NULL){
        //Começa a Recursividade pela Esquerda, Caso chegue em NULL, printa o nó pai, no caso a folha pela esquerda:
        printPosOrder(Arvore->num_left);
        //Após a recursividade pela esquerda encerrar, inicia a recursividade pela direita:
        printPosOrder(Arvore->num_right);

        //Após printar  a esquerda e a direita, printa o nó pai e até mesmo a Raiz:
        printf(" %d", Arvore->numero);
    }
}


//GetHeight
int getHeight(structArvore *Arvore){

    int aux = 0;
    //Caso a nó seja NULL ou o nó seja o folha
    if((Arvore == NULL) || (Arvore->num_left == NULL && Arvore->num_right == NULL)){
        return 0;
    }
    
    else{
        //Se a Altura pela direita da raiz seja maior Altura pela esquerda da raiz
        if(getHeight(Arvore->num_right) > getHeight(Arvore->num_left)){
            //Pega para uso a Altura pela direita
            aux = getHeight(Arvore->num_right);
        }
        //Caso contŕario
        else{
            //Pega para uso a Altura pela esquerda
            aux = getHeight(Arvore->num_left);
        }

        return 1 + aux;
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
        printf("\nO valor %d não está presente na Árvore.", valorBusca);
    }
}


//removeValue
structArvore *removeValue(structArvore *Arvore, int valorRemover){

    structArvore *auxRV;

    if(Arvore == NULL){
        printf("\nO valor %d não está presente na Árvore.", valorRemover);
        return Arvore;
    }

    //Caso o valorRemover seja maior que o nó, busca pela direita
    if(valorRemover > Arvore->numero){

        Arvore->num_right = removeValue(Arvore->num_right, valorRemover);
    }
    //Caso o valorRemover seja menor que o nó, busca pela esquerda
    else if(valorRemover < Arvore->numero){
        
        Arvore->num_left = removeValue(Arvore->num_left, valorRemover);
    }

    //Caso o valorRemover seja igual ao nó
    else if(valorRemover == Arvore->numero){
        //Caso o nó não tenha filho pela esquerda ou seja a folha
        if(Arvore->num_left == NULL){
            
            printf("\nNúmero Removivo.");
            
            auxRV = Arvore->num_right;

            free(Arvore);

            return auxRV;
        }
        //Caso o nó não tenha filho pela direita ou seja a folha
        else if(Arvore->num_right == NULL){

            printf("\n\nNúmero Removivo.");
            
            auxRV = Arvore->num_left;
        
            free(Arvore);
            
            return auxRV;
        }

        //Buscar que as condições acima sejam aceitas, 
        //buscando substituir o no pai(caso seja o removido) pelo nó filho da direita
        structArvore *aux1 = Arvore->num_right;

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

//Função não finalizada
//Someste se a Árvore for balanceada
structArvore *balanceTree(structArvore *Arvore){
    
    /* int alturaDireita = getHeight(Arvore->num_right);
    int alturaEsquerda = getHeight(Arvore->num_left);

    printf("E %d\n", alturaEsquerda);
    printf("D %d\n", alturaDireita);
    int diferenca = alturaDireita - alturaEsquerda;
    printf("diferença: %d\n", diferenca);

    if((alturaDireita >= alturaEsquerda) && (diferenca == 1 || diferenca == 0)){
        printf("Árvore já é balanceada.");
        
        return Arvore;
    }
    else if((alturaEsquerda > alturaDireita) && (diferenca == 1 || diferenca == 0)){
        printf("Árvore já é balanceada.");

        return Arvore;
    }
    else{

    } */
}

//_____________________________________________//