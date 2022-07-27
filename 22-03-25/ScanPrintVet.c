#include <stdio.h>

#define MAX 50

// Vetor Global
float Vet[MAX];
float Soma;
float Media;

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// Funcão leitura de vetores
// void scanVet(float *V, int n)
// Parametros:
//      V : vetor a ser lido
//      n : numero de elementos
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
void scanVet(float *V, int n){
    for (int i = 0; i < n; i++)
    {
        printf("V[%d] = ", i);
        scanf("%f", &V[i]);
    }
}

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// Funcão impressão de vetores
// void printVet(float *V, int n)
// Parametros:
//      V : vetor a ser impresso
//      n : numero de elementos
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
void printVet(float *V, int n){
    printf("V[");
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
        {
            printf("%.2f, ", V[i]);
        } else
            printf("%.2f", V[i]);
    }
    printf("]\n");
}

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// Funcão Soma dos elementos do vetores
// void printVet(float *V, int n)
// Parametros:
//      V : vetor a ser somado
//      n : numero de elementos
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
float somaVet(float *V , int n){
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += V[i];
    }

    return soma;
}

float mediaVet(float soma, int n){
    float media;
    media = soma/n;
    return media;
}

int main(void){
    int m;

    scanf("%d", &m);
    scanVet(Vet, m);
    printVet(Vet, m);
    Soma = somaVet(Vet, m);
    printf("Soma dos Elementos do vetor = %.2f\n", Soma);
    Media = mediaVet(Soma, m);
    printf("Média do Vetor = %.2f\n", Media);

    return 0;
}