#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_maiusculo(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
    }
}

int main()
{
    char string[30] = {""}, string_cripto[30] = {""};
    printf("Digite a string que deseja criptografar: ");
    fgets(string, 30, stdin);
    string[strlen(string) - 1] = '\0';
    int tamanho_string = strlen(string);
    string_maiusculo(string);


    for (int i = 0; i < strlen(string); i++)
    {
        if (string[tamanho_string - (i + 1)] == 'A' || string[tamanho_string - (i + 1)] == 'E'
        || string[tamanho_string - (i + 1)] == 'I' || string[tamanho_string - (i + 1)] == 'O'
        || string[tamanho_string - (i + 1)] == 'U' || string[tamanho_string - (i + 1)] == ' ')
        {
            string_cripto[i] = string[tamanho_string - (i + 1)];    
        }else{
            string_cripto[i] = '#';
        }
    }

    printf("A string cripitografada é: \n%s\n", string_cripto);

    return 0;
}