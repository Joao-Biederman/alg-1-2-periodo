#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* in;
    char imagefilename[256];
    char c;
    int pos;

    // Verifica se o número de parâmetros passados esta correto
    if(argc != 2) // são dois parâmetros: ./<programa> <arq>, nesta ordem
    {
        printf("Erro: Número de parâmetros incorreto.\n");
        exit(1);
    }

    // obtém o nome do arquivo de entrada
    strcpy(imagefilename, argv[1]);

    // tenta abrir o arquivo de entrada para leitura
    in = fopen(imagefilename, "rb");
    if (!in)
    {
        printf("Erro: Não foi possível abrir o arquivo %s\n", imagefilename);
        exit(1);
    }
    
    scanf("%d", &pos);

    // imprime o texto escondido na imagem.
    fseek(in, -pos, SEEK_END);
    while (1)
    {
        fread(&c, 1, 1, in);
        if (!feof(in))
            printf("%c", c);
        else
            break;
    }
    printf("\n");
    fclose(in);

    return 0;
}