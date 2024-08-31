# include <stdio.h>
int soma_digitos (int num)
{
    if(num == 0)
    {
        return 0;
    } else 
    {
        return (num % 10) + soma_digitos(num /10);
    }
}

int main () 
{
    int num = 0;
    printf("Digite um número para ver a soma dos digitos: ");
    scanf("%d", &num);

    printf("soma_digitos = %d", soma_digitos(num));
    return 0;

}