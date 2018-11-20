#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Arvore_Binaria.h"

//MAIN_____________________________________//
int main(){
    //Craindo a Arvore
    structArvore *Arvore = NULL;
    //Inicializando Programa
    startMenu();

    return 0;
}
//_________________________________________//


//MENU_____________________________________//

//Inicio do programa
void startMenu(){

    int escolha = 0;
    structArvore *novaArvore;

    system("clear");
    printf("-------------------------------------------------\n");
    printf("               ESCOLHA DO ARQUIVO\n");
    printf("-------------------------------------------------\n");
    printf("\nEscolha o arquivo a ser usado no programa:\n\n");
    printf("[1] - bst1.txt;\n");
    printf("[2] - bst2.txt;\n");
    printf("[3] - bst3.txt;\n");
    printf("[4] - bst4.txt;\n");
    printf("[5] - bst5.txt;\n");
    printf("[6] - bst6.txt;\n");
    printf("-------------------\n");
    printf("Digite sua escolha:");
    
    scanf("%d", &escolha);

    while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != 5 && escolha != 6){
       printf("Digite Novamente:"); 
       scanf("%d", &escolha);
    }
    
    if(escolha == 1){
        novaArvore = loadTreeFromFile(file1);
    }
    else if(escolha == 2){
        novaArvore = loadTreeFromFile(file2);
    }
    else if(escolha == 3){
        novaArvore = loadTreeFromFile(file3);  
    }
    else if(escolha == 4){
        novaArvore = loadTreeFromFile(file4);
    }
    else if(escolha == 5){
        novaArvore = loadTreeFromFile(file5);
    }
    else if(escolha == 6){
        novaArvore = loadTreeFromFile(file6);
    }
    
    menu(novaArvore);
}

//Menu
void menu(structArvore *raiz){

    system("clear");
    printf("-------------------------------------------------\n");
    printf("                      MENU\n");
    printf("-------------------------------------------------\n");
    printf("\nEscolha uma das Funções:\n\n");
    printf("[1] - LoadTreeFromFile;\n\n");
    printf("[2] - ShowTree:\n\n");
    printf("[3] - IsFull;\n\n");
    printf("[4] - SearchValue;\n\n");
    printf("[5] - GetHeight;\n\n");
    printf("[6] - RemoveValue;\n\n");
    printf("[7] - PrintInOrder;\n\n");
    printf("[8] - PrintPreOrder;\n\n");
    printf("[9] - PrintPostOrder;\n\n");
    printf("[10]- BalanceTree;\n");
    printf("-------------------------------------------------\n");
    printf("[11]- Sair\n");
    printf("-------------------------------------------------\n");
    
    menuOpcoes(raiz);
}
//Funções do Menu
void menuOpcoes(structArvore *raiz){
    
    //Escolha de uma das opções do Menu
    int escolhaMenu;
    printf("Escolha: ");
    scanf("%d", &escolhaMenu);
    while(escolhaMenu != 1 && escolhaMenu != 2 && escolhaMenu != 3 && escolhaMenu != 4 && escolhaMenu != 5 && escolhaMenu != 6 && escolhaMenu != 7 && escolhaMenu != 8 && escolhaMenu != 9 && escolhaMenu != 10 && escolhaMenu != 11){
       printf("Digite Novamente:"); 
       scanf("%d", &escolhaMenu);
    }

    if(escolhaMenu == 1){
        startMenu(raiz);
    }
    else if(escolhaMenu == 2){
        menuBack(raiz);
    }
    else if(escolhaMenu == 3){
        menuBack(raiz);
    }
    else if(escolhaMenu == 4){
        system("clear");
        printf("-------------------------------------------------\n");
        printf("              [4] - SearchValue\n");
        printf("-------------------------------------------------\n\n\n");
        
        int valorBusca;
        printf("Digite o Número de Busca: ");
        scanf("%d", &valorBusca);
        searchValue(raiz, valorBusca);
        
        menuBack(raiz);
    }
    else if(escolhaMenu == 5){

        system("clear");
        printf("-------------------------------------------------\n");
        printf("              [5] - GetHeight\n");
        printf("-------------------------------------------------\n\n\n");
        
        int altura = getHeight(raiz);
        printf("getHeight: %d", 1 + altura);
        
        menuBack(raiz);
    }
    else if(escolhaMenu == 6){
        system("clear");
        printf("-------------------------------------------------\n");
        printf("              [6] - RemoveValue\n");
        printf("-------------------------------------------------\n\n\n");
        
        int valorRemover;
        printf("Digite um Número para Remover: ");
        scanf("%d", &valorRemover);

        raiz = removeValue(raiz, valorRemover);

        menuBack(raiz);
    }
    else if(escolhaMenu == 7){
        
        system("clear");
        printf("-------------------------------------------------\n");
        printf("             [7] - PrintInOrder\n");
        printf("-------------------------------------------------\n\n\n");
        
        printf("InOrder: ");
        printInOrder(raiz);
        
        menuBack(raiz);
    }
    else if(escolhaMenu == 8){
        
        system("clear");
        printf("-------------------------------------------------\n");
        printf("             [8] - PrintPreOrder\n");
        printf("-------------------------------------------------\n\n\n");
        
        printf("PreOrder: ");
        printPreOrder(raiz);
        
        menuBack(raiz);
    }
    else if(escolhaMenu == 9){
        
        system("clear");
        printf("-------------------------------------------------\n");
        printf("             [9] - PrintPosOrder\n");
        printf("-------------------------------------------------\n\n\n");
        
        printf("PosOrder: ");
        printPosOrder(raiz);
        
        menuBack(raiz);
    }
    else if(escolhaMenu == 10){

        system("clear");
        printf("-------------------------------------------------\n");
        printf("             [10] - BalanceTree\n");
        printf("-------------------------------------------------\n\n\n");

        raiz = balanceTree(raiz);
        
        menuBack(raiz);
    }
    else if(escolhaMenu == 11){
        system("clear");
        printf("\n\n-------------------------------------------------\n\n");
        printf("                  Obrigado!!\n\n");
        printf("-------------------------------------------------\n\n\n");
        
        exit(0);
    }
}

void menuBack(structArvore *raiz){
    getchar();
    printf("\n\n\n-------------------------------------------------");
    printf("\nAperte QUALQUER BOTÃO para voltar ao Menu Principal\n");
    getchar();

    menu(raiz);
}
