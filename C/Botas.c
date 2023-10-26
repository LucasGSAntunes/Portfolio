#include <stdio.h>
#include <stdlib.h>

typedef struct registro node;
typedef struct cabeca head;
typedef int numero;

struct registro
{
    numero num;
    char lado;
    node *prox;
};

struct cabeca
{
    int num_itens;
    node *prox;
    node *ultimo;
};

head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens=0;
    le->prox=NULL;
    le->ultimo=NULL;
    return le;
}

node * criar_no(numero num, char lado)
{
    node *novo = malloc(sizeof(node));
    novo->prox=NULL;
    novo->num = num;
    novo->lado = lado;
    return novo;
}

int Vazia(head * le){
    return(le->prox==NULL);
}

void insere_inicio(head *le, node *novo)
{
    if(Vazia(le))
        le->ultimo = novo;

    novo->prox = le->prox;
    le->prox = novo;
    le->num_itens++;
}

void insere_fim(head *le, node *novo)
{
    if(Vazia(le))
        return insere_inicio(le, novo);
    
    novo->prox = NULL;

    le->ultimo->prox = novo;
    le->ultimo = novo;
    le->num_itens++;
}
void remove_inicio(head *le)
{
    node *lixo = le->prox;
    le->prox = lixo->prox;
    free(lixo);

}

void remove_no(head *lista, node *lixo)
{
    node *aux = lista->prox;
    while(aux!=NULL && aux->prox!=lixo) 
        aux = aux->prox;

    if(aux){
        aux->prox = lixo->prox;
        if(lixo == lista->ultimo) lista->ultimo = aux->prox;
        lista->num_itens--;
    }
    
}

int AcharPar(head *le){
    node *p = le->prox;
    node *par;
    if(p->prox!=NULL)
        par = p->prox;
    while(par!=NULL)
    {
        if(par->num==p->num && par->lado!=p->lado){
            remove_no(le, par);
            remove_inicio(le);
            return 1;
        }
        par = par->prox;
    }
    remove_inicio(le);
    return 0;
}

int main(){

    int m;
    char l;
    head *lista = criar_lista();
    node *p;

    while(scanf("%d", &m)==1 && scanf(" %c", &l) == 1){
        node *novo = criar_no(m,l);
        insere_fim(lista, novo);
    }

    int soma = 0;

    while(lista->prox!=NULL){
        soma+=AcharPar(lista);
    }

    printf("%d\n", soma);
    
    return 0;
}