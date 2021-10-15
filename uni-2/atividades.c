#include <stdio.h>
#include <string.h>

#define TAM 10

int pilha[TAM]; // variável que guar a pilha (de inteiro)
int topo = -1;

//FILA 
int fila[TAM];
int primeiro = -1;
int ultimo = -1;
// FILA 


int fila_vazia (){
    if (primeiro == -1 && ultimo == -1){
        return 1;
    }else{
        return -1;
    }
}

int pilha_vazia(){
    if(topo==-1){
      return 1;
     }
    else{
       return -1; 
    }    
}

int tam_pilha(){
   return topo+1;
}


int pilha_cheia(){

    if (topo == TAM -1){
        return 1;    
    }else{
        return -1; // pilha nao está cheia
    } 
}

void push(int n){
// adicionar elemento em pilha
    if (pilha_cheia() == -1){ // se pilha nao está cheia
        topo++; // agora eu vou adicionar em topo = topo +1
        pilha[topo] = n; // adiciona em i o valor n 
    }else{
        printf("PILHA CHEIA!");
    }
   
}

void listar_pilha(){
    
        for (int i =0;i<TAM;i++){
        printf("%d, ",pilha[i]);
            }
    
}


int topo_pilha(){
    return pilha[topo];
}

int pop(){
    
    if (pilha_vazia() ==-1){ //pilha nao está vazia
        int res = pilha[topo];
        pilha[topo] = 0;
        topo--; // topo = topo -1;    
        return res; 
    }else{
        printf(" PILHA VAZIA!");
    }
    return -1;
}

// ENTRADA: valor n 
// SAIDA: uma fila com o valor n adicionado 
void enfileira(int n){
    if(fila_vazia() ==1){
     // primeira e ultima == -1 
     ultimo =0; 
     primeiro= 0; 

    }else{
        ultimo = ultimo +1;
    }
          fila[ultimo] = n;       
}

int desenfileira(){
      int res;   
    if(fila_vazia() ==-1){
        res = fila[primeiro];
        fila[primeiro] = 0;
        if (primeiro == ultimo){
            primeiro = -1;
            ultimo = -1;
        }else{
            primeiro++;
        }
        
    }else{
        printf("FILA VAZIA");
    }
   return res;
}

void lista_fila(){ 
    
for (int i = 0; i < TAM ; i++ ){ 
        printf("%d, ", fila[i]);
    }    
}

void mostra_primeiro_ultimo(){
printf("primeiro: %d ultimo: %d \n",primeiro,ultimo);    
}


void enfila(int n){

    // puder adicionar (fila nao está cheia)
    if((primeiro == ultimo+1) || (primeiro == 0 && ultimo+1 == TAM)){
     printf("FILA CHEIA"); 
    }else{
        if(ultimo +1 == TAM){
            ultimo = 0;
        }else{
            if(primeiro == -1 && ultimo == -1){
                primeiro = 0;
                ultimo = 0;
            }else{
                ultimo++;    
            }
        }
    }
    
    fila[ultimo] = n;
}

int desfila(){
    int res;
    if(fila_vazia() == 1){
        printf("FILA VAZIA!"); 
    }else{
        res = fila[primeiro];
        fila[primeiro] =0;
        if (primeiro == ultimo){
            primeiro = -1;
            ultimo = -1;
        }else{
            if(primeiro+1 == TAM){
                primeiro = 0;
            }else{
                primeiro++;
            }
        }
    }
    return res;
}


int main(void) {
     

    enfila(10);
    mostra_primeiro_ultimo();
    
    enfila(20);
    mostra_primeiro_ultimo();
    
    enfila(30);
    mostra_primeiro_ultimo();
    
    enfila(30);
    mostra_primeiro_ultimo();
    
    enfila(30);
    mostra_primeiro_ultimo();
    
    enfila(30);
    mostra_primeiro_ultimo();
    
    enfila(30);
    mostra_primeiro_ultimo();
    
    enfila(30);
    mostra_primeiro_ultimo();
    lista_fila();

    int a = desfila();
    printf("elemento removido: %d\n",a);
    mostra_primeiro_ultimo();

    a = desfila();
    printf("elemento removido: %d\n",a);
    mostra_primeiro_ultimo();
    
    a = desfila();
    printf("elemento removido: %d\n",a);
    mostra_primeiro_ultimo();

    lista_fila();
    
    enfila(40);
    mostra_primeiro_ultimo();

    enfila(50);
    mostra_primeiro_ultimo();

    enfila(60);
    mostra_primeiro_ultimo();
    enfila(60);
    mostra_primeiro_ultimo();
    enfila(60);
    mostra_primeiro_ultimo();    
    
    lista_fila(); 

    a = desfila();
   printf("elemento removido: %d\n",a);
    mostra_primeiro_ultimo();

    lista_fila();

    return 0;
}