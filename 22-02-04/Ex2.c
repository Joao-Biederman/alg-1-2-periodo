#include <stdio.h>

int main(){

    int na, nb, nu=0, ni=0; //Lê a quantidade de elemetos presente nos vetores
    int k; //Lê os elementos a serem colocados nos vetores
    int a[31], b[31]; //Inicia os vetores para receber elementos entre e inclusive 0 e 30
    int uni[31], inter[31]; // Inicia os vetores para receber a união e a intercessão entre A e B

    for (int i = 0; i < 31; i++)
    {
        a[i] = 0;
        b[i] = 0;
        uni[i] = 0;
        inter[i] = 0;

    }
    

    scanf("%d", &na); //Quantidade de elementos no vetor A
    for (int i = 0; i < na; i++)
    {
        scanf("%d", &k);        //Le quais elementos serão inseridos em A
        a[k] = 1;               //O número do elemento recebe 1 no indice de A
    }
    
    scanf("%d", &nb);
    for (int i = 0; i < nb; i++)
    {
        scanf("%d", &k);        //Le quais elementos serão inseridos em B
        b[k] = 1;               //O número do elemento recebe 1 no indice de A
    }

    for (int i = 0; i <= 30; i++)
    {
        if (a[i] || b[i])       //se o indice de A ou B for 1, Uni recebe 1 no mesmo indice
        {
            uni[i] = 1;
            nu++;               //Conta a quantidade de elementos no conjunto Uni
        }
        
        if (a[i] && b[i])       //se o indice de A e B for 1, Inter recebe 1 no mesmo indice
        {
            inter[i] = 1;
            ni++;               //Conta a quantidade de elementos no conjunto Inter
        }
    }
    
    printf("A = {");
    for (int i = 0; i <= 30; i++)
    {
        if (a[i])
        {
            printf("%d", i);
            na--;
            if (na)
            {
               printf(", ");
            }
        }
        
    }
    printf("}\n");

    printf("B = {");
    for (int i = 0; i <= 30; i++)
    {
        if (b[i])
        {
            printf("%d", i);
            nb--;
            if (nb)
            {
               printf(", ");
            }
        }
        
    }
    printf("}\n");

    printf("U = {");
    for (int i = 0; i <= 30; i++)
    {
        if (uni[i])
        {
            printf("%d", i);
            nu--;
            if (nu)
            {
                printf(", ");
            }
        }
        
    }
    printf("}\n");

    printf("I = {");
    for (int i = 0; i <= 30; i++)
    {
        if (inter[i])
        {
           printf("%d", i);
           ni--;
           if (ni)
           {
               printf(", ");
           }
           
        }
        
    }
    printf("}\n");
    
}