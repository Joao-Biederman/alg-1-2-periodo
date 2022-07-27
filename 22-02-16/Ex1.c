#include <stdio.h>

int main(){

    int i=0;
    float k, a[100], b[100];

    while (scanf("%f",&k) && k > 0)
    {        
        a[i] = k;

        if (((i+1) % 2) == 0 )
        {
            b[i] = k/2;
        } else {
            b[i] = k*3;
        }
        
        i++;
    }


    printf("   A        B\n");
    for (int j = 0; j < i; j++)
    {
        printf("%.4f %.4f\n", a[j], b[j]);
    }
    

    return 0;
}