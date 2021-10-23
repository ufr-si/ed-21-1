#include<stdio.h> 
#include<stdlib.h>

typedef struct reg{ //criando um nó/item da minha lista
    int conteudo; // conteudo!
    struct reg *prox;  // ponteiro para o próximo elemento (que eu quiser)
    struct reg *ant;
}no;

no *lista;

no *fim_fila;
no *fim_lista;

void adiciona(int n){
    // criar um no
    no *novo;

    novo = malloc(sizeof(no)); // memory allocation = alocacao de memoria
    // mallloc retorna um endereco
    // adicionar conteúdo nesse nó
    novo->conteudo = n;
    novo->prox = lista;
    // fim_lista
    // adicionar NULL no "prox" desse nó
    // vamos apontar lista para ele
    lista = novo;
}

void add_fila(int n){
    no *novo;

    novo = malloc(sizeof(no)); // memory allocation = alocacao de memoria
    novo->conteudo = n;
    novo->prox = NULL;

    no *aux;
    if(lista == NULL){// significa que eu nao tenho elementos na lista.
        lista = novo;
        fim_fila = novo;
    }else{
        //prcurar qual o endereço do último elemento nessa FILA
        //aux = lista; // estou tentando passar NULL! 
        // while(aux->prox != NULL){// o ultimo elemento tem ->prox == NULL
        //     aux = aux->prox; /// 
        // }
        fim_fila->prox = novo; // pega o fim da fila ATUAL e coloca o novo como próximo elemento.
        fim_fila = novo; // ponteiro para fim_fila passa a apontar para novo!
        // aux terá o endereço do ULTIMO elemento da lista
        // aux->prox = NULL , isso equivale a dizer que eu estou com o endereco
        // do ultimo elemento em aux
    
        //aux->prox = novo;
    }

}

void add_fila_while(int n){
    no *novo;

    novo = malloc(sizeof(no)); // memory allocation = alocacao de memoria
    novo->conteudo = n;
    novo->prox = NULL;

    no *aux;
    if(lista == NULL){// significa que eu nao tenho elementos na lista.
        lista = novo;
    }else{
        //prcurar qual o endereço do último elemento nessa FILA
        aux = lista; // estou tentando passar NULL! 
         while(aux->prox != NULL){// o ultimo elemento tem ->prox == NULL
             aux = aux->prox; /// 
         }
        // aux terá o endereço do ULTIMO elemento da lista
        // aux->prox = NULL , isso equivale a dizer que eu estou com o endereco
        // do ultimo elemento em aux
        aux->prox = novo;
    }

}

int listar(){
    //percorrer 
    no *aux;
    aux = lista;
    while(aux!=NULL){
        printf("Listando: %d \n",aux->conteudo);
        aux = aux->prox;
    }
}

int remover_fila(){
    int removido;
    
    no *aux = lista; // estou tentando passar NULL! 
    if(lista == NULL){
        return -1;
    }else{
        if(aux->prox == NULL){
            //remover o próximo aux. (que aqui é lista )
            removido = aux->conteudo;
            free(aux); // free(lista)
            lista = NULL;
        }else{
            while(aux->prox->prox != NULL){
                 aux = aux->prox; //
            }
            // aux vai ter o endereço do PENULTIMO elemento 
            no *ultimo = aux->prox;
            aux->prox = NULL;
            removido = ultimo->conteudo;
            free(ultimo);
        }
    }
    
    return removido;
}

int remover_topo(){
    // lista : contém o endereço do último adicionado
    no *a_remover;
    int removido;
    a_remover = lista;
    lista = lista->prox; // aponta o começo da lista para o próximo disponível.
    removido = a_remover->conteudo;
    free(a_remover); // liberar o espaço de memória referente ao endereço que eu guardei em remover.
    return removido;
}


int main (void) {
    // ate aqui, lista é NULL
    // adiciona(1);
    // printf("Conteudo em lista: %d \n",lista->conteudo);
    // adiciona(2);
    // printf("Conteudo em lista: %d \n",lista->conteudo);
    // adiciona(3);
    // printf("Conteudo em lista: %d \n",lista->conteudo);
    add_fila(1);
    add_fila(2);
    add_fila(3);
    listar();
    int n = remover_fila();
    printf("Elemento removido: %d\n",n);
    listar();

    //remove(1);
    // int removido = remover_topo();
    // printf("Elemento removido: %d\n",removido);
    // listar();
    //listar();

   return 0;
}