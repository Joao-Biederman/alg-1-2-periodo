#include <string.h>
#include <stdio.h>

int main()
{
    int n, len;
    char grande[100];
    char *p; 

    while(scanf("%d %s", &n, grande) && n != 0)
    {

        printf("%d %s\n", n, grande);
        len = strlen(grande);

        for(int i = 0; i < len; i++)
        {
            if(grande[i] == n)
            {
                printf("%d ", i);
            }
            printf("%d ", i);
        }
    }
    return 0;
}