#include <stdio.h>

int main(){
    int c, c2;
    int a[50], b[50], soma[50];

    scanf("%d", &c);
    c2 = c;

    for (int i = 0; i < c; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < c; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < c; i++)
    {
        soma[i] = a[i] + b[i];
    }

    printf("[");
    for (int i = 0; i < c; i++)
    {
        printf("%d", soma[i]);
        c2--;
        if (c2)
        {
            printf(", ");
        }
        
    }
    printf("]");

    return 0;
}