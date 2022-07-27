#include <stdio.h>
#include <string.h>

int main()
{
    int n, lenght, i, j;
    char palavra[100], aux;

    scanf("%d", &n);

    for(int cont = 0; i < n; i++) {
        scanf(" %[^\n]", palavra);
        getchar();

        lenght = strlen(palavra);

        for (int i = 0; i < lenght; i++ ) {
           if ((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z')) {
                palavra[i] = palavra[i] + 3;
            }
        }
        for (i = 0, j = lenght-1; i < j; i++, j--){

            aux = palavra[j];
            palavra[j] = palavra[i];
            palavra[i] = aux;
        }
        for (i; i < lenght; i++ ){
            if ((palavra[i] >= 32 && palavra[i] <= 176 ))
                palavra[i] = palavra[i] - 1;
        }

        printf("%s\n", palavra);

        memset(palavra, '\0', sizeof(palavra));
    }
    return 0;
}