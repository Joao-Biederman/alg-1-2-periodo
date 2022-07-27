#include <stdio.h>

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
        printf("%u! = %u\n", x, fat(x));
    }
    return 0;
}