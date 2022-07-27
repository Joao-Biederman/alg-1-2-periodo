#include <stdio.h>

int main(){

    int i = 0, acima = 0;
    int k, a[40];
    float med = 0;

    while (scanf("%f",&k) && k > 0)
    {
        med += k;
        a[i] = k;
        
        i++;
    }
    med = med/i;

    for (int j = 0; j < i; j++)   //Error -> Segmentation fault (core dumped)
    {
        if (a[j] > med)
        {   
            acima++;
        }
   }
    

    printf("Média da turma = %.1f\n", med);
    printf("Número de alunos com nota acima da média = %d\n", acima);

    return 0;
}