#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcao;
    FILE *arq_vendedores;

    printf("Escolha uma opção:"
           "\n(a) cadastrar vendedor"
           "\n(b) cadastrar venda"
           "\n(c) consultar vendas de um funcionário em determinado mês"
           "\n(d) mostrar o número do vendendor que mais vendeu em determinado mês"
           "\n(e) mostrar o número do mês com mais venda"
           "\n(g) finalizar o programa\n");
    scanf("%c", &opcao);

    switch (opcao)
    {
    case 'a':
        arq_vendedores = fopen("arq_vendedores", "w+");
        if (!arq_vendedores)
        {
            printf("Erro na abertura do arquivo.");
            exit(1);
        }

        int cod_vend[4] = {0};
        for (int i = 0; i < 4; i++)
        {
            printf("Digite o código do vendedor %d: ", i + 1);
            scanf("%d", &cod_vend[i]);

            while (EOF)
            {
                if (cod_vend[i] == cod_vend[i - 1] || cod_vend[i] == cod_vend[i - 2] || cod_vend[i] == cod_vend[i - 3])
                {
                    printf("Código já cadastrado. Digite outro código: ");
                    scanf("%d", &cod_vend[i]);
                }
                else
                {
                    break;
                }
            }
            fprintf(arq_vendedores, "%d\n", cod_vend[i]);
        }
        fclose(arq_vendedores);
        break;

    case 'b':

    FILE *arq_vendas;
    if (!(arq_vendas = fopen("arq_vendas", "w")))
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    
    int mes = 0, codigo = 0;
    float vlr_venda = 0;
    printf("Digite o valor da venda: ");
    scanf("%f", &vlr_venda);
    fprintf(arq_vendas, "%f\n", vlr_venda);
    
    printf("Digite o código do vendedor: ");
    scanf("%d", &codigo);
    fprintf(arq_vendas,"%d\n", codigo);

    printf("Digite o mês da venda: ");
    scanf("%d", &mes);
    fprintf(arq_vendas,"%d\n", mes);

    break;
    default:
        break;
    }

    return 0;
}