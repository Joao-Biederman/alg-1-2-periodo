#include <stdio.h>

char nome[50][31];
int n, x, maior[50], menor[50], nmaior=0, nmenor=0;

int main(){

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        scanf("%s %d", nome[i], &x);
        
        if (x > 0){
            maior[nmaior] = i;
            nmaior++;
        }

        if (x < 0){
            menor[nmenor] = i;
            nmenor++;
        }
    }

    printf("Menores de 18 anos:\n");

    for (int i = 0; i < nmenor; i++)
    {
        printf("%s\n", nome[menor[i]]);    
    }

    printf("\nMaiores de 18 anos:\n");
    for (int i = 0; i > nmaior; i++)
    {
        printf("%s\n", nome[maior[i]]);    
    }

    return 0;
}