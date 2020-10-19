#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, tam_p, k, n_caixa=0, size, i; //n_caixa: contador
    Lista *l;
    Pilha p;
    Pilha *p_temp;
    Fila *f;
    
    int n_serie;
    char modelo[MAX];
    
    scanf("%d %d %d", &n, &tam_p, &k);

    cria_lista(&l, n);
    cria_pilha(&p, tam_p);
    cria_fila(&f);
    
    for(i=0; i<n; i++){
        scanf("%d %s", &n_serie, modelo);
        if(!insere_lista(&l, n_serie, modelo)){
            printf("Erro ao inserir!");
            break;
        }
    }
    size=n;
    while(size>0){
        i=0;
            while(i<n){
                Info elem = remove_lista(&l, n, i);
                if(!push(&p, elem)){
                    insere_fila(&f, p);
                    esvazia_pilha(&p);
                }
                i+=k-1;
                n--;
                if((i+k)>size){
                    break;
                }
            }
        size--;
        k--;
    }
    
    for(i=f->inicio; i<=(f->fim); i++){
        if(!remove_fila(&f, &p_temp)){
            printf("Erro ao remover caixa!");
            break;
        }
        imprime_pilha(&p_temp, n_caixa);
    }

    return 0;
}