#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* arquivo;
    char filename[8] = "arq.txt";
    char x;

    if ((arquivo = fopen(filename, "w")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	
    }

    while (scanf("%c", &x) && x != '0')
    {
        fprintf(arquivo, "%c ", x);
    }
	fclose(arquivo);

    if ((arquivo = fopen(filename, "r")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}
	fclose(arquivo);

    return 0;
}