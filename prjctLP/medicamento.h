#define MAX 100
typedef struct Medicamento {
    char codBarras[50];
    char nomeComercial[50];
    char laboratorio[50];
    double precoUn;
    int quantidadeEstoque;
    int estoqueMin;
} medicamento;
typedef medicamento *p_medicamento;

extern p_medicamento v[MAX];

void inicializa();

void ler_dados(int i);

void imprimir_unico(int i);

void imprimir_tudo();

void carregar_arquivo();

void salvar_arquivo();

void buscar_medicamento();

void relatorio_estoque();

void liberar_memoria();