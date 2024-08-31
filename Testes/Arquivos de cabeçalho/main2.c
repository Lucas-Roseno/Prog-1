#include<stdio.h>
#include "geometria.h"
    int main()
{
    float base, altura, raio;
    printf("Digite a base e altura do retângulo: ");
    scanf("%f %f", &base, &altura);
    printf("Área do retângulo: %.2f\n",
           calcularAreaRetangulo(base, altura));
    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);
    printf("Área do círculo: %.2f\n", calcularAreaCirculo(raio));
    return 0;
}