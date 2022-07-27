// Beecrowd não ta aceitando, só Deus sabe o por que
#include <stdio.h>

typedef char TData;
typedef struct
{
    TData P[26];
    short top;
}STACK;
typedef struct
{
    TData P[26];
    short head;
    short tail;
}QUEUE;

void initStack(STACK *s){
    s->top = 0;
}

void initQUEUE(QUEUE *s){
    s->head = 0;
    s->tail = 0;
}

void push(STACK *s, TData x){
    s->P[s->top] = x;
    s->top++;
}

TData pop(STACK *s){
    TData r;
    r = s->P[s->top--];
    return r;
}

void inQueue(QUEUE *s, TData x){
    s->P[s->tail++] = x;
}

TData deQueue(QUEUE *s){
    TData r;
    r = s->P[s->head++];
    return r;
}

short montagem(QUEUE *entry, QUEUE *out)
{
    STACK reorg;
    initStack(&reorg);
    while(out->head != out->tail)
    {
        if (reorg.P[reorg.top] != out->P[out->head])
        {
            if (entry->head != entry->tail)
            {
                push(&reorg, deQueue(entry));
                printf("I");
            } else 
            {
                return 1;
            }
        } else
        {
            pop(&reorg);
            deQueue(out);
            printf("R");
        }
    }
    printf("\n");
    return 0;
}

int main(){

    QUEUE entrada, saida;
    TData x;
    short vagao;

    while (scanf("%hd", &vagao) && vagao)
    {
        initQUEUE(&entrada);
        initQUEUE(&saida);
        
        getchar();
        for (int i = 0; i < vagao; i++)
        {
            scanf("%c", &x);
            getchar();
            inQueue(&entrada, x);
        }
        for (int i = 0; i < vagao; i++)
        {
            scanf("%c", &x);
            getchar();
            inQueue(&saida, x);
        }

        if (montagem(&entrada, &saida))
            printf(" Impossivel\n");
    }
    return 0;
}