#include "lista.h"

void cria_lista(Lista *l, int n){
    l->fim = n-1;
    l->pos = -1;
    l->total = 0;
}

int lista_vazia(Lista *l){
    return (l->total == 0);
}

int lista_cheia(Lista *l){
    return (l->total == l->fim+1);
}

int insere_lista(Lista *l, int x, char y[]){
    if(lista_cheia(l))
        return 1; //erro
    
    l->total++;
    l->pos++;
    
    l->brinquedo[l->pos].n_serie = x;
    strcpy(l->brinquedo[l->pos].modelo, y);
    return 0;
}

Info remove_lista(Lista *l, int n, int i){
    Info aux = l->brinquedo[i], temp;
    
    for(int j=i; j<n; j++){
        temp = l->brinquedo[j];
        l->brinquedo[j] = l->brinquedo[j+1];
        l->brinquedo[j+1] = temp;
    }
    return aux;
}

void cria_pilha(Pilha *p, int tam){
    p->topo =-1;
    p->capacidade=tam;
}

int pilha_vazia(Pilha *p){
    return (p->topo == -1);
}

int pilha_cheia(Pilha *p){
    return (p->topo+1 == p->capacidade);
}

int push(Pilha *p, Info elem){
    if(pilha_cheia(p))
        return 1; //erro
    
    p->topo++;
    p->brinquedo[p->topo].n_serie = elem.n_serie;
    strcpy(p->brinquedo[p->topo].modelo, elem.modelo);

    return 0;
}

int pop(Pilha *p, Info *aux){
    if(pilha_vazia(p))
        return 1; //erro
    
    aux->n_serie = p->brinquedo[p->topo].n_serie;
    strcpy(aux->modelo, p->brinquedo[p->topo].modelo);
    p->topo--;
    
    return 0;
}

void imprime_pilha(Pilha *p, int *n_caixa){
    printf("Caixa %d: brinquedo <%d,%s> - quantidade %d", *n_caixa, p->brinquedo[p->topo].n_serie, p->brinquedo[p->topo].modelo, p->topo);
}

void esvazia_pilha(Pilha *p){
    p->topo=-1;
}

void cria_fila(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int fila_cheia(Fila *f){
    return (f->total == f->fim);
}

int fila_vazia(Fila *f){
    return (f->total == 0);
}

int insere_fila(Fila *f, Pilha x){
    if(fila_cheia(f))
        return 1; //erro
    f->caixa[f->fim] = x;
    f->total++;
    if (f->fim == MAX-1)
        f->fim = 0;
    else
        f->fim++;
    return 0;
}

int remove_fila(Fila *f, Pilha *x){
    if(fila_vazia(f))
        return 1; //erro
    *x = f->caixa[f->inicio];
    f->total--;
    if (f->inicio == MAX-1)
        f->inicio = 0;
    else
        f->inicio++;
    
    return 0;
}