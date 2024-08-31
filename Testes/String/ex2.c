#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[20] = "";
    int cont = 0;
    printf("Digite uma string: ");
    fgets(string, 20, stdin);
    string[strlen(string) - 1] = '\0';
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == 'a')
        {
            string[i] = 'b';
            cont++;
        }   
    }
    printf("A string modificada é igual a: %s\nNúmero de letras modificadas: %d\n", string, cont);

    return 0;
}