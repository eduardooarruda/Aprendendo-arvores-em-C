//árvore binaria
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int conteudo;
	struct no* esquerda;
	struct no* direita;
}No;

typedef struct{
	No* raiz;
}Arvore;

void inserirDireita(No *no, int valor);

void inserirEsquerda(No *no, int valor){
	if(no->esquerda == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->esquerda = novo;
	}
	else{
		if(valor < no->esquerda->conteudo)
			inserirEsquerda(no->esquerda, valor);
	/*
	Este if é para evitar que seja armazenado o mesmo elemento na árvore.
	*/
		if(valor > no->esquerda->conteudo)
			inserirDireita(no->esquerda, valor);		
//		else
//			inserirDireita(no->esquerda, valor);
	}
}

void inserirDireita(No *no, int valor){
	if(no->direita == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->direita = novo;
	}
	else{
		if(valor > no->direita->conteudo)
			inserirDireita(no->direita, valor);	
		if(valor < no->direita->conteudo)
			inserirEsquerda(no->direita, valor);			
//		else
//			inserirEsquerda(no->direita, valor);
			
	}
}
void inserir(Arvore *arv, int valor){
	if(arv->raiz == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		arv->raiz = novo;
	}
	else{
		if(valor < arv->raiz->conteudo){
			inserirEsquerda(arv->raiz, valor);
		}
		if(valor > arv->raiz->conteudo){
			inserirDireita(arv->raiz, valor);
		}		
		
//		else
//			inserirDireita(arv->raiz, valor);
	}
}

//void imprimir(No *raiz){
//	if(raiz != NULL){
//		printf("%d ", raiz->conteudo);
//		imprimir(raiz->esquerda); //(*raiz).esquerda
//		imprimir(raiz->direita);
//	}
//}

/*
para imprimir ordernado. Nesta função é impresso na tela primeiro todos os elementos que se encontram a esquerda
e depois os que estão a direita.
*/

void imprimir(No *raiz){
	if(raiz != NULL){
		imprimir((*raiz).esquerda); //(*raiz).esquerda
		printf("%d ", raiz->conteudo);
		imprimir(raiz->direita);
	}
}

int main(){
	int op, valor;
	Arvore arv;
	arv.raiz = NULL;
	
	do{
		printf("\n0 - Sair \n1 - inserir\n2 - imprimir\n");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				printf("Programa encerrado\n");
				break;
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valor);
				inserir(&arv, valor);
				break;
			case 2:
				printf("\n---------Impressao---------\n");
				imprimir(arv.raiz);
				break;
			default:
				printf("Opcao invalida\n");
		}
		
	}while(op != 0);
	
	return 0;
}
