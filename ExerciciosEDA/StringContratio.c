#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct registro node;
struct registro {
    Item info;
    node *ant;
    node *prox;
};

typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};

head *criar_lista();
node *criar_no(Item);

int vazia(head*);

void insere_inicio(head *, node *);
void insere_fim(head *, node *);

head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->ant = NULL;            
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{
  return (p->prox==NULL); 
}

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) lista->ultimo = novo;
    else lista->prox->ant = novo; //<<<<<<<<<<<<<<<<<<<<<<<<
    lista->num_itens++; 

    novo->ant = NULL;         //<<<<<<<<<<<<<<<<<<<<<<<<
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; //<<<<<<<<<<<<<<<<<
    novo->prox = NULL;
    
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
}

int main(){
    head *cabeca;
    node *novo;
    node *p;
    cabeca = criar_lista();
    char c[500];
    int i=0;

    
    scanf(" %s", c);
    
    while(c[i] != '\0'){
        
        novo = criar_no(c[i]);
        insere_fim(cabeca, novo);
        i++;
    }

    for(p=cabeca->ultimo;p!=NULL;p=p->ant){
        printf("%c", p->info);
    }
    printf("\n");
    return 0;
}