// Jogo batalha Naval contra o computador

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char **ship;
    char **shots;
    short boats;
    unsigned l;
} Sea;

int finished(Sea *P1, Sea *Pc)
{
    if (!P1->boats)
        return 2;
    else if (!Pc->boats)
        return 1;
    else
        return 0;    
}

void initShipBoard(Sea *C , unsigned size){
    C->ship = (char**)malloc(size*sizeof(char*));
    if (!C->ship)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        C->ship[i] = (char*)malloc(size*sizeof(char));
        if (!C->ship[i])
        {
            printf("Erro: Memória insuficiente!\n");
            exit(1);
        } else
        {
            C->ship[i][j] = ' ';
            j++;
        }
    }
    C->l = size;
    return;
}

void initSeaBoard(Sea *C , unsigned size){
    C->shots = (char**)malloc(size*sizeof(char*));
    if (!C->shots)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        C->ship[i] = (char*)malloc(size*sizeof(char));
        if (!C->shots[i])
        {
            printf("Erro: Memória insuficiente!\n");
            exit(1);
        } else
        {
            C->shots[i][j] = ' ';
            j++;
        }
    }
    C->l = size;
    return;
}

void initPCBoard(Sea *C , unsigned size){
    C->shots = (char**)malloc(size*sizeof(char*));
    if (!C->shots)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        C->shots[i] = (char*)malloc(size*sizeof(char));
        if (!C->shots[i])
        {
            printf("Erro: Memória insuficiente!\n");
            exit(1);
        } else
        {
            C->shots[i][j] = '?';
            j++;
        }
    }
    C->l = size;
    return;
}

void board(Sea *P1, Sea *PC)
{
    for (int i = 0; i < P1->l; i++)
    {
        for (int j = 0; j < P1->l; j++)
            printf(" ");// P1->ship[i][j]);
        
        printf("|| ");
        
        for (int j = 0; j < PC->l; j++)
        {
            printf("? ");
        }
        printf("\n");
    }
}

void fillBoard(Sea *P1, int i, int j)
{
    while ((i > 5 || j > 5) || (i < 1 || j < 1))
    {
        printf("Posição inserida invalida, insira novamente: ");
        scanf("%d %d", &i, &j);
    }
    while (P1->ship[i-1][j-1] == '0')
    {
        printf("Posição já ocupada, insira outra posição: ");
        scanf("%d %d", &i, &j);
    }
    P1->ship[i-1][j-1] = '0';
}

// =========================
// Main
// =========================

int main()
{
    char play;
    Sea p1, pc;
    int winner;

    printf("Deseja jogar? y/n ");
    while(scanf("%c", &play) && (play == 'y'))
    {
        initShipBoard(&p1, 5);
        initPCBoard(&pc, 5);
        p1.boats = pc.boats = 5;
        winner = 0;
        
        for (int i = 0, l, c; i < 5; i++)
        {
            board(&p1, &pc);
            printf("Preencha seu campo: ");
            scanf("%d %d", &l, &c);
            fillBoard(&p1, l, c);
        }
        board(&p1, &pc);

        short ai, aj;

        while (!winner)
        {
            printf("Escolha uma coordenada alvo: ");
            // scanf("%hd %hd", ai, aj);
            winner = 1;
            // shoot(%pc, ai, aj);

        }

        if (winner == 1)
            printf("O jogador ganhou!!\n\n");
        else if (winner == 2)
            printf("O computador ganhou!! Mais sorte na proxima vez.\n\n");
        
        printf("Deseja jogar novamente? y/n ");
    }
    
}