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
    //printLeituraArquivo(leitura);
    Menu(novaArvore);
}

//Menu
void Menu(structArvore *novaArvore){

    system("clear");
    printf("-------------------------------------------------\n");
    printf("                 MENU PRINCIPAL\n");
    printf("-------------------------------------------------\n");
    printf("\nEscolha o que deseja fazer:\n\n");
    printf("[1] - Carregar uma nova árvore dos arquivos\n");
    printf("[2] - Imprimir a árvore\n");
    printf("[3] - Verificar se a árvore está cheia\n");
    printf("[4] - Buscar valor na árvore\n");
    printf("[5] - Imprimir a altura da árvore\n");
    printf("[6] - Remover um valor da árvore\n");
    printf("[7] - Imprimir os valores da árvore em ordem\n");
    printf("[8] - Imprimir os valores da árvore em pré-ordem\n");
    printf("[9] - Imprimir os valores da árvore em pós-ordem\n");
    printf("[10] - Balancear a árvore\n");
    printf("[11]- Sair\n");
    printf("-------------------------------------------------\n");
    
    menuOpcoes(novaArvore);
}

void menuOpcoes(structArvore *novaArvore){
    
    //Escolha de uma das opções do Menu
    int escolhaMenu;
    scanf("%d", &escolhaMenu);
    while(escolhaMenu != 1 && escolhaMenu != 2 && escolhaMenu != 3 && escolhaMenu != 4 && escolhaMenu != 5 && escolhaMenu != 6 && escolhaMenu != 7 && escolhaMenu != 8 && escolhaMenu != 9 && escolhaMenu != 10 && escolhaMenu != 11){
       printf("Digite Novamente:"); 
       scanf("%d", &escolhaMenu);
    }

    if(escolhaMenu == 1){
        showTree(novaArvore);
    }
    else if(escolhaMenu == 2){
        showTree(novaArvore);
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 3){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 4){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 5){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 6){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 7){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 8){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 9){
        menuBack(novaArvore);
    }
    else if(escolhaMenu == 10){
        startMenu(novaArvore);
    }
    else if(escolhaMenu == 11){
        printf("-------------------------------------------------\n");
        printf("\n\t\t   Obrigado!!\n\n");
        printf("-------------------------------------------------\n");
        exit(0);
    }
}

void menuBack(structArvore *novaArvore){
    getchar();
    printf("\n-------------------------------------------------");
    printf("\nAperte QUALQUER BOTÃO para voltar ao Menu Principal\n");
    getchar();

    menuOpcoes(novaArvore);
}
