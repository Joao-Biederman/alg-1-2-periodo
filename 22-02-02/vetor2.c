#include <stdio.h>

int main(){
    
    int V[20];  
    int x, i = 0;

    while(scanf("%d", &x) && x){
    
        V[i] = x;
        printf("| %d|\n", V[i]);
        i++;

    }

    return 0;
}
