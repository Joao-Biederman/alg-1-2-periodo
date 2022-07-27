#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef int TDados;
typedef int Tnum;

void troca(TDados *x, TDados *y)
{
    /*
     * Troca os dados de posição
     */
}

void escreve(TDados V[], Tnum n)
{
    /*
     *  Escreve o vetor
     */
    printf("\n\n");
}

// Algoritmo Bubble Sort
void bubblesort(TDados dados[], Tnum n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (dados[j-1] > dados[j])
                troca(&dados[i-1], &dados[i]);
        }
    }
}

// Algoritmo Shake Sort
void shakesort(TDados dados[], Tnum n)
{
    bool trocou;
    do
    {
        trocou = false;
        for (Tnum i = n - 1; i > 0; i--)
        {
            if (dados[i-1] > dados[i])
            {
                troca(&dados[i-1], &dados[i]);
                trocou = true;
            }
        }   
    } while (trocou);
}

// Algoritmo Selection Sort
void selectionsort(TDados dados[], Tnum n)
{
    for (int i = 0; i < (n-1); i++)
    {
        Tnum min = i;
        for (int j = i+1; i < n; i++)
        {
            if (dados[j] < dados[min])
                min = j;
            
            troca(&dados[min], &dados[i]);
        }   
    }
}

// Algoritmo Insertion Sort
void insertionSort(TDados dados[], Tnum n)
{
    for (Tnum i = 1; i < n; i++)
    {
        TDados aux = dados[i];
        Tnum j = 0;
        for (j = i; j > 0 && (aux < dados[j-1]); j--)
        {
            dados[j] = dados[j - 1];
        }
    }
}

// Algoritmo Shell Sort
// Pegar do slide

int main()
{
    const short MAX = 100;
    TDados V[MAX];
    Tnum n, k, p;
    __clock_t tempo;

    printf(">>> Exemplo de algoritmos de ordenação <<<\n");
    printf("Quantos elementos deseja gerar? >>>");
    scanf("%hd", &n);

    srand(time(NULL));

    printf("Vetor 1: ");
    for (int i = 0; i < n; i++)
        V[i] = rand() % MAX + 1;
    escreve(V, n);

    printf("Ordenando o vetor...\n");
    // descomente abaixo o algoritmo que deseja testar

    tempo = clock(); // pega o tempo inicial do algoritmo
    
    escreve(V, n);
    printf("Tempo gasto = %f segundos\n", ((float)tempo) / CLOCKS_PER_SEC);
    
}