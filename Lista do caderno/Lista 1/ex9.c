# include <stdio.h>
void main ()
{
    float total_compra = 0;
    char tipo_cliente;

    printf("Digite o valor total da compra: ");
    scanf("%f", &total_compra);

    printf("Digite o tipo de cliente:\n[C] - comum\n[F] - funcinários\n[E] - especiais\nDigite em maiúsculo: ");
    scanf(" %c", &tipo_cliente);

    switch (tipo_cliente)
    {
    case 'C':
        printf("O valor total = R$%.2f\n", total_compra);
        break;
    case 'F':
        printf("O valor total = R$%.2f\n", total_compra * 0.95);
        break;
    case 'E':
        printf("O valor total = R$%.2f\n", total_compra * 0.9);
        break;
    default:
        printf("ERRO. Programa finalizado.\n");
        break;
    }
}