#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// entrada
// LISTA (vetor) com numeros , possivelmente desordenados
int lista[130000];


// ordenacao por insercao (insertion sort)
void insertion_sort(int lista[],int tamanho_lista){
 
    // criar uma nova lista 
    int nova_lista[130000];
    int tamanho_lista_nova = 0;
    // pega o primeiro elemento da lista antiga, e coloca na nova.
    nova_lista[0] = lista[0]; // pega o conteúdo de nova_lista[1] e colocando em lista[1]
    tamanho_lista_nova = 1;

    // percorrer a lista antiga do segundo ate o ultimo elemento 
    for(int indice_antiga = 1; indice_antiga< tamanho_lista; indice_antiga++){
        
        // pega o elemento atual da lista antiga e coloca na lista nova , na última posicao. 
        tamanho_lista_nova++;
        nova_lista[tamanho_lista_nova-1] = lista[indice_antiga];
        printf("nova_lista: %d\n", nova_lista[tamanho_lista_nova-1]);
        
        printf("tamanho_lista_nova: %d\n",tamanho_lista_nova);
        for (int i = 0 ; i<tamanho_lista_nova;i++){
                       printf("%d,",nova_lista[i]);
                    }
                    printf("\n");
        // percorre da penultima posicao da lista nova até o começo da lista nova, e compara.
        for(int indice_nova = tamanho_lista_nova-2;indice_nova>=0;indice_nova--){
               // se o elemento que eu acabei de inserir for menor, eu troco.
               nova_lista[indice_nova]; // guarda o penultimo item
               if(nova_lista[indice_nova] > nova_lista[indice_nova+1]){
                   //troca!
                   int aux = nova_lista[indice_nova];
                   nova_lista[indice_nova] = nova_lista[indice_nova+1];
                   nova_lista[indice_nova+1] = aux;

                   for (int i = 0 ; i<tamanho_lista_nova;i++){
                       printf("%d,",nova_lista[i]);
                    }
                    printf("\n");

               } else{
                   break;
               }
        }
    }
printf("Tamanho Lista nova: %d\n", tamanho_lista_nova);
 printf("Lista ordenada:\n");
    for (int i = 0 ; i<tamanho_lista_nova;i++){
        printf("%d,",nova_lista[i]);
    }

}

// ordenacao por selecao (selection sort)
void selection_sort(int lista[],int tamanho_lista){

}

// ordenacao por  "bolha" (bubble sort
void bubble_sort(int lista[],int tamanho_lista){
    
    //percorrer tudo até que eu nao precise mais fazer trocas
    printf("Lista desordenada:\n");
    for (int i = 0 ; i<tamanho_lista;i++){
        printf("%d\n",lista[i]);
    }

    int fez_troca; //FLAG (GERALMENTE BOOLEANO)
    do{
        fez_troca = 0; 
        for (int i = 0;i<tamanho_lista-1;i++){
            // se preciso fazer troca entre lista[i] e lista[i+1]
            //ex:  3 , 2  (lista[i] > lista[i+1])!
            if(lista[i] > lista[i+1]){
                //trocar! 
                int aux;
                aux = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aux;
                fez_troca = 1; // FLAG LEVANTADA

                printf("Passo:\n");
                for (int i = 0 ; i<tamanho_lista;i++){
                    printf("%d,",lista[i]);
                }
                printf("\n");
            }

        }
        // tamanho_lista--;
    
        

    }while(fez_troca == 1);
    
    // FEZ_TROCA == 0 
    // SINAL QUE FOI ORDENADA A LISTA! 
    
    printf("Lista ordenada:\n");
    for (int i = 0 ; i<tamanho_lista;i++){
        printf("%d,",lista[i]);
    }

}


// divisao e conquista
int merge_sort(int lista[],int inicio,int fim){

    if(fim > inicio){
           // meio 
        int meio = floor(inicio+fim)/2; 

        merge_sort(lista,inicio,meio);
        merge_sort(lista,meio+1,fim);
        
        merge(lista,inicio,meio,fim);

    }
}

void quick_sort(int lista[]){

}


int main(void){
    int tamanho_lista = 10;
    int valor = tamanho_lista;

    for (int i =0;i<tamanho_lista;i++){
        //loop para gerar numeros aleatorios.
        lista[i] = (int) rand()/100000000;
        //lista[i] = i;
      //  valor--;
       // printf("Numero %d \n",lista[i]);
    }
  
   clock_t t;
   t = clock();
   // bubble sort 
    // bubble_sort(lista,tamanho_lista);
    //insertion_sort(lista,tamanho_lista);
    merge_sort(lista,0,tamanho_lista-1);
   
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   printf("\nO programa levou %f segundos para rodar", time_taken);

   
 
 
    
    return 0; 
}