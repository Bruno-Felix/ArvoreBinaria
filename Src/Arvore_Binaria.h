#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#define file1 "../BSTs/bst1.txt"
#define file2 "../BSTs/bst2.txt"
#define file3 "../BSTs/bst3.txt"
#define file4 "../BSTs/bst4.txt"
#define file5 "../BSTs/bst5.txt"
#define file6 "../BSTs/bst6.txt"

//Árvore
typedef struct proj5ArvoreBinaria{
    //Valor do Nó
    int numero;

    //Nó a Esquerda(num_left) e Nó a Direita(num_right)
    struct proj5ArvoreBinaria *num_left;
    struct proj5ArvoreBinaria *num_right;
}structArvore;

//MENU_____________________________________//
void startMenu();
void menu(structArvore *);
void menuOpcoes(structArvore *);
void menuBack();


//Auxiliar_________________________________//
char **criarMatriz(int );
int salvaMatrizShow(structArvore *, char **, int , int , int );
void printaMatriz(char **, int , int );


//FUNÇÕES_COM__A_ÁRVORE________________________//
structArvore *loadTreeFromFile(char[25]);//FEITO
void showTree(structArvore *);//FEITO
int isFull(structArvore *);//FEITO
void searchValue(structArvore *, int );//FEITO
int getHeight(structArvore *);//FEITO
structArvore *removeValue(structArvore *, int);//FEITO
void printInOrder(structArvore *);//FEITO
void printPreOrder(structArvore *);//FEITO
void printPosOrder(structArvore *);//FEITO
structArvore *balanceTree(structArvore *);

//TOTAL DE PONTOS = 9
//_________________________________________//
#endif