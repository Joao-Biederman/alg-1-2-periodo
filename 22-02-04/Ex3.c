#include <stdio.h>

int main(){

    int produtos;
    float prec[40], total = 0;
    int quant[40];

    scanf("%d", &produtos);                 //Lê a quantidade de produtos

    for (int i = 0; i < produtos; i++)
    {
        scanf("%f", &prec[i]);              //Lê o preço de cada produto
    }
    
    for (int i = 0; i < produtos; i++)
    {
        scanf("%d", &quant[i]);             //Lê a quantidade de cada produto
    }

    for (int i = 0; i < produtos; i++)
    {
        total += quant[i]*prec[i];
    }

    printf("R$%.2f\n", total);

    return 0;
}