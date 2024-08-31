#include <stdio.h>
int main()
{
    // int mat[2][3], *p, cont, var, menor = 32676, i, j;
    // p = *mat;
    // for (cont = 0; cont < 6; cont++, p++)
    // {
    //     printf("Digite o elemento %d: ", cont + 1);
    //     scanf("%d", &var);
    //     *p = var;
    //     if (*p <= menor)
    //         menor = *p;
    // }
    // printf("\nO menor valor da matriz é: %d", menor);
    // printf("\nos elementos da matriz são: \n");
    // for (i = 0; i < 2; i++)
    // {
    //     for (j = 0; j < 3; j++)
    //     {
    //         printf("\nmat[%d][%d] =%d", i, j, mat[i][j]);
    //     }
    // }
    int *x, cont = 2;
    x = &cont;
    printf("\n%p\n", &x);
    return 0;
}