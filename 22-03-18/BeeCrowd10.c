#include <stdio.h>

int main()
{
    int x, y;
    int cont = 1;

    scanf("%d %d", &x, &y);

    for(int i = 1; i <= y; i++) {

        if(cont < x){
            cont++;
            printf("%d ", i);
        }else if (cont == x){
            printf("%d\n", i);
            cont = 1;
        }
    }

    return 0;
}