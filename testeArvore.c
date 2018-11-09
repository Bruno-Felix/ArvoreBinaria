#include <stdio.h>
#include <stdlib.h>
#define file1 "BSTs/bst1.txt"
#define file2 "BSTs/bst2.txt"
#define file3 "BSTs/bst3.txt"
#define file4 "BSTs/bst4.txt"
#define file5 "BSTs/bst5.txt"
#define file6 "BSTs/bst6.txt"


typedef struct Test_Avr{
    int num;
    int *num_left;
    int *num_right;
}num_no;

//Ações com a Árvore:
num_no *create_List();

//Leitura do Arquivo:
int escolha_Arquivo();
FILE *leitura_Arquivo();


int main(){
    //Craindo da Arvore
    num_no *lista = create_List();

    FILE *file = leitura_Arquivo();

    return 0;
}

//Criação da Árvore
num_no *create_List(){
    
    return NULL;
}

//Escolha do arquivo de Leitura
int escolha_Arquivo(){
    
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

FILE *leitura_Arquivo(){
    //Escolha do arquivo de leitura
    int escolha = escolha_Arquivo();

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

    return leitura;
}