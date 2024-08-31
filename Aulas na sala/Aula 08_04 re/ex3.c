# include <stdio.h>
int fibonacci (int n )
{
    if (n == 0)
    {
        return 0;
    }else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n -1) + fibonacci(n-2);
    }
}

int main () 
{
    int n = 0;
    printf("Digite o termo da sequência fibonacci que deseja ver: ");
    scanf("%d", &n);
    printf("O termo da sequência é %d\n", fibonacci(n));

    return 0;
}