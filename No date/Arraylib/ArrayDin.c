#include <stdio.h>
#include <stdlib.h>
#include "ArrayDin.h"

// Implementação da biblioteca de arrays dinâmicos
// cria um vetor dinâmico com o tamanho size
void initVetDin(TVetDin *V, unsigned size){
    V->dados = (int*)malloc(size*sizeof(int));
    if (!V->dados)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    } else {
        V->n = size;
        return;
    }
}

// deleta um vetor dinâmico
void deleteVetDin(TVetDin *V)
{
    free(V->dados);
}
// lê um vetor dinâmico
void scanVetDin(TVetDin *V){
    for (int i = 0; i < V->n; i++)
    {
        printf("V[%d] = ", i);
        scanf("%d", &V->dados[i]);
    }
    return;
}

// escreve um vetor dinâmico
void printVetDin(TVetDin V){
    printf("[");
    for (unsigned i = 0; i < V.n; i++)
    {
        printf("%d", V.dados[i]);
        if (i < V.n - 1)
        {
            printf(", ");
        }
    }
    printf("]");
    return;
}

// realoca um vetor dinâmico
void realocaVetDin(TVetDin *V, unsigned newSize){
    V->dados = (int*)realloc(V->dados, newSize*sizeof(int));
    if (!V->dados)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    V->n = newSize;
    return;
}

// aloca uma matriz dinâmica
void initMatDin(TMatDin *M, unsigned lines, unsigned cols){
    M->dados = (int**)malloc(lines*sizeof(int*));
    if (!M->dados)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    for (int i = 0; i < lines; i++)
    {
        M->dados[i] = (int*)malloc(cols*sizeof(int));
        if (!M->dados[i])
        {
            printf("Erro: Memória insuficiente!\n");
            exit(1);
        }
    }
    M->l = lines;
    M->c = cols;
    return;
}

// deleta uma matriz dinâmica
void deleteMatDin(TMatDin *M){
    free(M->dados);
    M->l = M->c = 0;
}

// lê uma matriz dinâmica
void scanMatDin(TMatDin *M){
    for (int i = 0; i < M->l; i++){
        for (int j = 0; j < M->c; j++){
            printf("M[%d][%d] = ", i+1, j+1);
            scanf("%d", &M->dados[i][j]);
        }
    }
    return;
}

// escreve uma matriz dinâmica
void printMatDin(TMatDin M){
    for(int i = 0; i < M.l; i++){
        printf("|");
        for (unsigned j = 0; j < M.c; j++)
        {
            printf("%d", M.dados[i][j]);
            if (j < M.c - 1)
            {
                printf(", ");
            }
        }
        printf("|\n");
    }
}

// realoca uma matriz dinâmica
void realocaMatDin(TMatDin *M, unsigned newLines, unsigned newCols){
    M->dados = (int**)realloc(M->dados, newLines*sizeof(int*));
    if (!M->dados)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    } else {
        for (unsigned i = 0; i < newLines; i++)
        {
            M->dados[i] = (int*)realloc(M->dados[i], newCols*sizeof(int));
            if (!M->dados[i])
            {
                printf("Erro: Memória insuficiente!\n");
                exit(1);
            }
        }
        M->l = newLines;
        M->c = newCols;
    }

    return;
}