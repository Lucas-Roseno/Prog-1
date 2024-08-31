# include <stdio.h>
#include <math.h>
int main () 
{
    long double x = 0, sin_x = 0;
    int n = 0, n_termos = 0;
    printf("\nDigite o valor do grau e a quantidade de termos da série separados por espaço: \n");
    scanf("%Lf %d", &x, &n);
 
    x = (x*M_PI/180); //radianos

    int cont_fatorial = 3, fatorial = cont_fatorial, sinal = -1;
    long double pot_x = x;
    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i < cont_fatorial; i++) // fatorial
        {
            fatorial = fatorial * i;
        }
        sin_x += (sinal *(pow(x, cont_fatorial)/fatorial));
        sinal = sinal * (-1);
        cont_fatorial += 2;
        n_termos++;
    }
    printf("\nValor de seno de x calculado com %d termos: %Lf\nValor de seno de x pela biblioteca math: %lf\n",
    n_termos, sin_x, sin(x));
    printf("Erro: precisão na casa decimal.");
    return 0;
}
