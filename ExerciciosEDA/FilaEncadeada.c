#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;

    if (*f == NULL) {
        *f = novo;
        novo->prox = novo;
    } else {
        celula *cabeca = *f;
        while (cabeca->prox != *f) {
            cabeca = cabeca->prox;
        }
        cabeca->prox = novo;
        novo->prox = *f;
    }
}

int desenfileira(celula *f, int *y) {
    if (f->prox == f) { // fila vazia
        return 0;
    }
    celula *p = f->prox;
    *y = p->dado; // guarda o dado a ser retornado
    f->prox = p->prox; // remove o primeiro elemento
    free(p); // libera a memória alocada
    return 1; // sucesso
}