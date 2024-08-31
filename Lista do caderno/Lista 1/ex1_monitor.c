#include <stdio.h>
#include <math.h>

int main ()
{
    float ang, a, b, t, somat = 0;
    int num;

    printf("Digite o valor do ângulo, em graus:\n ");
    scanf("%f", &ang);
    printf("Quantos termos você deseja na equação?"); 
    scanf("%d", &num);

    b = (ang * M_PI / 180);

    for (int i = 0; i < num; i++) {
        t = pow(-1, i) * pow(b, 2 * i + 1) / tgamma(2 * i + 1);
        somat += t;
    }
    
    printf("sin(x) = %f\n", somat);
    printf("sin(x) da biblioteca math.h = %f\n", sin(b));


    return 0;
}
