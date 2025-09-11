#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// ============================
// Structs
// ============================

// Item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Nó da lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;


// ============================
// Mochila com VETOR
// ============================
Item mochilaVetor[MAX_ITENS];
int qtdItensVetor = 0;

// Inserir item no vetor
void inserirItemVetor() {
    if (qtdItensVetor >= MAX_ITENS) {
        printf("\nA mochila (vetor) esta cheia!\n");
        return;
    }

    Item novo;
    printf("\n--- Adicionar Item (Vetor) ---\n");
    printf("Nome: "); scanf(" %[^\n]", novo.nome);
    printf("Tipo: "); scanf(" %[^\n]", novo.tipo);
    printf("Quantidade: "); scanf("%d", &novo.quantidade);

    mochilaVetor[qtdItensVetor++] = novo;
    printf("Item adicionado com sucesso!\n");
}

// Remover item no vetor
void removerItemVetor() {
    if (qtdItensVetor == 0) {
        printf("\nA mochila (vetor) esta vazia!\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item para remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < qtdItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < qtdItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            qtdItensVetor--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }
    printf("Item nao encontrado!\n");
}

// Listar itens no vetor
void listarItensVetor() {
    printf("\n=== Mochila com VETOR (%d/%d) ===\n", qtdItensVetor, MAX_ITENS);
    for (int i = 0; i < qtdItensVetor; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
    }
    if (qtdItensVetor == 0) printf("Mochila vazia!\n");
}

// Busca sequencial no vetor
void buscarSequencialVetor() {
    char nome[30];
    printf("Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nome);

    int comparacoes = 0;
    for (int i = 0; i < qtdItensVetor; i++) {
        comparacoes++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Item encontrado! Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
            printf("Comparacoes realizadas: %d\n", comparacoes);
            return;
        }
    }
    printf("Item nao encontrado! Comparacoes: %d\n", comparacoes);
}

// Ordenar vetor por nome (Bubble Sort)
void ordenarVetor() {
    for (int i = 0; i < qtdItensVetor - 1; i++) {
        for (int j = 0; j < qtdItensVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                Item temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    printf("\nMochila ordenada por nome!\n");
}

// Busca binária no vetor
void buscarBinariaVetor() {
    if (qtdItensVetor == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    ordenarVetor();

    char nome[30];
    printf("Digite o nome do item para buscar (binaria): ");
    scanf(" %[^\n]", nome);

    int esq = 0, dir = qtdItensVetor - 1, meio, comparacoes = 0;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        comparacoes++;
        int cmp = strcmp(mochilaVetor[meio].nome, nome);
        if (cmp == 0) {
            printf("Item encontrado! Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[meio].nome, mochilaVetor[meio].tipo, mochilaVetor[meio].quantidade);
            printf("Comparacoes realizadas: %d\n", comparacoes);
            return;
        }
        if (cmp < 0) esq = meio + 1;
        else dir = meio - 1;
    }
    printf("Item nao encontrado! Comparacoes: %d\n", comparacoes);
}

// Menu da mochila com vetor
void menuVetor() {
    int opcao;
    do {
        printf("\n--- MENU VETOR ---\n");
        printf("1. Adicionar Item\n2. Remover Item\n3. Listar Itens\n4. Buscar Sequencial\n5. Buscar Binaria\n0. Voltar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItemVetor(); break;
            case 2: removerItemVetor(); break;
            case 3: listarItensVetor(); break;
            case 4: buscarSequencialVetor(); break;
            case 5: buscarBinariaVetor(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}


// ============================
// Mochila com LISTA
// ============================
No* inicio = NULL;

// Inserir item na lista
void inserirItemLista() {
    No* novo = (No*)malloc(sizeof(No));
    printf("\n--- Adicionar Item (Lista) ---\n");
    printf("Nome: "); scanf(" %[^\n]", novo->dados.nome);
    printf("Tipo: "); scanf(" %[^\n]", novo->dados.tipo);
    printf("Quantidade: "); scanf("%d", &novo->dados.quantidade);

    novo->proximo = inicio;
    inicio = novo;
    printf("Item adicionado com sucesso!\n");
}

// Remover item na lista
void removerItemLista() {
    if (inicio == NULL) {
        printf("Mochila (lista) vazia!\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item para remover: ");
    scanf(" %[^\n]", nome);

    No* atual = inicio;
    No* anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) inicio = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item nao encontrado!\n");
}

// Listar itens da lista
void listarItensLista() {
    No* atual = inicio;
    int i = 1;
    printf("\n=== Mochila com LISTA ===\n");
    if (atual == NULL) {
        printf("Mochila vazia!\n");
        return;
    }
    while (atual != NULL) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i++, atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->proximo;
    }
}

// Buscar item na lista
void buscarItemLista() {
    if (inicio == NULL) {
        printf("Mochila (lista) vazia!\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nome);

    No* atual = inicio;
    int comparacoes = 0;
    while (atual != NULL) {
        comparacoes++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Item encontrado! Nome: %s | Tipo: %s | Quantidade: %d\n",
                   atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            printf("Comparacoes realizadas: %d\n", comparacoes);
            return;
        }
        atual = atual->proximo;
    }
    printf("Item nao encontrado! Comparacoes: %d\n", comparacoes);
}

// Menu da mochila com lista
void menuLista() {
    int opcao;
    do {
        printf("\n--- MENU LISTA ---\n");
        printf("1. Adicionar Item\n2. Remover Item\n3. Listar Itens\n4. Buscar Item\n0. Voltar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItemLista(); break;
            case 2: removerItemLista(); break;
            case 3: listarItensLista(); break;
            case 4: buscarItemLista(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}


// ============================
// Programa principal
// ============================
int main() {
    int opcao;
    do {
        printf("\n==============================\n");
        printf(" INVENTARIO FREE FIRE - NIVEL AVENTUREIRO\n");
        printf("==============================\n");
        printf("1. Usar Mochila com VETOR\n");
        printf("2. Usar Mochila com LISTA\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menuVetor(); break;
            case 2: menuLista(); break;
            case 0: printf("\nSaindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}