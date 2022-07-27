// listSE.c
// Exemplos de algoritmos com listas encadeadas

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// define o tipo de dado a ser colocado na lista
typedef short Tdata; 

//tipo de dado para lista encadeada
typedef  struct TNode{
	Tdata info; // dado armazenado no nó
	struct TNode *next;	// ponteiro para o próximo nó
} TNode;

typedef struct TListSE{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

//===========================================
//
// Funções sobre listas encadeadas
//
//===========================================

// Inicialização da lista
void initList(TListSE *L){
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

// destruição da lista
void deleteList(TListSE *L){
	TNode *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		L->length--;
		p = L->first;
	}
	L->last = NULL;
}

// verifica lista vazia
bool emptyList(TListSE L){
	return (L.length == 0);
}

// escreve a lista;

void printList(TListSE L){
	TNode *p = L.first;
	
	printf("[");
	while (p)
	{
		printf("%hd", p->info);
		if (p->next)
			printf(", ");
		p = p->next;
	}
	printf("]");
}

// inserção pela esquerda
void insertLeft(Tdata x, TListSE *L){
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL){						// falha na alocação
		printf("Memória insuficiente!\n"); // sinaliza com erro, deixando a lista original intacta
		return;
	}
	else
	{ // insere x na lista
		aux->info = x;			 	  // atribui x para o campo info
		aux->next = L->first;	 	 // insere o elemento antes do atual primeiro
		L->first = aux;				// Faz o ponteiro do primeiro apontar para o novo nó
		if (L->last == NULL)	   // lista estava vazia
			L->last = aux;		  // primeiro elemento é também o último
		L->length++;			 // incrementa o tamanho da lista
		return;				// fim normal
	}
}

// Inserção pela direita
void insertRight(Tdata x, TListSE *L){
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL){
		printf("Memória insuficiente!\n");
		return;
	}
	else
	{
		aux->info = x;
		aux->next = NULL;
	
		if (L->last == NULL)			// lista está vazia
			L->first = L->last = aux;  // atualiza primeiro e último
		else                          // atualiza só o último
		{
			L->last->next = aux;
			L->last = aux;
		}
		L->length++;
		return;
	}
}

// remoção pela esquerda
void removeFirst(TListSE *L){
	TNode *aux = L->first;				// guarda o nó a ser removido em aux
	L->first = L->first->next;		   // avança para o próximo nó
	free(aux)	;					  // libera aux
	if (L->first == NULL)			 // Lista ficou vazia
		L->last = NULL;				// Anula o last também
	L->length--;				   // reduz o tamanho
}

// remoção pela direita
void removeLast(TListSE *L){
	TNode *aux = L->first;
	
	if (L->first == L->last){		 // há apenas um elemento na lista
		free(L->first);				// libera o nó first
		L->last = L->first =NULL;  // anula tudo
	}
	else
	{	// tem mais de um na lista
		while (aux->next->next != NULL)		 // procura pelo penúltimo
			aux = aux->next;
		L->last = aux;						// penúltimo é novo último
		free(aux->next);				   // libera o último
		L->last->next = NULL;			  // anula o nó depois do último
	}
	L->length--;
}

// Busca um elemento na lista
TNode* searchList(Tdata x, TListSE L){
	TNode *aux = L.first;
	
	while (aux && aux->info != x)
		aux = aux->next;
	return aux;
}

Tdata sumList(TListSE L){
	TNode *aux = L.first;
	Tdata s = 0;
	
	while (aux)
	{
		s += aux->info;
		aux = aux->next;
	}
	return s;
}
 
Tdata avgList(TListSE L)
{
	return (sumList(L)/L.length);
}

// decimal para binário
void dec2bin(Tdata num, TListSE* L){
	Tdata r;
	deleteList(L);
	while (num > 1)
	{
		r = num % 2;
		num = num / 2;
		insertLeft(r, L);
	}
	insertLeft(num, L);
}

// binário para decimal

Tdata bin2dec(TListSE L){
	Tdata i = 0, n = 0;
	TNode *aux = L.first;
	
	while (aux)
	{
		n += aux->info * (Tdata)pow(2, L.length - (++i));
		aux = aux->next;
	}
	return n;
}

// Inverte uma lista
void invertList(TListSE* L)
{
	TNode *ant = NULL, *seg; 			    // define variaveis auxiliares
	L->last = L->first;					   // Direciona o antigo primeiro elemento como o ultimo
	while (L->first)
	{					 				  // Repete o ciclo até L->First ser nulo
		seg = L->first->next;			 // Seg recebe a posição do até então proximo número			
		L->first->next = ant;			// Next recebe o endereço do termo anterior, invertendo a direção
		ant = L->first;				   // Ant recebe o ponteiro da atual casa
		L->first = seg;				  // First vai para a próxima casa
	}								 
	L->first = ant;					// First se torna a ultima casa visitada
}

// Insere um elemento em uma posição especifica da lista 
void insertElement(unsigned pos, Tdata x,TListSE* L){
	if (pos <= 0)
	{
		insertLeft(x, L);
	} else if (pos >= L->length)
	{
		insertRight(x, L);
	} else
	{
		TNode *aux, *aux2, *new = (TNode*)malloc(sizeof(TNode));
		if (new == NULL){
			printf("Memória insuficiente!\n");
			return;
		}
		else
		{
			new->info = x;
			int k=0;
			aux = L->first;

			while (k < pos-1)
			{
				aux = aux->next;
				k++;
			}
			aux2 = aux->next->next;
			aux->next = new;
			new->next = aux2;
			L->length++;
		}
	}
}


// Remove um elemento em uma posição especifica da lista 
void removeElement(short pos, TListSE *L){
	if (pos <= 0)
	{
		removeFirst(L);
	} else if (pos >= L->length)
	{
		removeLast(L);
	} else {
	
		short k = 0;
		TNode *aux, *aux2;
		aux = L->first;
		while (k < pos-1)
		{
			aux = aux->next;
			k++;
		}
		aux2 = aux->next->next;
		free(aux->next);
		aux->next = aux2;
		L->length--;
	}		
}

// Escreve os dados na ordem inversa sem inverter a lista
void printInversoRecursivo(TNode* position){
	if (!position)
		return;
	else
	{
		printInversoRecursivo(position->next);
		printf(" %hd", position->info);
		
	}
}
 // Ex aula sexta
// Deleta elementos de uma lista dado seu valor
void deleteValue(short x, TListSE* L){
	if (L->first->info == x){
		removeFirst(L);
		return;
	} else if (L->last->info == x){
		removeLast(L);
	} else {
	TNode *aux1, *aux2;
	aux1 = L->first;
	aux2 = aux1->next;
	while(aux1->info != x && aux1){
		aux1 = aux1->next;
	}
		aux2 = aux1->next->next;
		free(aux1->next);
		aux1->next = aux2;
		L->length--;
	}
}

// Concatena 2 listas
void lstcat(TListSE* L1, TListSE* L2){
	L1->last->next = L2->first;
	L1->last = L2->last;
	L1->length += L2->length;
}

// // Conta a quantidade de elementos com valor n em uma lista
// int contList(Tdata n, TListSE* L){
// 	int cont = 0;

// 	return cont;
// }

// Remove todos os elementos de valor n de uma lista
// void removeValue(Tdata n, TListSE* L){
// }

// 1) Escrever uma função para remover um elemento da lista, dado o seu elemento
// 2) Escrever uma função de concatenação para listas (TListSE lstcat(TListSE L1, TListSE L2))
// 3) Escrever uma função para contar o nº de ocorrências de um elemento x em uma lista L
// 4) Escrever uma função "removeAll(TData X, TListSE *L1)" Que remova todas as ocorrências de x em L!


//===========================================

int main(){
// Declaração de variáveis
  TListSE L1;

// Inicialização da lista
  printf("Inicializando a lista L1...\n");
  initList(&L1);
  printf("Lista inicializada!\n");
  
// Verificando lista vazia
  emptyList(L1)? printf("Lista vazia!\n"): printf("Lista não vazia!\n");

// Insere pela esquerda
  insertLeft(3, &L1); 
  insertLeft(2, &L1);
  insertLeft(1, &L1); 
  
// Insere pela esquerda
  insertRight(4, &L1); 
  insertRight(5, &L1);
  insertRight(6, &L1); 
  
// Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");

// Invertendo lista
  printf("Invertendo a lista L1...\n");
  invertList(&L1);

// Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");
  
//Inserindo em uma posição especifica
  printf("Adicionando Elementos a L1...\nERRO AO ADICIONAR NO MEIO!\n");
  insertElement(0, 7, &L1);
  insertElement(4, 9, &L1);

// Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");

// Impressão invertida sem inverter a lista
  printf("Imprimindo L1 ao inverso:\n");
  printf("L1' = [");
  printInversoRecursivo(L1.first);
  printf(" ]\n");

//Cria uma lista l2
  TListSE L2;
  printf("Inicializando a lista L2...\n");
  initList(&L2);
  printf("Lista inicializada!\n");

// Imprimindo a lista
  printf("L2 = ");
  printList(L2);
  printf("\n");

// Insere pela esquerda
  insertLeft(2, &L2); 
  insertLeft(1, &L2);
  insertLeft(0, &L2);   
 
// Concatena L1 com L2
  printf("Concatenando L1+L2...\n");
  lstcat(&L1, &L2);

// Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");

// Deletando o primeiro elemento com valor 9
  printf("Deletando 9...\n");
  deleteValue(9, &L1);
  printf("ERRO!\n");

//Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");  

// Deletando a lista
  printf("Deletando a lista L1...\n");
  deleteList(&L1);
  printf("Lista deletada!\n");
  
  return 0;
}