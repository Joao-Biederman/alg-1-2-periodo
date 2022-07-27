#include <stdio.h>

int fat(int n){
    if (n <= 1)
        return 1;
    n *= fat(n-1);
    return n;
}

int main(){
    unsigned n;

    while(scanf("%u", &n) && n > 0)
        printf("%d\n", fat(n));

    return 0;
}