#include <stdio.h>
#include <string.h>

int main(){
    char num[100];
    char result[200];
    int x, tamanho, uni, aux;

    while (scanf("%s", num) && strcmp(num, "@"))
    {
        tamanho = strlen(num);
        scanf("%d", &x);
        int mult, v1 = 0, sobra;
        for (int i = tamanho - 1, j = 0; i >= 0; i--, j++)
        {
            uni = num[i] - 48;
            mult = uni * x + v1;

            v1 = mult / 10;
            sobra = mult % 10;

            result[j] = sobra + 48;
        }

        tamanho = strlen(result);

        for (int i = 0, j = tamanho - 1; i < j; i++, j--)
        {
            aux = result[j];
            result[j] = result[i];
            result[i] = aux;
        }
        
        //Incompleto - Somar o v1 no final
        printf("%d %s\n",tamanho, result);
        
        printf("\n");
    }
    

    return 0;
}