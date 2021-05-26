#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct lista{
  int conteudo;
  struct lista *prox;
}no;

void inserir(int x, no *p){
  no *novo;
  novo = malloc(sizeof(no));
  novo->conteudo = x;
  novo->prox = p->prox;
  p->prox = novo;
}

void excluir(no *p){
  no *lixo;
  lixo = p->prox;
  p->prox = lixo->prox;
  free(lixo);
}

int buscar(int x, no *le){
  no *p = le;
  int achou = 0;
  while ( p != NULL && !achou){
    if (p->conteudo == x){
      achou = 1;
    }
    p = p->prox;
  }
  if (achou){
    return 1;
  }else{
    return 0;
  }
}

void imprimir(no *le){
  no *p;
  for (p = le; p != NULL; p = p->prox){
    printf("%d \n", p->conteudo);
  }
}

int main(void){
  int valor = 6;
  no *le;
  le = malloc(sizeof(no));
  le->prox = NULL;

  for (int i = 1; i <= 10; i ++){
    inserir(valor*i, le);
  }

  imprimir(le);
  excluir(le);
  printf("%d\n",buscar(8,le));
  printf("%d\n",buscar(6,le));
  imprimir(le);
}