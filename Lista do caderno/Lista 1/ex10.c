/*
10. Faça um algoritmo que receba uma sequência de números e retorne o maior e o
menor número da sequência. A quantidade de números n é fornecida pelo
usuário.
*/
# include <stdio.h>
int main ()
{
    int maior = 0, menor = 0, repeticoes = 0;
    printf("\nDejesa digitar quantos números para comparar qual o é o maior e o menor: ");
    scanf("%d", &repeticoes);
    for (int i = 0; i < repeticoes; i++)
    {
        int num = 0;
        printf("\nDigite o %d número: ", i + 1);
        scanf("%d", &num);

        if (i == 0)
        {
            maior = menor = num;
        }else if (num > maior)
        {
            maior = num;
        }else if (num < menor)
        {
            menor = num;
        }   
    }
    printf("\nMaior = %d\nMenor = %d\n", maior, menor); 

    return 0;
}