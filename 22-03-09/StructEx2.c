#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
    int z;
} Ponto3D;

int main(){

    Ponto3D p1={0, 0, 0}, p2={0, 0, 0}, p3={0, 0, 0};
    double d12, d13, d23;

    while (scanf("%d %d %d", &p1.x, &p1.y, &p1.z) != EOF)
    {
        scanf("%d %d %d", &p2.x, &p2.y, &p2.z);
        scanf("%d %d %d", &p3.x, &p3.y, &p3.z);

        d12 = sqrt(pow((p2.x-p1.x), 2)+pow((p2.y-p1.y), 2)+pow((p2.z-p1.z), 2));
        d13 = sqrt(pow((p3.x-p1.x), 2)+pow((p3.y-p1.y), 2)+pow((p3.z-p1.z), 2));
        d23 = sqrt(pow((p3.x-p2.x), 2)+pow((p3.y-p2.y), 2)+pow((p3.z-p2.z), 2));

        if ((d12 >= d13 + d23) || (d13 >= d12 + d23) || (d23 >= d12 + d13))
        {
            printf("Não é triangulo\n");
        } else {
            printf("É triangulo\n");
        }

    }

    return 0;
}