#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome_produto[5][30] = {""};
    float preco_produto[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o nome do %d produto: ", i+1);
        fgets(nome_produto[i], 30, stdin);

        printf("Digite o preço do %d produto: ", i+1);
        scanf("%f", &preco_produto[i]);
        printf("\n");
        while (getchar() != '\n');
    }
    int menor_50 = 0;
    float media_100 = 0, cont_100 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (preco_produto[i] < 50)
        {
            menor_50++;
        }else if (preco_produto[i] > 50 && preco_produto[i] < 100)
        {
            printf("%s", nome_produto[i]);
        }else if (preco_produto[i] > 100)
        {
            media_100 += preco_produto[i];
            cont_100++;
        }
    }
    printf("Há %d com preço abaixo de R50,00.\n", menor_50);
    printf("A media do preço dos produtos maiores que R$100,00 = %.2f\n", media_100/cont_100);
    

    return 0;
}