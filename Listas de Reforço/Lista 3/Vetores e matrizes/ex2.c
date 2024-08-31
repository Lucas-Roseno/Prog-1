#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int vet1[10], vet2[10], vet3[20];

    for (int i = 0; i < 10; i++)
    {
        vet1[i] = i + 1;
        vet2[i] = i + 11;
        vet3[i] = vet1[i];
        vet3[i + 10] = vet2[i];
    }
    
    int auxiliar = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = i; j < 20; j++)
        {
            if (vet3[i] < vet3[j])
            {
                auxiliar= vet3[i];
                vet3[i] = vet3[j];
                vet3[j] = auxiliar;
            }   
        }
        printf("%d - ", vet3[i]); 
    }
    

    return 0;
}