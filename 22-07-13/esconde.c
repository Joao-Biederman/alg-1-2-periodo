#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* in;
    FILE* out;
    char imagefilename[256];
    char textfilename[256];
    char outfilename[256];
    char c;
    int contFim = 0;

    // Verifica se o número de parâmetros passados esta correto
    if(argc != 4) // são quatro parâmetros: ./<programa> <arqImagem> <arqTexto> <arqDestino>, nesta ordem
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

    // obtém o nome do arquivo de saida    
    strcpy(outfilename, argv[3]);

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

    // obtém o nome do arquivo de textp
    strcpy(textfilename, argv[2]);

    // tenta abrir o arquivo de entrada para leitura
    in = fopen(textfilename, "rb");
    if (!in)
    {
        printf("Erro: Não foi possível abrir o arquivo %s\n", textfilename);
        exit(1);
    }

    // obtém o nome do arquivo de saida    
    strcpy(outfilename, argv[2]);

    while (1)
    {
        fread(&c, 1, 1, in);
        if (!feof(in))
        {
            fwrite(&c, 1, 1, out);
            contFim++;
        }
        else
            break;
    }
    printf("%d\n", contFim);
    fclose(in);
    fclose(out);
    // <programa> <imagem> <texto> <saida>
    // <imagem> -> <saida>; <texto> -> <saida>
    // cont número bytes imagem, para ler o texto basta abrir para leitura e ler a partir do byte em que termina a imagem.
    return 0;
}