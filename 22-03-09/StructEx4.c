#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Tponto;

typedef struct 
{
    int m;
    int n;
    char janela[80][25];
} Window;

//80-25

int main(){

    Window j;
    Tponto p1, p2;

    memset(&j, '1', sizeof(Window));

    //leitura do tamanho da janela
    printf("Tamanho da janela: ");
    scanf("%d %d", &j.m, &j.n);

    //leitura dos pontos das extremidades da janela *
    printf("ponto superior e inferior: \n");
    scanf("%d %d", &p1.x, &p1.y);
    scanf("%d %d", &p2.x, &p2.y);

    for (int i = p1.x; i < p2.x; i++)
    {
        for (int k = p1.y; k < p2.y; k++)
        {
            j.janela[i][k] = '2';
        }
    }

    for (int i = 0; i < j.m; i++)
    {
        for (int k = 0; k < j.n; k++)
        {
            printf("%c", j.janela);
        }
        printf("\n");
    }
    
    


    return 0;
}