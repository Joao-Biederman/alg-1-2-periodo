//
#include <stdio.h>

//
typedef int PF();

int F1(int a)
{
    printf("F1 como %d\n", a);
    return 1;
}

int F2(int a)
{
    printf("F2 como %d\n", a);
    return 2;
}

int F3(int a)
{
    printf("F3 como %d\n", a);
    return 3;
}

int main()
{
    PF *functionVet[3];
    int opt;

    functionVet[0] = F1;
    functionVet[1] = F2;
    functionVet[2] = F3;

    printf("Escolha sua opção, 0, 1, 2: ");
    scanf("%d", &opt);
    if(opt >= 0 && opt < 3)
        functionVet[opt](opt);
    else
        printf("Opção inválida!\n");
    return 0;
}