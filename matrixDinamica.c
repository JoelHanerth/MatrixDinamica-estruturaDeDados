#include <stdio.h>
#include <stdlib.h>

typedef struct tipoCelula {
	int valor;
	char nome[30];
	struct tipoCelula *abaixo;
	struct tipoCelula *direito;
}TCelula;


TCelula *usuarios;
TCelula *relacionamentos;


void inicializaMatrix(TCelula **celula){
    *celula = NULL;
}

TCelula *alocarCelula(){
    TCelula *celula = (TCelula *)malloc(sizeof(TCelula));
    celula->abaixo = NULL;
    celula->direito = NULL;
    celula->valor = 0;
    return celula;
}



// void defineMatriz(TCelula **celula, int linha, int coluna){

//     int i, j;
//     TCelula *linhaAtual = NULL, *colunaAtual; 
//     if (*celula == NULL){ *celula = alocaCelula(); }

//     linhaAtual = *celula;

//     for (i=0; i < linha; i++){
//         colunaAtual = linhaAtual;

//         for (j = 1; j < coluna; j++){
//             if (colunaAtual->direito == NULL){ colunaAtual->direito = alocaCelula(); }
            
//             colunaAtual = colunaAtual->direito;
//         }

//         if (i < linha-1){
//             if (linhaAtual->abaixo == NULL){ linhaAtual->abaixo = alocaCelula();}
//             linhaAtual = linhaAtual->abaixo;
//         }
        
//     }
// }
void defineMatriz(TCelula **celula, int linha, int coluna) {
    int i, j;
    TCelula *linha_atual = NULL, *coluna_atual = NULL, *coluna_acima = NULL;

    if (*celula == NULL) {
        *celula = alocarCelula();
    }

    linha_atual = *celula;

    for (i = 0; i < linha; i++) {
        coluna_atual = linha_atual;
        for (j = 1; j < coluna ; j++) {
            
            if (coluna_atual->direito == NULL) {
                coluna_atual->direito = alocarCelula();
            }
            coluna_atual = coluna_atual->direito;

            if (coluna_acima != NULL) {
                coluna_acima->abaixo = coluna_atual;
                coluna_acima = coluna_acima->direito;             
            }

        }
        if (i < (linha - 1)) {
            if (linha_atual->abaixo == NULL) {
                linha_atual->abaixo = alocarCelula();
            }
        }
        coluna_acima = linha_atual->direito;
        linha_atual = linha_atual->abaixo;
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




//================================================================
int menu(){
	int opcao;
	system("CLS");
	printf("\n\n\n\t\t=====| MENU |======\n\n");
	printf("\t0 - Sair (Encerrar Aplicacao).\n");
	printf("\t1 - Inserir NOVO usuario.\n");
	printf("\t2 - Registrar amizade entre usuarios.\n");
	printf("\t3 - Indicar novas amizades para usuarios.\n\n");
	printf("\t\tInforme OPCAO desejada: ");
	scanf("%d", &opcao);
	
	if((opcao > 3) || (opcao < 0)){
		printf("\n\n\tERRO:\n\tOPCAO invalida. Tente novamente.\n\n");
		system("PAUSE");
	}//if
	
	return opcao;
}
//================================================================


//==| Programa Principal ===============================
int main(){
	int opcao;
	
	inicializaMatriz(&relacionamentos);
	inicializaMatriz(&usuarios);
	
	defineMatriz(&relacionamentos, 4, 4);
	defineMatriz(&usuarios,4,1);


	
	do{
		opcao = menu();
			
	}while(opcao != 0);

}




// int main(){
//     inicializaMatrix(&relacionamentos);
//     defineMatriz(&relacionamentos,3,3);

//     set_celula(relacionamentos,0,0,1);
//     set_celula(relacionamentos,1,0,2);
//     set_celula(relacionamentos,2,0,3);
//     set_celula(relacionamentos,1,2,4);
//     print_matriz(relacionamentos);

//     defineMatriz(&relacionamentos,5,5);

//     set_celula(relacionamentos,3,0,5);
//     set_celula(relacionamentos,3,3,6);
//     print_matriz(relacionamentos);

//     return 0;
// }