#include <stdio.h>
#include <math.h>

double calculo_fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calculo_fatorial(n - 1);
    }
}

int main() {
    double x;
    printf("Digite um número: ");
    scanf("%lf", &x);

    double somatorio = 0.0;
    double termo;
    int i = 0;

    do {
        termo = pow(x, i) / calculo_fatorial(i);
        somatorio += termo;
        i++;
    } while (fabs(somatorio - exp(x)) > 0.0001);

    printf("Número de termos necessários: %d\n", i);
    printf("Valor da expressão pelo somatório: %lf\n", somatorio);
    printf("Valor da expressão pela função exp(x): %lf\n", exp(x));

    return 0;
}
