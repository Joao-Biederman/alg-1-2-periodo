#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;
    char filename[50] = "maiscula.txt", frase[101];

    if ((arquivo = fopen(filename, "w")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}
    for (int i = 0, j; i < 5; i++)
    {
        scanf("%s", frase);
        j=0;
        while (frase[j] != NULL)
        {
            fprintf(arquivo, "%c", toupper(frase[j]));
            j++;
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    return 0;
}