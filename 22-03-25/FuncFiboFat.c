#include <stdio.h>

unsigned fib(unsigned n)
{
    unsigned old = 1, aux = 1;
    unsigned fibo = 1;

    for (int i = 3; i <= n; i++)
    {
        fibo += old;
        old = aux;
        aux = fibo;
    }

    return fibo;
}

unsigned fat(unsigned n)
{
    unsigned f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main(void){
    unsigned x;
    while (scanf("%u", &x) && x > 0)
    {
        printf("Fatorial  %u! = %u\n", x, fat(x));
        printf("Fibonacci %uº = %u\n", x, fib(x));
        printf("Soma = %u\n", (fib(x)+fat(x)));
    }
    return 0;
}