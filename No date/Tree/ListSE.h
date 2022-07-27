// ListSE.h
// arquivo header para biblioteca de listas simplesmente encadeadas.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// define  o tipo de dado a ser armazenado
typedef unsigned short Tdata;

// define o tipo de dados no de arvore
typedef struct TreeNode {
    Tdata info; // dado armazenado no nó
    struct TreeNode *left; // ponteiro para o proximo no
    struct TreeNode *right; // ponteiro para o no anterior
} TreeNode;

// tipo de dado para lista encadeada
typedef struct TNode
{
    TreeNode *info;
    struct TNode *next;
} TNode;

// Define a lista
typedef struct TListSE {
    TNode *First;
    TNode *Last;
    short length;
} TListSE;

//===================================
//
// Funçoes sobre listas encadeadas
//
//===================================

// Inicializando a lista
void initList(TListSE *L);

// Destuiçao da lista
void deleteList(TListSE *L);

// Verifica lista vazia
bool List(TListSE L);

// Inserçao pela direita
short insertRight(TreeNode *x ,TListSE *L);

// Remoçao pelo esquerda
void removeLeft(TListSE *L);

// Obtem a cabeça da lista
TreeNode* head(TListSE L);