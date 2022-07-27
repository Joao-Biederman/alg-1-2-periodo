#include <stdio.h>
#include <string.h>

int main(){
    int casos, atual, destino, k, n;
    char sobrevivente[10000];

    scanf("%d",&casos);

    for (int i = 0; i < casos; i++)
    {
        scanf("%d %d", &n, &k);

        for (int l = 0; l < n; l++)
        {
            sobrevivente[l] = l+1;
        }
        
        atual=0;

        while (n > 1)
        {
            destino = (atual+k)%n;
            strcpy(&sobrevivente[atual], &sobrevivente[destino]);
            atual = destino;
            n--;
        }
        
        printf("Case %d: %d\n", i+1, sobrevivente[0]);

    }
    
    return 0;
}