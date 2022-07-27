#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* arquivo;
    char fileOut[16] = "ocorrencias.txt";
    char fileIn[20] = "Exercícios.txt";
    short contNum[10], contLetra[25];

    if ((arquivo = fopen(fileIn, "r+")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}
    for (int i = 0; i < 11; i++)
    {
        contNum[i] = 0;

        fseek(arquivo, 0, SEEK_SET);
        while(1)
        {
            if (i+48 == fgetc(arquivo))
            {
                contNum[i]++;
            }
            
            if (feof(arquivo))
            {
                break;
            }   
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        contLetra[i] = 0;

        fseek(arquivo, 0, SEEK_SET);
        while(1)
        {
            if (i+65 == toupper(fgetc(arquivo)))
            {
                contLetra[i]++;
            }
            
            if (feof(arquivo))
            {
                break;
            }   
        }
    }

    fclose(arquivo);

    if ((arquivo = fopen(fileOut, "w")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}
    fprintf(arquivo, " Caractere | Ocorrências \n");
    fprintf(arquivo, "=========================\n");
    for (int i = 0; i <= 9; i++)
        fprintf(arquivo, "|    %d     |     %3.hd\n", i, contNum[i]);

    for (int i = 65; i <= 90; i++)
        fprintf(arquivo, "|    %c     |     %3.hd\n", i, contLetra[i-65]);
    fprintf(arquivo, "=========================\n");
    fclose(arquivo);    

    return 0;
}