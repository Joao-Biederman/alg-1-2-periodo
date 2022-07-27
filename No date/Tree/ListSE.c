// ListSE.c

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned short Tdata;

typedef struct TreeNode
{
    Tdata info;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef  struct TNode
{
    TreeNode *info;
    struct TNode *next;
} TNode;

typedef struct TListSE
{
    TNode *first;
    TNode *last;
    short length;
} TListSE;

//===================================
//
// Funçoes sobre listas encadeadas
//
//===================================

// Inicializando a lista
void initList(TListSE *L){
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

// Destuiçao da lista
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

// Verifica lista vazia
bool emptyList(TListSE L){
    return (L.length == 0);
}

// Inserçao pela direita
short insertRight(TreeNode *x ,TListSE *L){
	TNode *aux = (TNode*)malloc(sizeof(TNode));
    if (aux ==NULL)
        return 1;
    else
    {
        aux->info = x;
        aux->next = NULL;
    
        if (L->last == NULL)
            L->first = L->last = aux;
        else
        {
            L->last->next = aux;
            L->last = aux;
        }
        L->length++;
        return 0;
    }
}

// Remoçao pelo esquerda
void removeLeft(TListSE *L){
TNode *aux = L->first;
    L->first = L->first->next;
    free(aux);
    if (L->first == NULL)
        L->last = NULL;
    L->length--;
}

// retorna a cabeça da arvore
TreeNode* head(TListSE L){
	return (L.first->info);
}