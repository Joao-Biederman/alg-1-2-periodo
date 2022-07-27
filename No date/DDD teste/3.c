// 3.c
// Testar

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nome[10];
} Pessoa;

Pessoa contatos[5];

void gerarNome(char vetor[])
{
    for(int i = 0; i < 10; i++)
    {
        vetor[i] = rand()%26 + 65;
    }
}

int main()
{
    for (int i = 0, mat = 1; i < 5; i++, mat++)
    {
        contatos[i].matricula = mat;
        gerarNome(contatos[i].nome);
    }
    return 0;
}