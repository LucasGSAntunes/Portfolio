#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int remove_depois (celula *p){
    if(p->prox == NULL || p == NULL)
        return 0;
    celula * lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}
void remove_elemento (celula *le, int x){
    celula *p = le;
    while(p->prox!= NULL){
        if(p->prox->dado==x){
            remove_depois(p);
            return;
        }
        p = p->prox;
    }
}
void remove_todos_elementos (celula *le, int x){
    celula *p = le;
    while(p->prox != NULL){
        if (p->prox->dado == x) {
            remove_depois(p);
        } else {
            p = p->prox;
        }
    }
}