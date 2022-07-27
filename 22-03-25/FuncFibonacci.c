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

int main(void){
    unsigned n;

    while (scanf("%u", &n) && n > 0)
    {
        printf("%uº = %u\n", n, fib(n));
    }
}