//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayDin.h"

int main(void){
    TMatDin A;
    unsigned newL, newC;


    printf("Alocação Dinâmica de Vetores e Matrizes\n");
    printf("Matrizes:\n\n");
    printf("Quantas linhas?  >> ");
    scanf("%u", &A.l);
    printf("Quantas colunas? >> ");
    scanf("%u", &A.c);
    initMatDin(&A, A.l, A.c);
    scanMatDin(&A);
    printMatDin(A);
    printf("\nModificando o tamanho da matriz: \n");
    printf("Qual a nova quantidade de linhas?  >> ");
    scanf("%u", &newL);
    printf("Qual a nova quantidade de colunas? >> ");
    scanf("%u", &newC);
    printf("Realocando a matriz...\n");
    realocaMatDin(&A, newL, newC);
    printf("Matriz realocado\n");
    printMatDin(A);
    printf("Deletando a matriz\n");
    deleteMatDin(&A);
    return 0;
}