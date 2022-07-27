#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* in;
    FILE* out;
    char infilename[256];
    char outfilename[256];
    char c;

    // Verifica se o número de parâmetros passados esta correto
    if(argc != 3) // são três parâmetros: ./<programa> <arqOrigem> <arqDestino>, nesta ordem
    {
        printf("Erro: Número de parâmetros incorreto.\n");
        exit(1);
    }

    // obtém o nome do arquivo de entrada
    strcpy(infilename, argv[1]);

    // tenta abrir o arquivo de entrada para leitura
    in = fopen(infilename, "rb");
    if (!in)
    {
        printf("Erro: Não foi possível abrir o arquivo %s\n", infilename);
        exit(1);
    }
    
    strcpy(outfilename, argv[2]);

    // tenta abrir o arquivo de saida para escrita
    out = fopen(outfilename, "wb");
    if (!out)
    {
        printf("Erro: Não foi possível abrir o arquivo %s\n", outfilename);
        exit(2);
    }
    
    // copia o arquivo inicial para o arquivo final;
    while (1)
    {
        fread(&c, 1, 1, in);
        if (!feof(in))
            fwrite(&c, 1, 1, out);
        else
            break;
    }
    fclose(in);
    fclose(out);

    return 0;
}