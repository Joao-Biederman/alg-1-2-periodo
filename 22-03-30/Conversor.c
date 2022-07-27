// Chamadas Recursivas
// Função conversora de Binário -> Decimal

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 8

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// Funcão recursiva para conversão de Binários
// void bit2dec(char bits[MAX], int n)
// Parametros:
//      bits : valor em binario a ser convertido
//      n : comprimento da cadeia de caracteres
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int bit2dec(char bit[MAX], int n){
    int convertido;
    n--;
    convertido = (bit[0]-48)*pow(2, n);
    if (n >= 1)
        convertido += bit2dec(&bit[1], n);
    return convertido;
}

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// Funcão recursiva para conversão de Decmais
// void dec2bit(int decimal, char *end)
// Parametros:
//      decimal : valor em decimal a ser convertido
//      end : posição da variavel
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
int dec2bit(int decimal, char *end){

}

int main(){
    char bits[MAX];
    int n, decimal;
    char decisao;

    printf("Digite 1 para decimal e 2 para binario: ");
    while (scanf("%s", decisao) != EOF)
    {
        getchar();
        switch (decisao){
        case 1:
            /* code */
            break;
        case 2:
            n = strlen(bits);
            decimal = bit2dec(bits, n);
    
            printf("O valor de %s em decimal é : %d\n", bits, decimal);
            break;
        }
        printf("Digite 1 para decimal e 2 para binario: ");
    }

    return 0;
}