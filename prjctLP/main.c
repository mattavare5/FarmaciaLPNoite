#include <locale.h>
#include <stdio.h>
#include "medicamento.h"

p_medicamento v[MAX];

int main() {
    setlocale (LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    int i = 0;
    int opcao = 0;
    inicializa();
    carregar_arquivo();
    while (i < MAX && v[i] != NULL) {
        i++;
    }
    do {
        int p = 0;
        printf("\n---------------- MENU PRINCIPAL ----------------\n");
        printf("------------------------------------------------\n");
        printf("1. Cadastrar medicamento\n");
        printf("2. Imprimir os dados dos medicamentos\n");
        printf("3. Imprimir os dados de todos os medicamentos\n");
        printf("4. Buscar medicamento pelo código de barras\n");
        printf("5. Relatório de estoque\n");
        printf("9. Salvar e sair\n");
        printf("------------------------------------------------\n");
        printf("\nDigite a sua opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        switch (opcao) {
            case 1:
                if (i < MAX) {
                    ler_dados(i);
                    i++;
                    getchar();
                } else {
                    printf("Limite de 100 itens cadastrados atingido.");
                }
                break;
            case 2:
                printf("Digite a posição para imprimir o medicamento: ");
                scanf("%d", &p);
                fflush(stdin);
                if (p < 0 || p > MAX) {
                    printf("Posição inválida.");
                } else {
                    imprimir_unico(p);
                }
                break;
            case 3:
                imprimir_tudo();
                break;
            case 4:
                buscar_medicamento();
                break;
            case 5:
                relatorio_estoque();
                break;
            case 9:
                salvar_arquivo();
                liberar_memoria();
                printf("FIM\n");
                break;
            default:
                printf("Opção inválida");
        }
    } while (opcao!=9);
    return 0;
}