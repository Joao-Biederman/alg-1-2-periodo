#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char texto[2000], tautograma;
    int len, i, tauto;

    while (scanf("%[^\n]s", texto) && texto[0]!='*')
    {
        getchar();

        len = strlen(texto);
        i = len;
        tauto=1;

        tautograma = texto[0];
        //printf("%c\n", tautograma);

        while ((i > 0) && tauto)
        {
            if (texto[i] == ' '){
                if (texto[i+1] >= 90)
                {
                    if (texto[i+1]==tautograma || texto[i+1]==(tautograma+32))
                    {
                        tauto=1;
                    } else
                    {
                        tauto=0;
                    }
                }
                if (texto[i+1] < 96)
                {
                    if (texto[i+1]==tautograma || texto[i+1]==(tautograma-32))
                    {
                        tauto=1;
                    } else
                    {
                        tauto=0;
                    }
                }
            }
            i--;
        }
        tauto ? printf("Y\n"):printf("N\n");        
    }
    return 0;
}