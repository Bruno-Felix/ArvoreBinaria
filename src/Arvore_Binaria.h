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
    int numero;
    int altura;
    struct proj5ArvoreBinaria *num_left;
    struct proj5ArvoreBinaria *num_right;
}structArvore;

//MENU_____________________________________//
void startMenu();
void Menu(structArvore *);
void menuOpcoes(structArvore *);
void menuBack();


//Auxiliar_________________________________//
int maior(int , int );


//AÇÕES COM ARVORES________________________//

structArvore *loadTreeFromFile(char[25]);
void showTree(structArvore *);
void isFull(structArvore *);
void searchValue(structArvore *);
int getHeight(structArvore *);
structArvore removeValue(structArvore *);
void printInOrder(structArvore *);
void printPreOrder(structArvore *);
void printPosOrder(structArvore *);
structArvore balanceTree(structArvore *);

//_________________________________________//
#endif