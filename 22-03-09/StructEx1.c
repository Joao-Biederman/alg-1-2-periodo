#include <stdio.h>

typedef struct
{
    int num;
    int den;
} TRacional;

int main(){

    TRacional x={0, 0}, y={0, 0}, r={0, 0};
    int resto;
    char op;

    while (scanf("%d/%d %c %d/%d", &x.num, &x.den, &op, &y.num, &y.den) != EOF)
    {
        switch (op)
        {
        case '+':
            r.num = (x.num*y.den)+(x.den*y.num);
            r.den = x.den*y.den;
            break;
        
        case '-':
            r.num = (x.num*y.den)-(x.den*y.num);
            r.den = x.den*y.den;
            break;

        case '*':
            r.num = x.num*y.num;
            r.den = x.den*y.den;
            break;
        
        case '/':
            r.num = x.num*y.den;
            r.den = x.den*y.num;
            break;

        default:
            printf("Erro: Operação Invalida");
        }

        int n = r.num;
        int d = r.den;

        do
        {
            resto = n % d;
            n = d;
            d = resto;
        } while (d != 0);
        
        r.num = r.num/n;
        r.den = r.den/n;

        printf("%d/%d\n",r.num, r.den);

    }
    
    return 0;
}