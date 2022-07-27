#include <stdio.h>

int main(){

    int x;
    float a[40],b[40];

    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        scanf("%f %f", &a[i], &b[i]);
    }

    for (int i = 0; i < x; i++)
    {
        printf("%.2f\n", a[i]+b[i]);
    }

    return 0;
}