#include <stdio.h>
#include "vetor.h"

int main(void)
{
    IntVet A;

    printf("Testando a biblioteca vetor.h\n");
    initIntVet(&A);
    scanIntVet(&A);
    return 0;
}