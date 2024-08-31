#include <stdio.h>
#include <math.h>

// Função para calcular o fatorial de um número inteiro positivo
int fatorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main() {
    double x, seno_x = 0;
    int n, i;

    // Recebendo o valor de x e n do usuário
    printf("Digite o valor de x (em graus): ");
    scanf("%lf", &x);
    printf("Digite o numero de termos (n): ");
    scanf("%d", &n);

    // Convertendo x para radianos
    x = x * M_PI / 180.0;

    // Calculando o seno aproximado de x com n termos
    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            seno_x += pow(x, 2 * i + 1) / fatorial(2 * i + 1);
        else
            seno_x -= pow(x, 2 * i + 1) / fatorial(2 * i + 1);
    }

    // Calculando o valor real do seno usando a biblioteca math.h
    double seno_real = sin(x);

    // Calculando a diferença entre o valor calculado e o valor real
    double diferenca = fabs(seno_x - seno_real);

    // Imprimindo os resultados
    printf("Valor aproximado do seno de x com %d termos: %.6lf\n", n, seno_x);
    printf("Valor real do seno de x: %.6lf\n", seno_real);
    printf("Diferenca entre os valores: %.6lf\n", diferenca);

    return 0;
}
