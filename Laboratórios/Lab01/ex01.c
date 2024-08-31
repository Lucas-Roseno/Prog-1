# include <stdio.h>
#include <math.h>
int main ()
{
    int exercicio = 0;

    printf("\nDeseja executar qual exercício?(de 1 a 4) ");
    scanf("%d", &exercicio);


    switch (exercicio)
    {
    case 1:
        printf("\n-----EXERCICIO 1-----\n");
        int a, b, c;
        double desvioPadrao, media;
        printf("Digite o numero a: ");
        scanf("%d", &a);
        printf("Digite o numero b: ");
        scanf("%d", &b);
        printf("Digite o numero c: ");
        scanf("%d", &c);

        media = (a+b+c)/3.0;
        printf("\nA media dos valores é %.2lf",media);

        desvioPadrao = sqrt((pow((a-media), 2) + pow((b-media), 2) + pow((c-media), 2))/2);
        printf("\nDesvio padrao é %.2lf\n", desvioPadrao);
        
        break;
    case 2:
        int x;
        printf("Digite o valor x: ");
        scanf("%d", &x);
        if (((x+1)/((-2*x)+3)) <= 0)
        {
            printf("X satisfaz a inequação.\n");
        }else{
            printf("X NÃO satisfaz a inequação.\n");
        }
        
        break;
    case 3:
        float nota1, nota2, nota3;
        int tipoMedia;
        printf("Digite a nota 1: ");
        scanf("%f", &nota1);
        printf("Digite a nota 2: ");
        scanf("%f", &nota2);
        printf("Digite a nota 3: ");
        scanf("%f", &nota3);
        printf("\nQual tipo de média deseja utilizar? \n[1] - Aritmétrica\n[2] - Ponderada\n[3] - Harmônica\nResposta: ");
        scanf("%d", &tipoMedia);
        if (tipoMedia == 1)
        {
            printf("A média aritmétrica das notas é %.2f\n", (nota1 + nota2 + nota3)/3.0);
        } else if(tipoMedia == 2)
        {
            printf("A média ponderada das notas é %.2f\n", (nota1*3 + nota2*3 + nota3*4)/10.0);
        } else if(tipoMedia == 3)
        {
            printf("A média harmônica das notas é %.2f\n", (3.0/((1/nota1) + (1/nota2) + (1/nota3))));
        } else{
            printf("VALOR INVÁLIDO!");
        }
        break;
    case 4:
        char sexo;
        int tempoTrabalho;
        float salario;
        printf("Digite o sexo do funcionário [F/M]: ");
        scanf(" %c", &sexo);
        printf("Digite o tempo de trabalho: ");
        scanf("%d", &tempoTrabalho);
        printf("Digite o salário: ");
        scanf("%f", &salario);
        if (sexo == 'M' && tempoTrabalho > 15)
        {
            printf("O bônus do funcionário é R$%.2f.\n", salario*0.2);
        } else if (sexo == 'F' && tempoTrabalho > 10)
        {
            printf("O bônus da funcionária é R$%.2f.\n", salario*0.25);
        } else
        {
            printf("O bônus é R$100.00.\n");
        }
        
        
        break;
    default:
        printf("Erro!\n");
        break;
    }


    return 0;
}