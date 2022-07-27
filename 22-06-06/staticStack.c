#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false, true} bool;

typedef short TData;

// definição do tamanho da pila
#define STACK_SIZE 20;

// definição do tipo pilha
typedef struct
{
    TData P[20];
    short top;
}STACK;


void initStack(STACK *s){
    s->top = 0;
}

bool emptyStack(STACK s){
    return s.top == 0;
}

bool fullStack(STACK s){
    return s.top == STACK_SIZE;
}

void printStack(STACK s){
    printf("top -> ");
    while (--s.top >= 0)
    {
        printf("%hd", s.P[s.top]);
        if (s.top > 0)
            printf(", ");
        
    }
    printf("\n");
    return;
}

void push(STACK *s, TData x){
    // Deve-se verificar se a pilha esta cheia antes de tentar usar esta função
    s->P[s->top++] = x;
}

TData pop(STACK *s){
    // Deve-se verificar se a pilha esta vazia antes de tentar usar esta função
    TData r;
    s->top--;
    r = s->P[s->top];
    return r;
}

int main(){
    TData a;
    STACK pilha;
    printf("Teste da pilha\n");

    printf("Teste de Empilhameto\n");
    srand(time(NULL)); // semente para números aleatórios
    initStack(&pilha);
    while (!fullStack(pilha))
    {
        a = rand() % STACK_SIZE + 1;
        push(&pilha, a);
        printStack(pilha);
    }

    while (!emptyStack(pilha))
    {
        pop(&pilha);
        printStack(pilha);
    }
    
    return 0;
}