//Exercicio 4
#include <stdio.h>
#include <math.h>

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// Funcão recursiva para soma de frações
// float f2(int n)
// Parametros:
//      n : soma 2/3 até (n²+1)/(n+3)
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
float f2(int n){
    float soma = 0;
    if (n == 1)
    {
        return (2/3);
    } else
    {
        soma = (pow(n, 2)+1.0)/(n+3);
        n--;
        soma += f1(n);
        return soma;
    }
    
}

int main(){
    int n;
    float soma;
    while(scanf("%d", &n) != EOF){
        soma = f2(n);
        printf("%.2f\n", soma);
    }

    return 0;
}