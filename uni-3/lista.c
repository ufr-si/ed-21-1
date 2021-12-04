#include<stdio.h>
#include<stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
}no;

void listar(no *lista);

no *l; // NULL 
no *k; // NULL

void adiciona_l(int n){ // pilha
    // criar um PONTEIRO PARA no
    no *novo;
   
    novo = malloc(sizeof(no)); // memory allocation = alocacao de memoria
    // mallloc retorna um endereco
    // adicionar conteúdo nesse nó
    // novo->conteudo = n;
    novo->conteudo = n;
    //novo->prox = lista;

    if(l == NULL){ // nao tinha elementos na lista! =)
        novo->prox = NULL;
        l = novo;
    }else{
        novo->prox = l;
        // fim_lista
        // adicionar NULL no "prox" desse nó
        // vamos apontar lista para ele
        l = novo;
    }
    
}

void remover_e_inserir(){
    no *aux; // mao 2
    no *maior; // mao 3
    
    aux = l;
    maior = l;
    while(aux !=NULL){
        // guardar o maior entre o maior que eu conheco
        // guardado em MAIOR e o atual (aux) 
        if(aux->conteudo > maior->conteudo){
                maior = aux;
        }
        aux = aux->prox; // pega o próximo candidato a maior
    }
    // terminei de percorrer
    // "maior" vai ter o ENDERECO (ele eh ponteiro)
    // para o maior conteudo

    // remover o maior de l
    aux = l;
    // o que acontece se aux= l  = maior
    if(aux == maior){
        // a lista tem um elemento? 
        if(aux->prox == NULL){ 
            l = NULL;
        }else{
            // maior eh o primeiro elemento ?
            l = maior->prox;            
        }

    }else{
        while(aux->prox != maior){
            aux = aux->prox; // pega o próximo candidato a maior
        }
        // aqui , eu tenho assim: 
        // aux->[resto da lista]
        // remover maior
            no *resto_da_lista = maior->prox;
            aux->prox = resto_da_lista;
            // maior->[resto_da_lista]
            maior->prox = NULL;

    }
  
/// INSERIR

    if(k == NULL){ // nao tinha elementos na lista! =)     
        k = maior;
    }else{
        maior->prox = k;

        // fim_lista
        // adicionar NULL no "prox" desse nó
        // vamos apontar lista para ele
        k = maior; // oficialmente, maior passa a ser o primeiro da lista
    }
}

void concatena(){
    no *aux; 
    aux = l;
     while(aux->prox !=NULL){
        aux = aux->prox;
    }
    // aux tem o ponteiro para o ULTIMO elmento de l
    aux->prox =k;
}


void listar(no *lista){
    //percorrer 
    no *aux;
    aux = lista;
    printf("Listando:\n [");
    while(aux!=NULL){
        printf(" %d, ",aux->conteudo);
        aux = aux->prox;
    }
    printf("]\n\n");
}

int main(void){
    
    
    adiciona_l(4); // l é NULL
    adiciona_l(10);
    adiciona_l(3);
    adiciona_l(4);
    adiciona_l(16);
    adiciona_l(5);
    listar(l);
    while(l!=NULL){
        remover_e_inserir();
    }
    
    
    listar(k);

}