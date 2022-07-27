// LDE.c
// Exemplos de algoritmos com listas duplamente encadeadas

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// define o tipo de dado a ser colocado na lista
typedef short Tdata; 

//tipo de dado para lista encadeada
typedef  struct TNode
{
	Tdata info; // dado armazenado no nó
    struct TNode *prev;	// ponteiro para o nó anterior
	struct TNode *next;	// ponteiro para o próximo nó
} TNode;

typedef struct TListDE
{
	TNode *first;
	TNode *last;
	short length;
} TListDE;

//===========================================
//
// Funções sobre listas duplamente encadeadas
//
//===========================================

// Inicialização da lista
void initList(TListDE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

// destruição da lista
void deleteList(TListDE *L)
{
	TNode *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		p = L->first;
	}
	L->last = NULL;
  L->length = 0;
}

// verifica lista vazia
bool emptyList(TListDE L)
{
	return (L.length == 0);
}

// escreve a lista;

void printList(TListDE L, bool inverse) 	
{	
  TNode *p;
  
  if (!inverse)
  {
    printf("First->");
    p = L.first;
     
    while (p)
    {
      printf("[%hd]->", p->info);
      p = p->next;
    }
    printf("[NULL]");
  }
	else
	{
		printf("Last->");
    p = L.last;
     
    while (p)
    {
      printf("[%hd]->", p->info);
      p = p->prev;
    }
    printf("[NULL]");
	}
  
  return;
}

// inserção pela esquerda
short insertLeft(Tdata x, TListDE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)	// falha na alocação
		return 1;	// sinaliza com erro, deixando a lista original intacta
	else
	{ // insere x na lista
		aux->info = x;					// Atribui x para o campo info.
		aux->next = L->first;		// Insere o elemento antes do atual primeiro.
		aux->prev = NULL;				// não tem anterior
		if (L->first != NULL)
			L->first->prev = aux;
		L->first = aux;				// Faz o ponteiro do primeiro apontar para o novo nó.
		if (L->last == NULL)			// lista estava vazia
			L->last = aux;				// primeiro elemento é também o último
		L->length++;					// incrementa o tamanho da lista
		return 0;						// fim normal
	}
}

// Inserção pela direita
short insertRight(Tdata x, TListDE *L)
{
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = NULL;					// Não tem próximo
		aux->prev = L->last;				// O anterior é o antigo último

		if (L->last == NULL)				// Lista estava vazia
			L->first = L->last = aux;	// atualiza primeiro e último
		else                          // atualiza só o último
		{
			L->last->next = aux;			// liga o novo último nó
			L->last = aux;					// atualiza o ponteiro para o novo último
		}
		L->length++;						// atualiza o comprimento
		return 0;
	}
}

// remoção pela esquerda
void removeFirst(TListDE *L)
{
	TNode *aux = L->first;		// Guarda o nó a ser removido em aux
	L->first = L->first->next;	// Avança para o próximo nó
	free(aux)	;					// libera aux
	if (L->first == NULL)		// Lista ficou vazia
		L->last = NULL;			// Anula o last também
	else
  		L->first->prev = NULL;
		L->length--;					// reduz o tamanho
}

// remoção pela direita

void removeLast(TListDE *L)
{
	TNode *aux = L->last;		// Guarda o nó a ser removido em aux
	L->last = L->last->prev;	// volta para o nó anterior
	free(aux)	;					// libera aux
	if (L->last == NULL)			// Lista ficou vazia
		L->first = NULL;			// Anula o first também
  else
    L->last->next = NULL;			// Anula o próximo do novo último
	L->length--;					// reduz o tamanho
}

// Busca um elemento na lista
TNode* searchList(Tdata x, TListDE L)
{
	TNode *aux = L.first;
	
	while (aux && aux->info != x)
		aux = aux->next;
	return aux;
}


Tdata sumList(TListDE L)
{
	TNode *aux = L.first;
	Tdata s = 0;
	
	while (aux)
	{
		s += aux->info;
		aux = aux->next;
	}
	return s;
}
 
 Tdata avgList(TListDE L)
 {
	 return (sumList(L)/L.length);
 }

// decimal para binário
TListDE *dec2bin(Tdata num)
{
	Tdata r;
	TListDE *L = (TListDE*)malloc(sizeof(TListDE));
	initList(L);
	
	while (num > 1)
	{
		r = num % 2;
		num = num / 2;
		(insertLeft(r, L));
	}
	insertLeft(num, L);
	return L;
}


// binário para decimal

Tdata bin2dec(TListDE L)
{
	Tdata i = 0, n = 0;
	TNode *aux = L.first;
	
	while (aux)
	{
		n += aux->info * (Tdata)pow(2, L.length - (++i));
		aux = aux->next;
	}
	return n;
}

// Inverte a lista
void invertList(TListDE *L)
{
    TNode *aux = NULL;
    L->last = L->first;							   // Substitui o ultimo elemento pelo atual primeiro
	while (L->first)							  // Enquanto First não for nulo
    {
		L->first->prev = L->first->next;
		L->first->next = aux;
		aux = L->first;
		L->first = L->first->prev;
    }
	L->first = aux;
}

// Adiciona um elemento
short addElement(Tdata x, TListDE *L, short pos)
{
	if (pos == 1)
		insertLeft(x, L);
	else if (pos >= L->length)	
		insertRight(x, L);
	else
	{
		TNode *new, *aux = L->first;
		new = (TNode*)malloc(sizeof(TNode));
		if (new == NULL)	 // falha na alocação
			return 1;		// sinaliza com erro, deixando a lista original intacta
		else
		{
			new->info = x;
			for (int i = 1; i < pos-1; i++)
			{
				aux = aux->next;
			}
			new->prev = aux;
			new->next = aux->next;
			aux->next = new;
			new->next->prev = new;
			L->length++;
			return 0;
		}
	}
}

// Remove um elemento baseado em sua posição
void removeElement(TListDE *L, short pos)
{
	if (pos <= 1)
		removeFirst(L);
	else if (pos >= L->length)	
		removeLast(L);
	else
	{
		TNode *aux = L->first;
		for (short i = 1; i < pos; i++)
		{
			aux = aux->next;
		}
		aux->next->prev = aux->prev;
		aux->prev->next = aux->next;
		free(aux);
		L->length--;
	}
}

// Remove um elemento baseado em seu conteúdo
void removeValue(Tdata x, TListDE *L)
{
	if (x == L->first->info)
		removeFirst(L);
	else if (x == L->last->info)
		removeLast(L);
	else
	{
		TNode *aux = L->first, *aux2;
		while (aux->next->info != x)
			aux = aux->next;
		aux2 = aux->next->next;
		free(aux->next);
		aux->next = aux2;
		aux2->prev = aux;
		L->length--;
	}
}

// Concatena 2 listas preservando a segunda lista
void concatList(TListDE *L1, TListDE *L2)
{
	TNode *aux = L2->first;
	while (aux)
	{
		insertRight(aux->info, L1);
		aux = aux->next;
	}
}

// Conta a quantidade que um valor x se repete dentro da lista
short contValue(short x, TListDE *L1)
{
	TNode *aux = L1->first;
	short cont = 0;

	while (aux)
	{
		if (aux->info == x)
			cont++;	
		aux = aux->next;
	}
	return cont;
}

// Remove todos os elementos cujo conteúdo seja x
void removeAllValue(Tdata x, TListDE *L1)
{
	TNode *aux = L1->first, *aux2;

	while (aux)
	{
		if (aux->info == x)
		{
			if (aux == L1->first)
			{
				removeFirst(L1);
			} else if (aux == L1->last)
			{
				removeLast(L1);
			} else {
				aux2 = aux->next;
				aux2->prev = aux->prev;
				aux->prev->next = aux->next;
				free(aux);
				aux = aux2;
				L1->length--;
			}
		} else
			aux = aux->next;	
	}
}

// Separa uma lista em duas
void splitList(TListDE *L1, TListDE *L2, unsigned pos)
{
	TNode *aux = L1->first;
	for (unsigned i = 1; i < pos-1; i++)
	{
		aux = aux->next;
	}

	L2->last = L1->last;
	L2->first = aux->next;
	L1->last = aux;

	L2->first->prev = NULL;
	L1->last->next = NULL;

	L2->length = L1->length-pos+1;
	L1->length = pos-1;
}

//===========================================

int main()
{
	TListDE L1, L2;
	short a, b;
	TNode *n;
	
	printf("Inicializando a lista...\n");
	initList(&L1);
	printf("Lista Inicializada!\n\n");

  if (emptyList(L1))
		printf("A lista está vazia!\n");
	printList(L1, false);
	printf("\n");

	printList(L1, true);
	printf("\n\n");	

  printf("Inserindo 1 na lista pela esquerda...\n");
	if (insertLeft(1, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");
	printList(L1, false);
	printf("\n");
  printList(L1, true);
	printf("\n\n");

  printf("Inserindo 2 na lista pela esquerda...\n");
	if (insertLeft(2, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");
	printList(L1, false);
	printf("\n");	
	printList(L1, true);
	printf("\n\n");

  printf("Inserindo 3 na lista pela direita...\n");
	if (insertRight(3, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");
		
	printList(L1, false);
	printf("\n");
	printList(L1, true);
	printf("\n\n");

	printf("Inserindo 4 na lista pela direita...\n");
	if (insertRight(4, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");
	
	printList(L1, false);
	printf("\n");	
	printList(L1, true);
	printf("\n\n");

/*
  printf("Removendo pela esquerda...\n");
	removeFirst(&L1);
	printList(L1, false);
	printf("\n");	
	printList(L1, true);
	printf("\n\n");	

  printf("Removendo pela direita...\n");
	removeLast(&L1);
	printList(L1, false);
	printf("\n");	
	printList(L1, true);
	printf("\n\n");
*/
  printf("Digite um valor a ser pesquisado: >> ");
	scanf("%hd", &a);
	printf("Buscando elemento...\n");
	n = searchList(a, L1);
	if (n)
	{
		printf("Elemento encontrado no endereço %p.\n", n);
		printf("imprimindo o valor: %hd\n", n->info);
		printf("Modificando o valor para 5...\n");
		n->info = 5;
		printList(L1, false);
		printf("\n");	
		printList(L1, true);
		printf("\n");
	}
	else
		printf("Elemento não encontrado!\n");
	
// Inverte a lista
  printf("Invertendo a lista...\n");
	invertList(&L1); 
  printf("Lista invertida\n");
// Imprime a lista
  printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");

// Adicionando um número em uma posição especifica
  printf("Adicionando 3 novos elementos...\n");
	addElement(6, &L1, 5);
	addElement(0, &L1, 1);
	addElement(4, &L1, 3);
  printf("Elementos adicionados:\n");
// Imprime a lista
  printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");

// Remove um elemento em uma posição especifica
  printf("Removendo elementos...\n");
	removeElement(&L1, 1);
	removeElement(&L1, 6);
	removeElement(&L1, 2);
  printf("Elementos removidos:\n");
// Imprime a lista
  printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");

//Removendo um número especifico
  printf("Removendo o número 5 da lista...\n");
	removeValue(5, &L1);
  printf("Número removido:\n");
// Imprime a lista
  printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");
  
// Inicializa lista 2
  initList(&L2);
// Adiciona elementos a lista 2;
  insertRight(3, &L2);
	insertRight(9, &L2);
	insertRight(4, &L2);
  insertRight(3, &L2);

// Concatena as listas L1 e L2
  printf("Concatenando Listas...\n");
	concatList(&L1, &L2);
  printf("Listas concatenadas\nL1:\n");
// Imprime a lista 1 já concatenada com a lista 2
  printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");

// Imprime a lista 2
  printf("L2:\n");
	printList(L2, false);
	printf("\n");
	printList(L2, true);
  printf("\n\n");

// Conta a quantidade de 3 presentes na L1
  printf("Na lista L1 temos %hd elementos cujo valor é 3.\n\n", contValue(3, &L1));

// Remove todos os elementos com valor = 3
  printf("Removendo todos os elementos cujo valor é 3...\n");
    removeAllValue(3, &L1);
  printf("Elementos removidos:\n");
// Imprime a lista 1
  printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");

//Inicia uma terceira lista L3, que será fruto da divisão de L1
  TListDE L3;
	printf("Inicializando a lista...\n");
	initList(&L3);
	printf("Lista Inicializada!\n\n");

  if (emptyList(L3))
		printf("A lista está vazia!\n");
	printList(L3, false);
	printf("\n");

// Divide L1
  printf("Dividindo lista L1...\n");
	splitList(&L1, &L3, 3);
  printf("Lista dividida.\n");
// Imprime a lista 1
  printf("L1: %hd\n", L1.length);
	printList(L1, false);
	printf("\n");
	printList(L1, true);
  printf("\n\n");
// Imprime a lista 2
  printf("L2: %hd\n", L2.length);
	printList(L2, false);
	printf("\n");
	printList(L2, true);
  printf("\n\n");
// Imprime a lista 3
  printf("L3: %hd\n", L3.length);
	printList(L3, false);
	printf("\n");
	printList(L3, true);
  printf("\n\n");

// Deleta a lista
  printf("Destruindo a lista...\n");	
	deleteList(&L1);
	deleteList(&L2);
	deleteList(&L3);
  printf("Lista apagada!\n");
 // deleteList(&L2);
	
	return 0;
}