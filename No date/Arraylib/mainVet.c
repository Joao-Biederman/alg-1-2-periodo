//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayDin.h"

int main(void){
    TVetDin A;
    unsigned newS;


    printf("Alocação Dinâmica de Vetores e Matrizes\n\n");
    printf("Tamanho desejado para o vetor? >> ");
    scanf("%u", &A.n);
    initVetDin(&A, A.n);
    scanVetDin(&A);
    printVetDin(A);
    printf("\nModificando o tamanho do vetor: \n");
    printf("Qual o novo tamanho? >> ");
    scanf("%u", &newS);
    printf("Realocando o vetor...\n");
    realocaVetDin(&A, newS);
    printf("Vetor realocado: \n");
    printVetDin(A);
    return 0;
}