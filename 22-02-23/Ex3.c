#include <stdio.h>
#include <string.h>

char nome[51] = {""}, abrev[51] = {""};

int main(){

    int i, n, j, p, final;

    char *a, conect[51] = {""};

    while(scanf("%[^\n]s", nome) && strcmp(nome, "$$$")){

        getchar(); // limpa o buffer do teclado

        j = n = strlen(nome);

        a = strstr(nome, " de ");
        if(a){
            conect[0] = '\0';
            strncpy(conect, a, 4);
            printf("conectivo = %s\n", conect);
            nome[a - nome] = '\0';
            strcat(nome, a + 3);
            printf("%s\n\n", nome);
        }

        a = strstr(nome, " da ");
        if(a){

            conect[0] = '\0';
            strncpy(conect, a, 4);
            printf("conectivo = %s\n", conect);
            nome[a - nome] = '\0';
            strcat(nome, a + 3);
            printf("%s\n\n", nome);
        }

        a = strstr(nome, " das ");
        if(a){

            conect[0] = '\0';
            strncpy(conect, a, 5);
            printf("conectivo = %s\n", conect);
            nome[a - nome] = '\0';
            strcat(nome, a + 4);
            printf("%s\n\n", nome);
        }

        a = strstr(nome, " do ");
        if(a){

            conect[0] = '\0';
            strncpy(conect, a, 4);
            printf("conectivo = %s\n", conect);
            nome[a - nome] = '\0';
            strcat(nome, a + 3);
            printf("%s\n\n", nome);
        }

        a = strstr(nome, " dos ");
        if(a){

            conect[0] = '\0';
            strncpy(conect, a, 5);
            printf("conectivo = %s\n", conect);
            nome[a - nome] = '\0';
            strcat(nome, a + 4);
            printf("%s\n\n", nome);
        }

        a = strstr(nome, " e ");
        if(a){

            conect[0] = '\0';
            strncpy(conect, a, 3);
            printf("conectivo = %s\n", conect);
            nome[a - nome] = '\0';
            strcat(nome, a + 2);
            printf("%s\n\n", nome);
        }

        do {
            j--;
        } while (nome[j] != ' ');
        strncpy(abrev, &nome[j+1], n-j);
        strcat(abrev,", ");
        strncat(abrev, " ", 1);
        strcat(abrev, " ");

        printf("%s\n", abrev);
    }

    return 0;

}