#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct{
    int n_serie;
    char modelo[100];
}Info;

typedef struct{
    int fim;
    int pos;
    int total;
    Info brinquedo[MAX];
}Lista;

typedef struct{
    int topo;
    int capacidade;
    Info brinquedo[MAX];
}Pilha;

typedef struct{
    int inicio, fim, total;
    Pilha caixa[MAX];
}Fila;

void cria_lista(Lista *l, int n);
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
int insere_lista(Lista *l, int x, char y[]);
Info remove_lista(Lista *l, int n, int i);

void cria_pilha(Pilha *p, int tam);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
int push(Pilha *p, Info elem);
int pop(Pilha *p, Info *aux);
void imprime_pilha(Pilha *p, int *n_caixa);
void esvazia_pilha(Pilha *p);

void cria_fila(Fila *f);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
int insere_fila(Fila *f, Pilha x);
int remove_fila(Fila *f, Pilha *x);