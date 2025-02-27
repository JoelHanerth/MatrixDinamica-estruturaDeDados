#include <stdio.h>
#include <stdlib.h>

typedef struct tipoCelula
{
    int valor;
    struct tipoCelula *abaixo;
    struct tipoCelula *direito;
} TCelula;


TCelula *matriz;


void inicializaMatrix(TCelula **celula){
    *celula = NULL;
}

TCelula *alocaCelula(){
    TCelula *celula = (TCelula *)malloc(sizeof(TCelula));
    celula->abaixo = NULL;
    celula->direito = NULL;
    celula->valor = 0;
    return celula;
}



void defineMatriz(TCelula **celula, int linha, int coluna){

    int i, j;
    TCelula *linhaAtual = NULL, *colunaAtual; 
    if (*celula == NULL){ *celula = alocaCelula(); }

    linhaAtual = *celula;

    for (i=0; i < linha; i++){
        colunaAtual = linhaAtual;

        for (j = 1; j < coluna; j++){
            if (colunaAtual->direito == NULL){ colunaAtual->direito = alocaCelula(); }
            
            colunaAtual = colunaAtual->direito;
        }

        if (i < linha-1){
            if (linhaAtual->abaixo == NULL){ linhaAtual->abaixo = alocaCelula();}
            linhaAtual = linhaAtual->abaixo;
        }
        
    }
}



TCelula *get_celula(TCelula *celula, int linha, int coluna){
    int i, j;

    for (i=0; i< linha; i++){
        celula = celula->abaixo;
    }
    for (j=0; j< coluna; j++){
        celula = celula->direito;
    }
    return celula;
}

void set_celula(TCelula *celula, int linha, int coluna, int valor){
    TCelula *celula_atual = get_celula (celula, linha, coluna);
    celula_atual->valor = valor;
}

void print_matriz(TCelula *celula) {
    TCelula *linha_atual = celula, *coluna_atual = celula;
    while (linha_atual != NULL) {
        coluna_atual = linha_atual;
        while (coluna_atual != NULL) {
            printf("%d ", coluna_atual->valor);
            coluna_atual = coluna_atual->direito;
        }
        printf("\n");
        linha_atual = linha_atual->abaixo;
    }
}


int main(){
    int op;
    inicializaMatrix(&matriz);
    defineMatriz(&matriz,3,3);

    set_celula(matriz,0,0,1);
    set_celula(matriz,1,0,2);
    set_celula(matriz,2,0,3);
    set_celula(matriz,1,2,4);
    print_matriz(matriz);

    defineMatriz(&matriz,5,5);

    set_celula(matriz,3,0,5);
    set_celula(matriz,3,3,6);
    print_matriz(matriz);

    do {
        op = menu();
        switch (op) {
            case 0:
                break;
            case 1:
  
                break;
            case 2:
            
                break;
            case 3:
              
                break;
            case 4:
             
                break;
            case 5:
           
                break;
            case 6:
         
                break;
            case 7:

                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (op != 0);

    return 0;

    return 0;
}
