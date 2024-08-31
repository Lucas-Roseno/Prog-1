# include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void main ()
{
    float ang = 0, radianos = 0, termo = 0, soma_termos = 0;
    int n_termos = 0;

    printf("Digite o valor do ângulo: ");
    scanf("%f", &ang);
    printf("Digite a quantidade de termos da equação: ");
    scanf("%d", n_termos);

    radianos = n_termos * M_PI/180;

    for (int i = 1; i <= n_termos; i++)
    {
        termo = pow(-1, i + 1) * pow(radianos, (i - 1) * 2) / tgamma((i - 1) * 2);
        soma_termos += termo;
    }
    printf("")
    

}