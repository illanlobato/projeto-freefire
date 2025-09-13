#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTES 10
#define MAX_NOME 30
#define MAX_TIPO 20

typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
    int prioridade; // 1 a 5
} Componente;

Componente mochila[MAX_COMPONENTES];
int qtdComponentes = 0;
int ordenadoPorNome = 0; // flag para saber se está ordenado por nome

// Função para adicionar componente
void adicionarComponente() {
    if (qtdComponentes >= MAX_COMPONENTES) {
        printf("\nMochila cheia! Nao e possivel adicionar mais componentes.\n");
        return;
    }

    Componente c;
    printf("\n== Cadastro de Componente ==\n");
    printf("Nome: ");
    scanf(" %[^\n]", c.nome);
    printf("Tipo: ");
    scanf(" %[^\n]", c.tipo);
    printf("Quantidade: ");
    scanf("%d", &c.quantidade);

    do {
        printf("Prioridade (1-5): ");
        scanf("%d", &c.prioridade);
    } while (c.prioridade < 1 || c.prioridade > 5);

    mochila[qtdComponentes] = c;
    qtdComponentes++;

    printf("\nComponente adicionado com sucesso!\n");
    ordenadoPorNome = 0; // perdeu a ordenação
}

// Função para listar componentes em tabela alinhada
void listarComponentes() {
    if (qtdComponentes == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    printf("\n== Inventario da Mochila ==\n");
    printf("%-3s %-20s %-15s %-7s %-10s\n", "N", "Nome", "Tipo", "Qtd", "Prioridade");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < qtdComponentes; i++) {
        printf("%-3d %-20s %-15s %-7d %-10d\n",
               i + 1,
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }
}

// Função para descartar componente
void descartarComponente() {
    if (qtdComponentes == 0) {
        printf("\nMochila vazia. Nada para descartar.\n");
        return;
    }

    listarComponentes();
    int pos;
    printf("\nDigite o numero do componente para descartar: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > qtdComponentes) {
        printf("\nNumero invalido.\n");
        return;
    }

    for (int i = pos - 1; i < qtdComponentes - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    qtdComponentes--;

    printf("\nComponente descartado com sucesso!\n");
    ordenadoPorNome = 0; // perdeu ordenação
}

// Funções de comparação
int cmpNome(const void *a, const void *b) {
    return strcmp(((Componente*)a)->nome, ((Componente*)b)->nome);
}
int cmpTipo(const void *a, const void *b) {
    return strcmp(((Componente*)a)->tipo, ((Componente*)b)->tipo);
}
int cmpPrioridade(const void *a, const void *b) {
    return ((Componente*)a)->prioridade - ((Componente*)b)->prioridade;
}

// Função para organizar mochila
void organizarMochila() {
    int opcao;
    do {
        printf("\n--- Estrategia de Organizacao ---\n");
        printf("1. Por nome (ordem alfabetica)\n");
        printf("2. Por tipo\n");
        printf("3. Por prioridade de montagem\n");
        printf("0. Voltar ao menu\n");
        printf("Escolha o criterio: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                qsort(mochila, qtdComponentes, sizeof(Componente), cmpNome);
                printf("\nMochila organizada por NOME!\n");
                ordenadoPorNome = 1;
                break;
            case 2:
                qsort(mochila, qtdComponentes, sizeof(Componente), cmpTipo);
                printf("\nMochila organizada por TIPO!\n");
                ordenadoPorNome = 0;
                break;
            case 3:
                qsort(mochila, qtdComponentes, sizeof(Componente), cmpPrioridade);
                printf("\nMochila organizada por PRIORIDADE!\n");
                ordenadoPorNome = 0;
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);
}

// Função para busca binária (apenas se estiver ordenado por nome)
void buscaBinaria() {
    if (qtdComponentes == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    if (!ordenadoPorNome) {
        printf("\nALERTA: A busca binaria requer que a mochila esteja ordenada por NOME.\n");
        printf("Use a Opcao 4 para organizar a mochila primeiro.\n");
        return;
    }

    char chave[MAX_NOME];
    printf("\nDigite o nome do componente para buscar: ");
    scanf(" %[^\n]", chave);

    int inicio = 0, fim = qtdComponentes - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(chave, mochila[meio].nome);

        if (cmp == 0) {
            printf("\nComponente encontrado: %s | Tipo: %s | Qtd: %d | Prioridade: %d\n",
                   mochila[meio].nome,
                   mochila[meio].tipo,
                   mochila[meio].quantidade,
                   mochila[meio].prioridade);
            return;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    printf("\nComponente nao encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\n=============================\n");
        printf("PLANO DE FUGA - CODIGO DA ILHA (NIVEL MESTRE)\n");
        printf("Itens na Mochila: %d/%d\n", qtdComponentes, MAX_COMPONENTES);
        printf("=============================\n");
        printf("1. Adicionar Componente\n");
        printf("2. Descartar Componente\n");
        printf("3. Listar Componentes (Inventario)\n");
        printf("4. Organizar Mochila (Ordenar Componentes)\n");
        printf("5. Busca Binaria por Componente-Chave (por nome)\n");
        printf("0. ATIVAR TORRE DE FUGA (Sair)\n");
        printf("=============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarComponente(); break;
            case 2: descartarComponente(); break;
            case 3: listarComponentes(); break;
            case 4: organizarMochila(); break;
            case 5: buscaBinaria(); break;
            case 0: printf("\nTorre de Fuga ativada! Saindo...\n"); break;
            default: printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}