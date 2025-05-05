#include <stdio.h>
#include <stdlib.h>

// Função que cria uma lista
int* criar(int tamanho) {
    return (int*)malloc(sizeof(int) * tamanho);
}

// Adiciona elementos na lista
void adicionar(int **lista, int *tamanho, int indice, int valor) {
    // Verifica se o índice é válido
    if (indice < 0 || indice > *tamanho) {
        printf("Índice inválido\n");
        return;
    }

    // Alterando a posição para adicionar elemento
    *tamanho += 1;
    *lista = (int*)realloc(*lista, sizeof(int) * (*tamanho));
    // Move elementos pro lado
    for (int i = *tamanho - 1; i > indice; i--) {
        (*lista)[i] = (*lista)[i - 1];
    }
    // Adiciona o novo elemento
    (*lista)[indice] = valor;
}

// Remove elementos da lista
void remover(int **lista, int *tamanho, int indice) {
    // Verifica se o índice é válido
    if (indice < 0 || indice >= *tamanho) {
        printf("Índice inválido\n");
        return;
    }

  // Move elementos pro lado para manter a ordem
    for (int i = indice; i < *tamanho - 1; i++) {
        (*lista)[i] = (*lista)[i + 1];
    }
    // Alterando a posição para remover elemento
    *tamanho -= 1;
    *lista = (int*)realloc(*lista, sizeof(int) * (*tamanho));
}

// Mostra todos os elementos da lista
void mostrarTudo(int *lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Índice %d: %d\n", i, lista[i]);
    }
}

// Mostra um elemento da lista com base no índice
void mostrarUm(int *lista, int tamanho, int indice){
    printf("Índice %d: %d\n", indice, lista[indice]);
}

int main(void) {
    int *lista;
    int tamanho = 0;
    // Criando uma lista com 5 elementos
    lista = criar(5);

    // Adicionando elementos na lista
    adicionar(&lista, &tamanho, 0, 10);
    adicionar(&lista, &tamanho, 1, 20);
    adicionar(&lista, &tamanho, 1, 15);
    adicionar(&lista, &tamanho, 2, 25);
    adicionar(&lista, &tamanho, 4, 30);

    printf("Mostra a lista, com indice e valor\n");
    mostrarTudo(lista, tamanho);
    printf("\n");
    // Remove um elemento
    remover(&lista, &tamanho, 1);
    printf("Valor do indice 1 removido\n");
    printf("\n");
  
    // Mostra a lista após remoção
    mostrarTudo(lista, tamanho);
    printf("\n");
  
    // Mostra um elemento específico
    printf("Buscando o valor do indice 2\n");
    mostrarUm(lista, tamanho, 2);

    // Apaga memoria alocada
    free(lista);

    return 0;
}