#include <stdio.h>
int main () 
{
    float nota1 = -1, nota2 = -1;
    while (nota1 < 0 || nota1 > 10)
    {
        printf("\nDigite a primeira nota: ");
        scanf("%f", &nota1);
        if (nota1 < 0 || nota1 > 10)
        {
            printf("NOTA INVÁLIDA!\n");
        }
    }
    while (nota2 < 0 || nota2 > 10)
    {
        printf("\nDigite a segunda nota: ");
        scanf("%f", &nota2);
        if (nota2 < 0 || nota2 > 10)
        {
            printf("NOTA INVÁLIDA!\n");
        }
    }
    printf("\nA média das notas semestrais é %.2f\n", (nota1 + nota2)/2);
    
    
}