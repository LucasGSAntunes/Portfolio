#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>

#define MAX 100
using namespace std;

typedef struct registro aluno;
typedef struct cabeca head;

struct registro
{
    char nome[MAX];
    float notas[MAX];
    float media;
    char grau;
    aluno *prox;
};

struct cabeca
{
    int num_itens;
    aluno *prox;
    aluno *ultimo;
};

head * criar_lista();
aluno *cria_no(char *, float *, int);
int vazia(head *);
void insere_inicio(aluno *);
void insere_fim(head *, aluno *);
void remove_no(head *, aluno *);

float achaMenor(float *, int);
void calculaMedia(head *, int);
void obtemGrau(head*);
void ordena(head*);

int main(void)
{
    int n, j=1;
    char nome[MAX];
    float notas[MAX];

    cout<<"Digite a quantidade de provas aplicadas:"<<endl;
    cin>>n;

    while (n<=1)
    {
        cout<<"Digite uma quantidade valida de provas aplicadas:"<<endl;
        cin>>n;
    }
    
    head *lista = criar_lista();

    while(1)
    {
        cin.ignore();
        cout<<"Digite o nome do "<<j<<"° aluno:"<<endl;
        cin.getline(nome, MAX);
        if(strcmp(nome,"fim")==0)
            break;
        for(int i=1;i<=n;i++)
        {
            cout<<"Digite a "<<i<<"° nota do aluno "<<nome<<":"<<endl;
            cin >> notas[i];
            while(notas[i]<0 || notas[i]>10)
            {
                cout<<"Digite uma nota entre 0-10"<<endl;
                cin >> notas[i];
            }
        }
        aluno *novo = cria_no(nome, notas, n);
        insere_fim(lista, novo);
        j++;
    }

    calculaMedia(lista, n);
    obtemGrau(lista);
    ordena(lista);

    for(aluno *p = lista->prox;p!=NULL;p=p->prox)
    {
        cout<<p->grau<<" ";
        cout<<p->nome<<endl;
    }

    return 0;
}

head * criar_lista()
{
    head *le = (head*)malloc(sizeof(head));
    le->num_itens=0;
    le->prox=NULL;
    le->ultimo=NULL;
    return le;
}
aluno * cria_no(char *nome, float *notas, int n)
{
    aluno *novo = (aluno*)malloc(sizeof(aluno));
    novo->prox = NULL;
    strcpy(novo->nome, nome);
    for(int i=1;i<=n;i++)
        novo->notas[i]=notas[i];
    novo->media = 0;
    novo->grau = '0';
    return novo;
}

int vazia(head *lista)
{
    return (lista->prox==NULL);
}

void insere_inicio(head *lista, aluno *novo)
{
    if(vazia(lista))
        lista->ultimo = novo;
    
    novo->prox = lista->prox;
    lista->prox = novo;
    lista->num_itens++;
}

void insere_fim(head *lista, aluno *novo)
{
    if(vazia(lista))
        return insere_inicio(lista, novo);
    
    novo->prox = NULL;
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
}

void calculaMedia(head * lista, int n)
{
    aluno *p;
    float menor;

    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        menor=achaMenor(p->notas, n);
        p->media=-menor;
        for(int i=1;i<=n;i++)
        {
            p->media += p->notas[i];
        }
        p->media=p->media/(n-1);
    }

}

float achaMenor(float *notas, int n)
{
    float menor;

    if(n==1)
        return notas[n];
    
    menor = achaMenor(notas, n-1);

    if(notas[n]<menor)
        return notas[n];
    else
        return menor;
}

void obtemGrau(head *lista)
{
    aluno *p;
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->media>=9)
            p->grau = 'A';
        else if(p->media>=8 && p->media<9)
            p->grau = 'B';
        else if(p->media>=7 && p->media<8)
            p->grau = 'C';
        else 
            p->grau = 'D';
    }
}

void ordena(head *lista) {
    aluno *atual, *proximo, *anterior = NULL;
    int trocou = 1;

    if (vazia(lista)) {
        cout << "Lista vazia!" << endl;
        return;
    }

    while (trocou) {
        trocou = 0;
        anterior = NULL;
        atual = lista->prox;
        proximo = atual->prox;

        while (proximo != NULL) {
            if (proximo->grau < atual->grau || (proximo->grau == atual->grau && strcmp(proximo->nome, atual->nome) < 0)) {
                if (anterior != NULL)
                    anterior->prox = proximo;
                else
                    lista->prox = proximo;

                atual->prox = proximo->prox;
                proximo->prox = atual;

                anterior = proximo;
                proximo = atual->prox;
                trocou = 1;
            }
            else {
                anterior = atual;
                atual = proximo;
                proximo = proximo->prox;
            }
        }
    }
}