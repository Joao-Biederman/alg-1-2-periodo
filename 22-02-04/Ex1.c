#include <stdio.h>

int main(){

    int n, nota[20];
    float media;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nota[i]);
        media += nota[i];
    }
    media = media/n;

    for (int i = 0; i < n; i++)
    {    
        printf("%d %.2f\n", nota[i], media);
    }

}