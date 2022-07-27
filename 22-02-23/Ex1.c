#include <stdio.h>
#include <string.h>

int main(){
    char str1[30];
    char str2[30];
    char c;
    int len1, len2, i;

    while (scanf("%s", str1) && strcmp(str1, "@@@"))
    {
        scanf("%s", str2);
    
        len1 = strlen(str1);
        len2 = strlen(str2);

        if (len1 != len2)
        {            
            printf("NAO\n");   
        } else
        {            
            i=1;
            while (i++ <= len1 && strcmp(str1, str2) != 0)
            {
                c = str1[0];
                strncpy(str1, &str1[1], len1 -1);
                str1[len1-1] = c;
            }

            (i > len1) ? printf("NAO\n") : printf("SIM\n");
            
        }
    }
    return 0;
}