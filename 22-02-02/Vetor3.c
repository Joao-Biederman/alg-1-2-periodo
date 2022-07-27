#include <stdio.h>

int main(){
    
    int n, acima[29], abaixo[29];
    int x=0;
    int y=0;    

    float V[30], media=0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){

        scanf("%f", &V[i]);
        media += V[i];
        
    }
    media = media/n;
    
    for(int i=0; i < n; i++){

        if (V[i] > media)
        {
            acima[x] = i;
            x++;
        }
        if(V[i] < media){
            abaixo[y] = i;
            y++;
        }

    }

    printf("Media do vetor: %.1f\nElementos acima da media:", media);

    for (int i = 0; i < x; i++)
    {
       if (i!=0)
        {
            printf(",");
        }
         
        printf(" %d", acima[i]);
    }
    
    printf("\nElementos abaixo da media:");
    
    for (int i = 0; i < y; i++)
    {
        if (i!=0)
        {
            printf(",");
        }
        
        printf(" %d", abaixo[i]);
    }

    printf("\n");

    return 0;
}
