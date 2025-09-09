#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor para armazenar os itens
Item mochila[MAX_ITENS];
int qtdItens = 0;

// Função para inserir um item na mochila
void inserirItem() {
    if (qtdItens >= MAX_ITENS) {
        printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n--- Adicionar Novo Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Tipo do item (arma, municao, cura...): ");
    scanf(" %[^\n]", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[qtdItens] = novo;
    qtdItens++;

    printf("\nItem adicionado com sucesso!\n");
}

// Função para remover item pelo nome
void removerItem() {
    if (qtdItens == 0) {
        printf("\nA mochila esta vazia, nada para remover.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n--- Remover Item ---\n");
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            for (int j = i; j < qtdItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            qtdItens--;
            printf("\nItem removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado na mochila.\n");
    }
}

// Função para listar todos os itens
void listarItens() {
    printf("\n======= Itens na Mochila (%d/%d) =======\n", qtdItens, MAX_ITENS);

    if (qtdItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (int i = 0; i < qtdItens; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função para buscar item pelo nome
void buscarItem() {
    if (qtdItens == 0) {
        printf("\nA mochila esta vazia, nada para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n--- Buscar Item ---\n");
    printf("Digite o nome do item: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado.\n");
    }
}

// Função principal (menu)
int main() {
    int opcao;

    do {
        printf("\n==============================\n");
        printf(" MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
        printf("==============================\n");
        printf("Itens na Mochila: %d/%d\n", qtdItens, MAX_ITENS);
        printf("\n1. Adicionar Item");
        printf("\n2. Remover Item");
        printf("\n3. Listar Itens");
        printf("\n4. Buscar Item");
        printf("\n0. Sair");
        printf("\n------------------------------");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("\nSaindo do sistema...\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}