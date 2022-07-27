#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned a0: 1;
    unsigned a1: 1;
    unsigned a2: 1;
    unsigned a3: 1;
    unsigned a4: 1;
    unsigned a5: 1;
    unsigned a6: 1;
    unsigned a7: 1;
}CampoBit;

typedef union
{
    CampoBit CB;
    char C;
}Campo;

int main(){

    Campo campo;

    campo.C = '1';

    printf("%d", campo.CB.a0? 1:0);
    printf("%d", campo.CB.a1? 1:0);
    printf("%d", campo.CB.a2? 1:0);
    printf("%d", campo.CB.a3? 1:0);
    printf("%d", campo.CB.a4? 1:0);
    printf("%d", campo.CB.a5? 1:0);
    printf("%d", campo.CB.a6? 1:0);
    printf("%d", campo.CB.a7? 1:0);
    printf('\n');
    printf("%c\n", campo.CB);

    return 0;
}