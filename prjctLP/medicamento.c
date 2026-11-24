#include "medicamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa() {
    int i;
    for (i=0; i<MAX; i++) {
        v[i] = NULL;
    }
}

void ler_dados(int i) {
    int quantidade;
    if (v[i] == NULL) {
        v [i] = (p_medicamento)malloc(sizeof(medicamento));
        if (v[i] == NULL) {
            printf("Erro no alocamento de memória.");
            return;
        }
        fflush(stdin);
        printf("Digite o código de barras: ");
        gets(v[i]->codBarras);
        printf("Digite o Nome Comercial: ");
        gets(v[i]->nomeComercial);
        printf("Digite o nome do laboratório: ");
        gets(v[i]->laboratorio);
        printf("Digite o preço unitário: ");
        scanf("%lf", &v[i]->precoUn);
        v[i]->quantidadeEstoque = 0;
        printf("Digite um valor de estoque mínimo para esse item: ");
        scanf("%d", &v[i]->estoqueMin);

        printf("Quantidade atual do estoque: %d\n", v[i]->quantidadeEstoque);

        printf("Digite a quantidade que será adicionada: ");
        scanf("%d", &quantidade);

        if (quantidade > 0) {
            v[i]->quantidadeEstoque += quantidade;
            printf("Estoque atualizado: %d un.\n", v[i]->quantidadeEstoque);
        } else {
            printf("Erro: Quantidade não atualizada.");
        }
    }
}

void imprimir_unico(int i) {
    if (v[i] != NULL) {
        printf("Codigo de Barras: %s \n", v[i]->codBarras);
        printf("Nome Comercial do Medicamento: %s \n", v[i]->nomeComercial);
        printf("Nome do Laboratório: %s \n", v[i]->laboratorio);
        printf("Preço un.: %lf \n", v[i]->precoUn);
        printf("Quantidade atual: %d \n", v[i]->quantidadeEstoque);
        printf("Estoque min.: %d \n\n", v[i]->estoqueMin);
    }
}

void imprimir_tudo() {
    int i;
    for (i=0; i<MAX; i++) {
        imprimir_unico(i);
    }
}

void carregar_arquivo() {
    FILE *arquivo;
    char linha[300];
    int i = 0;

    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro: Arquivo nulo");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < MAX) {
        v[i] = (p_medicamento)malloc(sizeof(medicamento));

        if (v[i] == NULL) {
            printf("Erro na abertura do arquivo");
            break;
        }

        if (sscanf(linha, "%49[^;];%49[^;];%49[^;];%lf;%d;%d",
            v[i]->codBarras,
            v[i]->nomeComercial,
            v[i]->laboratorio,
            &v[i]->precoUn,
            &v[i]->quantidadeEstoque,
            &v[i]->estoqueMin) == 6) {
            i++;
        } else {
            free(v[i]);
            v[i] = NULL;
        }
    }
    fclose(arquivo);
}

void salvar_arquivo() {
    FILE *arquivo;
    int i;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro: Erro ao salvar");
        return;
    }

    for (i=0; i<MAX; i++) {
        if (v[i] != NULL) {
            fprintf(arquivo, "%s;%s;%s;%.2lf;%d;%d\n",
                v[i]->codBarras,
                v[i]->nomeComercial,
                v[i]->laboratorio,
                v[i]->precoUn,
                v[i]->quantidadeEstoque,
                v[i]->estoqueMin);
        }
    }
    fclose(arquivo);
}

void buscar_medicamento() {
    char codigo[20];
    int i = 0;
    int encontrado = 0;

    printf("Digite o código de barras do medicamento: ");
    scanf("%s", codigo);

    for (i=0; i<MAX; i++) {
        if (v[i] != NULL && strcmp(v[i]->codBarras, codigo) == 0) {
            imprimir_unico(i);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Medicamento não encontrado.\n");
    }
}

void relatorio_estoque() {
    int i;
    int encontrado = 0;

    printf("Medicamentos com o estoque baixo:\n");

    for (i=0; i<MAX; i++) {
        if (v[i] != NULL && v[i]->quantidadeEstoque < v[i]->estoqueMin) {
            printf("Codigo de Barras: %s, Medicamento: %s, Qtd atual: %d, Estoque mínimo: %d\n",
                v[i]->codBarras,
                v[i]->nomeComercial,
                v[i]->quantidadeEstoque,
                v[i]->estoqueMin);
            encontrado++;
        }
    }
    if (encontrado == 0) {
        printf("Todos os medicamentos com o estoque OK.\n");
    }
}

void liberar_memoria() {
    int i = 0;

    for (i=0; i<MAX; i++) {
        if (v[i] != NULL) {
            free(v[i]);
            v[i] = NULL;
        }
    }
}