#include<stdio.h> 
#include<stdlib.h>

// no de uma lista (encaeada)
typedef struct reg{
    int conteudo;
    struct reg *prox;
}no;

// declarando
no *c;
//no *p; 

void adiciona(int n){
    no *novo;
    novo = malloc(sizeof(no));
    novo->prox = NULL;
    novo->conteudo = n;
    c->prox = novo;
}

int busca(int n){
   
   no *p;
   p = c;
  
   while (p != NULL && p->conteudo != n){
       p = p->prox; 
   } 
   return p->conteudo;
}

void listar(){
   no *p;
   p = c;
  
   while (p != NULL){
       printf("Conteúdo: %i \n",p->conteudo);
       p = p->prox; 
   }
}

remove (no *p)
{
   no *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}


int main (void) {
    c = malloc(sizeof(no));
    adiciona(1);
    adiciona(2);
    listar();

   return 0;
}






