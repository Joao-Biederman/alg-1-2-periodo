#include <stdio.h>
#include <string.h>

int main(){
    char original[100], corrigida[100];
    char a, b;
    int len;


    while(scanf("%[^\n]s", original) != EOF){    //Lê diversas strings repetindo o ciclo até ser lido a entrada EOF
        
        getchar(); //Limpa o buffer do teclado
        scanf("%c %c", &a, &b); //Lê duas letras, 'a' é a letra a ser encontrada na palavra e 'b' é a letra que devemos substituir 'a' na string 's'
        getchar();

        //printf("%s. %c, %c\n", s, a, b); //Teste para procurar erros na escrita

        len = strlen(original);
        for (int i = 0; i < len; i++)
        {
            if (original[i] == a)
            {
                corrigida[i]=b;
            } else {
                corrigida[i] = original[i];
            }
        }
        printf("Origina = %s\n", original);
        printf("Corrigida = %s\n\n", corrigida);

    }


    return 0;
}