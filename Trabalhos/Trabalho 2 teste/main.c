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
    while (quanCaixas < 0)
    {
        printf("Quantidade de caixas não pode ser menor que 0!\n"
               "Digite um valor maior que 0:  ");
        scanf("%d", &quanCaixas);
    }

    for (int i = 0; i < quanCaixas; i++)
    {
        inserirFimCaixas(&listaCaixas);
    }
    mostrarCaixas(&listaCaixas);
    printf("\n");
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

            while (prioridade < 1 || prioridade > 3)
            {
                printf("Prioridade (1 = alta; 2 = média; 3 = baixa): ");
                scanf("%d", &prioridade);
            }

            printf("Número de itens do carrinho: ");
            scanf("%d", &nitens);

            printf("Caixa escolhido: ");
            scanf("%d", &caixa);

            while (caixa > quanCaixas || caixa < 0)
            {
                printf("Caixa não existe!\nDigite um caixa válido: ");
                scanf("%d", &caixa);
            }
            inserirOrdFila(&listaCaixas, nome, cpf, prioridade, nitens, caixa);
            mostrarUmCaixa(&listaCaixas, caixa);
            caixa = prioridade = 0;
            break;

        case 2: // atender
            while (caixa <= 0 || caixa > quanCaixas)
            {
                printf("Caixa: ");
                scanf("%d", &caixa);
            }
            desenfileirar(&listaCaixas, caixa, 1);
            caixa = 0;
            break;

        case 3:
            int numCaixa = -1;
            printf("\nAbrir = 1, Fechar = 0\nOpção: ");
            scanf("%d", &opcao);

            while (numCaixa < 1 || numCaixa > quanCaixas)
            {
                printf("Número do caixa: ");
                scanf("%d", &numCaixa);
            }

            switch (opcao)
            {
            case 0:
                printf("\nCaixa %d fechado.", numCaixa);
                fecharCaixa(&listaCaixas, numCaixa);
                break;
            case 1:
                abrirCaixa(&listaCaixas, numCaixa);
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
            }
            break;
        case 5:
            while (caixa <= 0 || caixa > quanCaixas)
            {
                printf("Caixa: ");
                scanf("%d", &caixa);
            }
            mostrarUmCaixa(&listaCaixas, caixa);
            caixa = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}
// parei na parte de fechar um caixa se tiver 2 caixas o 2 fechado e tentar
// fechar o primeiro não acontece nada, corrigir