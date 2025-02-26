/*
   Simulação de uma rede social onde os usuarios podem ser registrar
   livremente e estabelecer relacionamentos de amizades uns com os 
   outros.
   
   Os usuários tem seus nomes armazenados em um vetor unidimensional.
   
   Os relacionamentos são registrados em uma matriz de adjacências 
   (como um grafo).
   
   Assim, por exemplo, um usuário de nome "Asdrúbal" é registrado na
   posição 0 do vetor usuarios. "Jambira" é registrada na posição 1 
   do mesmo vetor.
   
   A relação de amizade entre ambos é representada por um valor 1 na
   matriz relacionamentos (linha 0 e coluna 1) e também por um valor
   1 na linha 1 e coluna 0.
   
   Afinal, se Asdrúbal é amigo de Jambira também é verdade que Jambira
   é igualmente amiga de Asdrúbal.
   
   Usuário inicialmente é um vetor de 4 posições e relacionamentos é uma
   matriz 4 X 4.
   
   Caso seja necessário cadastrar um quinto usuário, tanto o vetor quanto 
   a matriz deverão ser ampliados dinâmicamente. O vetor usuário possuirá
   5 posições e a matriz relacionamentos será de dimensão 5 x 5.
   
   20-02-2025 (quarta-feira).
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];

typedef struct tipoCelula {
	int valor;
	string nome;
	tipoCelula *abaixo;
	tipoCelula *dir;
}TCelula;

TCelula *relacionamentos, *usuarios;

//==| Assinatura das Funções |==========================
void inicializaMatriz(TCelula **c);
void defineMatriz(TCelula **c, int linha, int coluna);
TCelula *alocaCelula();
void atualizaCelula(TCelula **c, int linha, int coluna, int valor);
TCelula *localizaCelula(TCelula *c, int linha, int coluna);
int obterValor(TCelula *c);
void adicionarLinha(TCelula **c);
void adicionarColuna(TCelula **c);
void exibeMatriz(TCelula *c);

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

//===| Funções e Procedimentos |========================
void inicializaMatriz(TCelula **c){
	*c = NULL;
}
//======================================================
void defineMatriz(TCelula **c, int linha, int coluna){
	if(*c == NULL){
		int lin,col;
		TCelula *linhaAtual = NULL, *colunaAtual = NULL;
		TCelula *colunaAux = NULL;
		
		*c = alocaCelula();
		linhaAtual = *c;
		
		for(lin=0; lin < linha; lin++){
			colunaAtual = linhaAtual;
			
			for(col=1; col < coluna; col++){
				colunaAtual->dir = alocaCelula();
				colunaAtual = colunaAtual->dir;
				
				if(colunaAux != NULL)	{
					colunaAux->abaixo = colunaAtual;
					colunaAux = colunaAux->dir;	
				}//if
				
			}//for
			
			colunaAux = linhaAtual->dir;
			
			if(lin < (linha - 1)) 
			   linhaAtual->abaixo = alocaCelula();
			
			linhaAtual = linhaAtual->abaixo;
		}//for
	}//if
}
//=======================================================
TCelula *alocaCelula(){
	TCelula *novo = (TCelula *)malloc(sizeof(TCelula));
	novo->dir = NULL;
	novo->abaixo = NULL;
	novo->valor = 0;
	strcpy(novo->nome,"");
	return novo;
}
//=======================================================
void atualizaCelula(TCelula **c, int linha, int coluna, int valor){
	TCelula *atual = *c;
	int lin = 0;
	int col = 0;
	
	while(lin < linha){
		lin++;
		atual = atual->abaixo;
	}//while
	
	while(col < coluna){
		col++;
		atual = atual->dir;
	}//while
	
	atual->valor = valor;
}
//===============================================================
TCelula *localizaCelula(TCelula *c, int linha, int coluna){
	TCelula *atual = c;
	int lin = 0, col = 0;
	
	while(lin < linha){
		atual = atual->abaixo;
		lin++;
	}//while
	
	while(col < coluna){
		atual = atual->dir;
		col++;
	}//while
	return atual;
}
//================================================================
int obterValor(TCelula *c){
	return c->valor;
}
//================================================================
void adicionarLinha(TCelula **c){
/* Acrescenta uma nova linha ao final da matriz*/
	TCelula *atual, *novo, *ultimo;
	
	if((*c) != NULL){

	   atual = (*c);
	   while(atual->abaixo != NULL){
	    	atual = atual->abaixo;
	   }//while
	   
	   ultimo = NULL;
	   
	   while(atual != NULL){
	   		novo = alocaCelula();
			
			if(ultimo != NULL){
				ultimo->dir = novo;
			}//if
			
			atual->abaixo = novo;
			
			ultimo = novo;
			
			atual = atual->dir;
					
	   }//while
	   
    }//if
	
	printf("\n\n\tLinha INSERIDA com SUCESSO!!!");
	
}
//================================================================
void adicionarColuna(TCelula **c){
/* Acrescenta uma nova coluna ao final da matriz*/
	TCelula *atual, *novo, *ultimo;
	
	if((*c) != NULL){
		atual = (*c);
		
		while(atual->dir != NULL){
			atual = atual->dir;
		}//while
		
		ultimo = NULL;
		
		while(atual != NULL){
	   		novo = alocaCelula();
			
			if(ultimo != NULL){
				ultimo->abaixo = novo;
			}//if
			
			atual->dir = novo;
			
			ultimo = novo;
			
			atual = atual->abaixo;
			
		}//while
		
    }//if
    
    printf("\n\n\tColuna INSERIDA com SUCESSO!!!");
}
//================================================================
void exibeMatriz(TCelula *c){
	system("CLS");
	printf("\n\n\n\t\t=====| EXIBE MATRIZ |=====\n\n");
	
	TCelula *atual;
	TCelula *proxima = c;
	
	while(proxima != NULL){
		atual = proxima;
		while (atual != NULL)	{
			printf("  %d", atual->valor);
			atual = atual->dir;
		}//while
		printf("\n");
		proxima = proxima->abaixo;
	}//while
	
	printf("\n\n");
	system("PAUSE");
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


