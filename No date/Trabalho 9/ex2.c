#include <stdio.h>
#include <stdlib.h>

typedef short Tdata;

typedef struct TNode
{
    Tdata info;
    struct TNode *next;
}TNode;

typedef struct TList
{
    TNode *first;
    TNode *last;
    short length;
} TList;

void initList(TList *L){
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

void insertRight(Tdata x, TList *L){
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux ==NULL){
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

Tdata sumList(TList L){
	TNode *aux = L.first;
	Tdata s = 0;
	
	while (aux)
	{
		s += aux->info;
		aux = aux->next;
	}
	return s;
}

short abv(TList L, Tdata med){
    TNode *aux = L.first;
    short a=0;

    while (aux)
    {
        if(aux->info > med)
            a++;
        aux = aux->next;
    }
    return a;
}

short blw(TList L, Tdata med){
    TNode *aux = L.first;
    short b=0;

    while (aux)
    {
        if(aux->info > med)
            b++;
        aux = aux->next;
    }
    return b;
}

int main(){
    TList L;
    Tdata x;
    initList(&L);

    while (scanf("%hd", &x) && x > 0)
        insertRight(x, &L);

    float media;
    media = (float)sumList(L)/L.length;
    printf("Média = %.2f\n", media);
    printf("Acima = %hd\n", abv(L, media));
    printf("Abaixo = %hd\n", blw(L, media));

    return 0;
}