// 5.c
// exemplo de matriz dimanica no DDD

#include <stdio.h>
#include <stdlib.h>

int **A;

int main()
{
    A = (int**)malloc(sizeof(int*)*5);
    if (!A)
    {
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }
    
    for (int i = 0; i < 5; i++)
    {
        A[i] = (int*)malloc(sizeof(int)*5);
        if (!A[i])
        {
            printf("Erro: memoria insuficiente.\n");
            exit(2);
        }
        
        
    }
    
    return 0;
}