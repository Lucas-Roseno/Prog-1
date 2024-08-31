/*
6. Escreva um programa em C que calcule o máximo divisor comum (MDC) de dois
números de forma recursiva. A assinatura da função deve ser int mdc(int a, int
b), onde a e b representam os 2 números cujo MDC se deseja saber e o número
retornado pela função é o MDC de a e b
*/
# include <stdio.h>
int mdc (int a, int b)
{
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}
int main ()
{
    int a = 0, b = 0, divisor = 2;
    printf("\nDigite o valor de a: ");
    scanf("%d", &a);

    printf("\nDigite o valor de b: ");
    scanf("%d", &b);

    printf("O mdc de %d e %d = %d\n", a, b, mdc(a, b));

    return 0;
}