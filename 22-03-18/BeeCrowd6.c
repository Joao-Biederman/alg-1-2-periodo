#include <stdio.h>

int main(){
    int b, d, negativo;
    int saldo[20];
    int deve, credor, valor;

    while(scanf("%d %d", &b, &d) && b && d)
    {
        negativo=0;
        for (int i = 0; i < b; i++)
        {
            scanf("%d", &saldo[i]);
        }
        for (int i = 0; i < d; i++)
        {
            scanf("%d %d %d", &deve, &credor, &valor);
            saldo[deve-1] -= valor;
            saldo[credor-1] += valor;
        }
        for (int i = 0; i < b; i++)
        {
            if (saldo[i] < 0)
            {
                negativo=1;
            }
        }
        printf("%d %d %d\n", saldo[0], saldo[1], saldo[2]);
        negativo?printf("N\n"):printf("S\n");
    }
    return 0;
}