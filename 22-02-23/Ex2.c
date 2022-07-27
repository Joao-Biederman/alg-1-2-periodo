#include <stdio.h>
#include <string.h>

int main(){
    int indice;
    char *p;
    char palavra1[30], palavra2[30];

    while (scanf("%s", palavra1) && strcmp(palavra1, "###"))
    {
        indice = 0;
        scanf("%s", palavra2);
        p = strstr(palavra1, palavra2);
        if (p)
        {
            indice = p - &palavra1[0] + 1;
        }
        printf("%d\n", indice); 

    }
    return 0;
}