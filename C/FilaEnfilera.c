#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) {
        return NULL; // caso não seja possível alocar memória para a nova célula
    }
    novo->dado = x;
    novo->prox = NULL;

    if (f == NULL) { // fila vazia, o novo elemento será o primeiro
        return novo;
    }

    celula *p = f;
    while (p->prox != NULL) { // procura o último elemento da fila
        p = p->prox;
    }
    p->prox = novo; // insere o novo elemento no final da fila
    return f;
}
