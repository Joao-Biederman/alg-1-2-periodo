#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int col;
    int lin;
    float dados[10][10];
}Tmatriz;

int main(){
    Tmatriz A, B;

    //limpa matrizes
    memset(&A, 0, sizeof(Tmatriz));
    memset(&B, 0, sizeof(Tmatriz));

    //ler tamanho de A
    printf("Insira o tamanho da matriz A\n");
    scanf("%d %d", &A.lin, &A.col);

    //le os dados de A
    printf("Insira os dados da matriz A: \n");
    for (int i = 0; i < A.lin; i++)
    {
        for (int j = 0; j < A.col; j++)
        {
            scanf("%f", &A.dados[i][j]);
        }
    }
    
    //ler tamanho de B
    printf("\nInsira o tamanho da matriz B\n");
    scanf("%d %d", &B.lin, &B.col);

    //le os dados de B
    printf("Insira os dados da matriz B: \n");
    for (int i = 0; i < B.lin; i++)
    {
        for (int j = 0; j < B.col; j++)
        {
            scanf("%f", &B.dados[i][j]);
        }
    }

    //Mostra A
    printf("A matriz A tem %d linhas e %d colunas\n", A.lin, A.col);

    for (int i = 0; i < A.lin; i++)
    {
        for (int j = 0; j < A.col; j++)
        {
            printf(" %6.2f", A.dados[i][j]);
        }
        printf("\n");
    }
    
    //Mostra B
    printf("A matriz B tem %d linhas e %d colunas\n", B.lin, B.col);

    for (int i = 0; i < B.lin; i++)
    {
        for (int j = 0; j < B.col; j++)
        {
            printf(" %6.2f", B.dados[i][j]);
        }
        printf("\n");
    }

    return 0;
}