#include <stdio.h>

typedef struct
{
    int num;
    int den;
} TRacional;

int main(){

    TRacional x={0, 0}, y={0, 0}, r={0, 0}, redu={0, 0};
    int num, resto;
    char op;

    scanf("%d", &num);

    for (int i = 0; i < num; i++)    
    {
        scanf("%d / %d %c %d / %d", &x.num, &x.den, &op, &y.num, &y.den);

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
        
        redu.num = r.num/n;
        redu.den = r.den/n;

        if (redu.den < 0)
        {
            redu.den = redu.den*(-1);
            redu.num = redu.num*(-1);
        }
        
        printf("%d/%d = %d/%d\n",r.num, r.den, redu.num, redu.den);
    }
    
    return 0;
}