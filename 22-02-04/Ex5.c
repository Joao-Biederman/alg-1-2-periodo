#include <stdio.h>

int main(){

    int ind = 0, indmenor, indmaior;
    float k, menor, maior;

    do
    {
        scanf("%f", &k);
        if (k >= 0)
        {
            if (ind == 0)
            {
                menor = k;
                maior = k;
                indmaior = 0;
                indmenor = 0;
            }
            
            ind ++;       

            if (k > maior)
            {
                maior = k;
                indmaior = ind;
            }

            if (k < menor)
            {
                menor = k;
                indmenor = ind;
            }
        }

    } while (k > 0);
    
    printf("Maior Elemento: A[%d] = %.0f\n", indmaior, maior);
    printf("Menor Elemento: A[%d] = %.0f\n", indmenor, menor);

    return 0;
}