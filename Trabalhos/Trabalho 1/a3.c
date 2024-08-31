// Exercício 3: O Código Secreto de Avalon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100


void removerAcentos (char *string)
{
    char c;
    int cont = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        int entrou_for = 0;
        c = string[i];
        char tabela[42][4] =
        {
            {"áa"}, {"àa"}, {"âa"}, {"ãa"},
            {"ÁA"}, {"ÀA"}, {"ÂA"}, {"ÃA"},
            {"ée"}, {"èe"}, {"êe"}, {"ẽe"},
            {"ÉE"}, {"ÈE"}, {"ÊE"}, {"ẼE"},
            {"íi"}, {"ìi"}, {"îi"}, {"ĩi"},
            {"ÍI"}, {"ÌI"}, {"ÎI"}, {"ĨI"},
            {"óo"}, {"òo"}, {"ôo"}, {"õo"},
            {"ÓO"}, {"ÒO"}, {"ÔO"}, {"ÕO"},
            {"úu"}, {"ùu"}, {"ûu"}, {"ũu"},
            {"ÚU"}, {"ÙU"}, {"ÛU"}, {"ÛU"},
            {"çc"}, {"ÇC"}
        };

        for (int j = 0; j < 42; j++)
        {
            if (c == tabela[12][0] || c == tabela[16][0])
            {
                c = tabela[j][3];
                string[cont] = c;
                cont++;
                entrou_for++;
            }else if (c == tabela[j][0])
            {
                c = tabela[j][2];
                string[cont] = c;
                cont++;
                entrou_for++;
            }       
        }
        if (entrou_for == 0)
        {
            string[cont] = c;
            cont++;
        }
        
    }
}

char *verificar_palindromo(char *string) {
    char string_reversa[TAM] = {""};
    int cont = 0;
    removerAcentos(string); // Remover acentos
    printf("%s\n", string);
    for (int i = 0; i < strlen(string); i++) {
        if (isalnum(string[i])) {
            string[cont] = tolower(string[i]);
            cont++;
        }
    }
    string[cont] = '\0';
    for (int i = 0; i < strlen(string); i++) {
        string_reversa[i] = string[strlen(string) - (i + 1)];
    }

    if (strcmp(string, string_reversa) == 0) {
        return "True";
    }
    return "False";
}

int main() {
    char frase[TAM] = {""};
    printf("Exercício 3: O Código Secreto de Avalon\n\nDigite a frase: ");
    fgets(frase, 100, stdin);
    frase[strlen(frase) - 1] = '\0';
    printf("%s\n", verificar_palindromo(frase));

    return 0;
}