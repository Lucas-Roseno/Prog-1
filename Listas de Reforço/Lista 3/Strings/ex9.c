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
    char string[50] = {""};
    printf("Digite a frase: ");
    fgets(string, 50, stdin);
    string[strlen(string) - 1] = '\0';
    string_maiusculo(string);
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            string[i] = '\n';
        }
    }
    printf("%s\n", string);
    return 0;
}