// Luiz Felipe e João Vitor

#include <stdio.h>
#include <stdlib.h>

/*
* Definição de tipos e de structs
* TRacional para o tipo racional num/den
* TData para os dados da lista simplesmente encadeada
* TListSE para a lista simplesmente encadeada 
*/
typedef struct
{
    int num;
    int den;
} TRacional;

typedef struct TNode
{
    TRacional info;
    struct TNode *next;
} TNode;

typedef struct
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

/*
*   initList()
*   Função que inicia a lista simplesmente encadeada, zerando os valores e evitando possíveis lixos na memória
*   Entradas: ponteiro da lista do tipo definido TListSE
*   Saídas: nenhuma
*/
void initList(TListSE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

/*
*   deletList()
*   Função que elimina a lista L da memória evitando lixo
*   Entradas: Ponteiro da lista do tipo definido TListSE
*   Saídas: nenhuma
*/
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

/*
*   printList()
*   Função que printa a lista de maneira formatada, mostrando numerador/denominador
*   Se denominador for == 1, printa somente 1
*   Entradas: ponteiro da lista TListSE
*   Saídas: nenhuma
*/
void printList(TListSE L)
{
	TNode *p = L.first;
	
	while (p)
	{
		printf("%d/%d", p->info.num, p->info.den);
		if (p->next)
			printf(", ");
		p = p->next;
	}
}

/*
*   insertRight()
*   Função que insere valores à direita na lista simplesmente encadeada.
*   Entradas: valor que será inserido na lista é do tipo TRacional, contendo um numerador e um denominador
*   Saídas: short que nos diz se a função deu certo ou não deu.
*/
short insertRight(TRacional x, TListSE *L)
{
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

/*
*   insert()
*   Insere o valor da soma dos denominadores de duas frações entre elas na lista.
*   Entradas: O valor inserido é a posição de memória da primeira das duas frações (é do tipo TNode) e um array TListSE L o valor inserido pertence
*   Saídas: short que informa um sinal de erro, sendo 1 para erro e 0 para sucesso.
*/
short insert(TNode *aux1, TListSE *L){
    TNode *aux2=aux1->next, *new = (TNode*)malloc(sizeof(TNode));
    if (new == NULL)
        return 1;
    new->info.den = aux1->info.den + aux2->info.den;
    new->info.num = aux1->info.num + aux2->info.num;
    new->next = aux2;
    aux1->next = new;
    L->length++;
    return 0;
}

/*
*   farey()
*   Cria frações de Farey de nivel x.
*   Entradas: Um x que representa o nível da fração de Farey e um array tipo TListSE que irá receber a ração.
*   Saídas: Não possui saídas
*/
void farey(unsigned x, TListSE *L){
    TNode *aux1 = L->first;
    TNode *aux2 = L->last;
    while ((float)aux1->info.den/aux1->info.num != 1)
    {
        if ((aux1->info.den + aux2->info.den) > x)
        {
            aux2 = aux2->next;
            aux1 = aux1->next;
        } else {
            insert(aux1, L);
            aux2 = aux1->next;
        }
    }
}

int main(){
    TListSE L;
    int x;

    while (scanf("%d", &x) && x > 0)
    {
        initList(&L);
        TRacional inicio={0, 1}, fim = {1,1};
        insertRight(inicio, &L);
        insertRight(fim, &L);
        farey(x, &L);
        printf("[");
        printList(L);
        printf("]\n");
        deleteList(&L);
    }

    return 0;
}