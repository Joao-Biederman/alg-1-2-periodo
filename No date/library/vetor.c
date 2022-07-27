// vetor.c
// implementação da biblioteca vetor
#include <stdio.h>
#include <string.h>
#include "vetor.h"

void initIntVet(IntVet *V)
{
    memset(V, 0, sizeof(IntVet));
    return;
}

void scanIntVet(IntVet *V)
{
    printf("Tamanho >>");
    scanf("%d", &V->size);
    for (int i = 0; i < &V->size; i++)
    {
        printf("V[%d] >> ", i);
        scanf("%d", &V->data[i]);
    }
}