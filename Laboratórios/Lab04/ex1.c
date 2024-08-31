#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30

int analisa_string(char string[TAM])
{
    int contador[TAM] = {0}; 
    char caracteres_processados[TAM] = {0}; 
    int index = 0;

    for (int i = 0; i < strlen(string); i++)
    {
        int processado = 0;
        for (int k = 0; k < index; k++)
        {
            if (string[i] == caracteres_processados[k])
            {
                processado = 1;
                break;
            }
        }
        if (processado == 1)
            continue; //ignora oq está embaixo e volta para o início do for, incrementando o i

        for (int j = 0; j < strlen(string); j++)
        {
            if (string[i] == string[j])
            {
                contador[i]++;
            }
        }
        caracteres_processados[index] = string[i];
        index++;
        printf("%c = %d\n", string[i], contador[i]);
    }
    return 0;
}

int main()
{
    char string[TAM] = {0};
    printf("Digite a palavra que deseja analisar: ");
    fgets(string, TAM, stdin);
    string[strlen(string) - 1] = '\0'; 

    analisa_string(string);
    return 0;
}
