#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main()
{
    char nome[TAMn];
    long long cpf;
    int prioridade, nitens, caixa, quanCaixas;
    listCaixa listaCaixas;
    criarListCaixa(&listaCaixas);

    printf("Quantidade de caixas (valor fixo durante o programa): ");
    scanf("%d", &quanCaixas);
    while (quanCaixas < 0);
    {
        printf("Quantidade de caixas não pode ser menor que 0!\n"
               "Digite um valor maior que 0:  ");
        scanf("%d", &quanCaixas);
    }

    printf("\n");
    for (int i = 0; i < quanCaixas; i++)
    {
        inserirFimCaixas(&listaCaixas);
    }
    mostrarCaixas(&listaCaixas);

    while (1)
    {
        int opcao;
        printf("0 - Sair\n");
        printf("1 - Cadastrar cliente.\n");
        printf("2 - Atender um cliente.\n");
        printf("3 - Abrir ou fechar um caixa.\n");
        printf("4 - Imprimir a lista de espera.\n");
        printf("5 - Imprimir o status do caixa\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 0:
            exit(0);
        case 1:
            printf("Nome: ");
            fgets(nome, TAMn, stdin);
            nome[strlen(nome) - 1] = '\0';
            printf("CPF: ");
            scanf("%lld", &cpf);
            printf("Prioridade (1 = alta; 2 = média; 3 = baixa)");
            scanf("%d", &prioridade);
            printf("Número de itens do carrinho: ");
            scanf("%d", &nitens);
            printf("Caixa escolhido: ");
            scanf("%d", &caixa);
            do
            {
                printf("Caixa não existe!\nDigite um caixa válido: ");
                scanf("%d", &caixa);
            } while (caixa > quanCaixas);
            inserirIniFila(&listaCaixas, nome, cpf, prioridade, nitens, caixa);
            mostrarUmCaixa(&listaCaixas, caixa);

            break;

        case 3:
            int numCaixa;
            printf("\nAbrir = 1, Fechar = 0\nOpção: ");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                printf("Qual caixa deseja abrir: ");
                scanf("%d", &numCaixa);
                abrirCaixa(&listaCaixas, numCaixa);
            }
            else
            {
                printf("Qual caixa deseja fechar: ");
                scanf("%d", &numCaixa);
                fecharCaixa(&listaCaixas, numCaixa);
            }

        default:
            break;
        }
    }

    return 0;
}