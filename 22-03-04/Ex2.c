#include <stdio.h>
#include <string.h>

int main(){
    char palavra[50];
    int len, destino;


    while(scanf("%[^\n]s", palavra) != EOF){
        getchar();

        len = strlen(palavra);
        destino = 0;

        while(palavra[destino] != ' '){
            destino++;
        }
        strcpy(palavra, &palavra[destino+1]);

        //printf("Palavra = %s\n\n", palavra); //Teste retirada espaços da frente da palavra
        destino = len - 1;
        
        while (palavra[destino] != ' ')
        {
            destino--;
        }
        palavra[destino] = '\0';
        
        printf("Palavra = %s\n\n", palavra);printf("Palavra = %s\n\n", palavra);   

    }

    return 0;
}