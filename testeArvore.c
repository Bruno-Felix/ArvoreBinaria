#include <stdio.h>
#include <stdlib.h>
#define file1 "BSTs/bst1.txt"
#define file2 "BSTs/bst2.txt"
#define file3 "BSTs/bst3.txt"
#define file4 "BSTs/bst4.txt"
#define file5 "BSTs/bst5.txt"
#define file6 "BSTs/bst6.txt"

//Árvore
typedef struct proj5ArvoreBinaria{
    int element;
    int *num_left;
    int *num_right;
}structArvore;

//Menu
void starMenu();
void Menu();
void menuOpcoes();

//Ações com a Árvore:
structArvore *criandoNovaArvore(FILE *);

//Leitura do Arquivo:
int escolhendoArquivo();
FILE *leituraArquivo();
void printLeituraArquivo(FILE *leitura);

//__________________________
//MAIN
int main(){
    //Craindo a Arvore
    structArvore *Arvore = NULL;
    //Inicializando Programa
    starMenu();

    return 0;
}
//__________________________


//Escolha do arquivo de Leitura
int escolhendoArquivo(){
    
    int escolha = 0;

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

    return escolha;
}

//Leitura do arquivo
FILE *leituraArquivo(){
    //Escolha do arquivo de leitura
    int escolha = escolhendoArquivo();

    FILE *leitura;
    
    if(escolha == 1){

        leitura = fopen(file1, "r");
        
        if(leitura == NULL){
            printf("\n\nError: Fail to open File1!\n\n");
        }
        else{printf("Abriu o 1!\n");}
    }
    else if(escolha == 2){

        leitura = fopen(file2, "r");
        
        if(leitura == NULL){
            printf("\n\nError: Fail to open File1!\n\n");
        }
        else{printf("Abriu o 2!\n");}
    }
    else if(escolha == 3){

        leitura = fopen(file3, "r");
        
        if(leitura == NULL){
            printf("\n\nError: Fail to open File1!\n\n");
        }
        else{printf("Abriu o 3!\n");}
    }
    else if(escolha == 4){

        leitura = fopen(file4, "r");
        
        if(leitura == NULL){
            printf("\n\nError: Fail to open File1!\n\n");
        }
        else{printf("Abriu o 4!\n");}
    }
    else if(escolha == 5){

        leitura = fopen(file5, "r");
        
        if(leitura == NULL){
            printf("\n\nError: Fail to open File1!\n\n");
        }
        else{printf("Abriu o 5!\n");}
    }
    else if(escolha == 6){

        leitura = fopen(file6, "r");
        
        if(leitura == NULL){
            printf("\n\nError: Fail to open File1!\n\n");
        }
        else{printf("Abriu o 6!\n");}
    }

    return leitura;
}

void printLeituraArquivo(FILE *leitura){
    int num1;	
    int num2;	
    int num3;	
    int num4;	
    int num5;	
    int num6;	
    int num7;	
    int num8;	
    int num9;	
    int num10;	
     	
    while(!feof(leitura)){	
        fscanf(leitura, "%d", &num1);	
        fscanf(leitura, "%d", &num2);	
        fscanf(leitura, "%d", &num3);	
        fscanf(leitura, "%d", &num4);	
        fscanf(leitura, "%d", &num5);	
        fscanf(leitura, "%d", &num6);	
        fscanf(leitura, "%d", &num7);	
        fscanf(leitura, "%d", &num8);	
        fscanf(leitura, "%d", &num9);	
        fscanf(leitura, "%d", &num10);	
    }	
    fclose(leitura);	
     printf("num1: %d\nnum2: %d\nnum3: %d\nnum4: %d\nnum5: %d\nnum6: %d\nnum7: %d\nnum8: %d\nnum9: %d\nnum10: %d\n", num1, num2, num3, num4, num5, num6, num7, num8, num9, num10);
}

structArvore *criandoNovaArvore(FILE *leitura){

}


void starMenu(){
    structArvore *novaArvore;
    FILE *leitura = leituraArquivo();
    //printLeituraArquivo(leitura);
    Menu();
}

//Menu
void Menu(){

    system("clear");
    printf("-------------------------------------------------\n");
    printf("                 MENU PRINCIPAL\n");
    printf("-------------------------------------------------\n");
    printf("\nEscolha o que deseja fazer:\n\n");
    printf("[1] - Imprimir a árvore\n");
    printf("[2] - Verificar se a árvore está cheia\n");
    printf("[3] - Buscar valor na árvore\n");
    printf("[4] - Imprimir a altura da árvore\n");
    printf("[5] - Remover um valor da árvore\n");
    printf("[6] - Imprimir os valores da árvore em ordem\n");
    printf("[7] - Imprimir os valores da árvore em pré-ordem\n");
    printf("[8] - Imprimir os valores da árvore em pós-ordem\n");
    printf("[9] - Balancear a árvore\n");
    printf("[10]- Carregar uma nova árvore dos arquivos\n");
    printf("[11]- Sair\n");
    printf("-------------------------------------------------\n");
    menuOpcoes();
}

void menuOpcoes(){
    
    //Escolha de uma das opções do Menu
    int escolhaMenu;
    scanf("%d", &escolhaMenu);
    while(escolhaMenu != 1 && escolhaMenu != 2 && escolhaMenu != 3 && escolhaMenu != 4 && escolhaMenu != 5 && escolhaMenu != 6 && escolhaMenu != 7 && escolhaMenu != 8 && escolhaMenu != 9 && escolhaMenu != 10 && escolhaMenu != 11){
       printf("Digite Novamente:"); 
       scanf("%d", &escolhaMenu);
    }

    if(escolhaMenu == 1){}
    else if(escolhaMenu == 2){}
    else if(escolhaMenu == 3){}
    else if(escolhaMenu == 4){}
    else if(escolhaMenu == 5){}
    else if(escolhaMenu == 6){}
    else if(escolhaMenu == 7){}
    else if(escolhaMenu == 8){}
    else if(escolhaMenu == 9){}
    else if(escolhaMenu == 10){
        starMenu();
    }
    else if(escolhaMenu == 11){
        printf("-------------------------------------------------\n");
        printf("\n\t\t   Obrigado!!\n\n");
        printf("-------------------------------------------------\n");
        exit(0);
    }
}

void menuBack(){
    getchar();
    printf("-------------------------------------------------");
    printf("\nAperte QUALQUER BOTÃO para voltar ao Menu Principal\n");
    getchar();

    menuOpcoes();
}
