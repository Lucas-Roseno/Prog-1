#include "listaDupla.h"

int main()
{
    int opcao;
    lista_dupla lista;
    criarLista(&lista);
    char musica[TAM], musicaNova[TAM];

    while (1)
    {

        printf("1 - Inserir múscia no início\n");
        printf("2 - Inserir música ordenada por nome\n");
        printf("3 - Remover música do início\n");
        printf("4 - Remover determinada música\n");
        printf("6 - Inserir música após uma determinada música\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        getchar();
        switch (opcao)
        {
        case 1:
            printf("Digite a música: ");
            fgets(musica, TAM, stdin);
            musica[strlen(musica) - 1] = '\0';

            inserirIni(&lista, musica);
            mostrarLista(&lista);
            break;

        case 2:
            printf("Digite a música: ");
            fgets(musica, TAM, stdin);
            musica[strlen(musica) - 1] = '\0';
            inseririOrd(&lista, musica);
            mostrarLista(&lista);

            break;
        case 3:
            removerIni(&lista);
            mostrarLista(&lista);
            break;
        case 4:
            printf("Digite a música: ");
            fgets(musica, TAM, stdin);
            musica[strlen(musica) - 1] = '\0';

            removerElemento(&lista, musica);

            break;
        case 6:
            printf("Digite a nova música: ");
            fgets(musicaNova, TAM, stdin);
            musicaNova[strlen(musicaNova) - 1] = '\0';

            printf("Digite a música de referência: ");
            fgets(musica, TAM, stdin);
            musica[strlen(musica) - 1] = '\0';

            inserirAposMusica(&lista, musica, musicaNova);
            break;
        default:
            break;
        }
    }

    return 0;
}