/*
Integrantes do projeto: Joel Hanerth e Lucas Zanetti Zanotelli
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct tipoCelula {
	int valor;
	char nome[30];
	struct tipoCelula *abaixo;
	struct tipoCelula *direito;
}TCelula;


TCelula *usuarios;
TCelula *relacionamentos;


void inicializaMatriz(TCelula **celula){
    *celula = NULL;
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

void SugerirAmizades(TCelula *usuarios, TCelula *relacionamentos, int quant_usuarios) {
    int i, j, k;
    TCelula *user_i, *user_j, *user_k, *user_kj;

    for (i = 0; i < quant_usuarios; i++) {
        user_i = get_celula(usuarios, i, 0);
        printf("\nSugestões de amizade para %s:\n", user_i->nome);
        int encontrouSugestao = 0; 

        for (j = 0; j < quant_usuarios; j++) {
            if (i == j) continue; 

            user_j = get_celula(relacionamentos, i, j);
            if (user_j->valor == 0) {  // Se não forem amigos ainda
                int amigos_em_comum = 0;

                for (k = 0; k < quant_usuarios; k++) {
                    if (k != i && k != j) {
                        user_k = get_celula(relacionamentos, i, k);
                        user_kj = get_celula(relacionamentos, k, j);

                        if (user_k->valor == 1 && user_kj->valor == 1) {
                            amigos_em_comum++;
                        }
                    }
                }

                if (amigos_em_comum >= 2) {
                    TCelula *user_sugestao = get_celula(usuarios, j, 0);
                    printf("  - %s (amigos em comum: %d)\n", user_sugestao->nome, amigos_em_comum);
                    encontrouSugestao = 1;
                }
            }
        }

        if (!encontrouSugestao) {
            printf("  Nenhuma sugestão disponível.\n");
        }
    }
}




TCelula *alocarCelula(){
    TCelula *celula = (TCelula *)malloc(sizeof(TCelula));
    celula->abaixo = NULL;
    celula->direito = NULL;
    celula->valor = 0;
    celula->nome[0] = 0;
    return celula;
}


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



void set_int(TCelula *celula, int linha, int coluna, int valor){
    TCelula *celula_atual = get_celula (celula, linha, coluna);
    celula_atual->valor = valor;
}

void set_str(TCelula *celula, int linha, int coluna, char nome[30]){
    TCelula *celula_atual = get_celula (celula, linha, coluna);
    strcpy(celula_atual->nome, nome);
}

void InserirUsuario (TCelula *usuarios, TCelula *relacionamentos, int *quant){
    char nome [30];

    printf("Insira o nome de usuário: ");
    scanf(" %29[^\n]s", nome);

    (*quant)++;

    defineMatriz(&usuarios,*quant,1);
    set_str(usuarios,(*quant)-1,0,nome);
    defineMatriz(&relacionamentos,*quant,*quant);  

}


void get_nomes(TCelula *celula) {
    TCelula *celula_atual = celula;
    int i;

    for (i=1; celula_atual != NULL; i++){;
        printf("%d - %s \n", i,celula_atual->nome);
        celula_atual = celula_atual->abaixo;
    }
}


void print_matriz(TCelula *celula) {
    TCelula *linha_atual = celula, *coluna_atual = celula;
    while (linha_atual != NULL) {
        coluna_atual = linha_atual;
        while (coluna_atual != NULL) {
            printf("%s ", coluna_atual->nome);
            printf("%d ", coluna_atual->valor);
            coluna_atual = coluna_atual->direito;
        }
        printf("\n");
        linha_atual = linha_atual->abaixo;
    }
}


void InserirRelacionamentos(TCelula *usuarios, TCelula *relacionamentos, int *quant) {
    int num1, num2;     

    get_nomes(usuarios);
    
    printf("Insira número do primeiro usuário para relacionamento: ");
    scanf("%d", &num1);
    while (num1 <= 0 || num1 > *quant) {
        printf("Número inválido. Insira novamente: ");
        scanf("%d", &num1);
    }
    
    printf("Insira número do segundo usuário para relacionamento: ");
    scanf("%d", &num2);
    while (num2 <= 0 || num2 > *quant || num2 == num1) {
        printf("Número inválido. Insira novamente: ");
        scanf("%d", &num2);
    }

    set_int(relacionamentos,num1-1,num2-1,1);
    set_int(relacionamentos,num2-1,num1-1,1);

}



//================================================================
int menu(){
	int opcao;
	// system("CLS");
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
    SetConsoleOutputCP(65001);
	int opcao;
    int quant_usuarios = 4;
	
	inicializaMatriz(&relacionamentos);
	inicializaMatriz(&usuarios);
	
	defineMatriz(&relacionamentos, 4, 4);
	defineMatriz(&usuarios,4,1);
    set_str(usuarios,0,0,"Anna");
    set_str(usuarios,1,0,"Beatriz");
    set_str(usuarios,2,0,"Carlos");
    set_str(usuarios,3,0,"Daniel");



	do{
        get_nomes(usuarios);
        printf("\n");
        print_matriz(relacionamentos);
        opcao = menu();
        switch (opcao) {
            case 0:
                break;
            case 1:
                InserirUsuario(usuarios,relacionamentos,&quant_usuarios);

                break;
            case 2:
                InserirRelacionamentos(usuarios,relacionamentos, &quant_usuarios);
            
                break;
            case 3:
                SugerirAmizades(usuarios, relacionamentos, quant_usuarios);
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);			

    return 0;
}


