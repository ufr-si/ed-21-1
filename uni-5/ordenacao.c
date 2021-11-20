#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// entrada
// LISTA (vetor) com numeros , possivelmente desordenados
int lista[130000];


// ordenacao por insercao (insertion sort)

// ordenacao por selecao (selection sort)

// ordenacao por  "bolha" (bubble sort
void bubble_sort(int lista[],int tamanho_lista){
    
    //percorrer tudo até que eu nao precise mais fazer trocas
    printf("Lista desordenada:\n");
    for (int i = 0 ; i<tamanho_lista;i++){
        printf("%d\n",lista[i]);
    }

    int fez_troca;
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
                fez_troca = 1;
            }
        }
        // tamanho_lista--;

    }while(fez_troca == 1);
    
    printf("Lista ordenada:\n");
    for (int i = 0 ; i<tamanho_lista;i++){
        printf("%d\n",lista[i]);
    }

}


int main(void){
    int tamanho_lista = 128000;
    int valor = tamanho_lista;

    for (int i =0;i<tamanho_lista;i++){
        //loop para gerar numeros aleatorios.
        //lista[i] = rand();
        lista[i] = i;
        valor--;
        printf("Numero %d \n",lista[i]);
    }

  
   clock_t t;
   t = clock();
   // bubble sort 
    bubble_sort(lista,tamanho_lista);
   
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   printf("O programa levou %f segundos para rodar", time_taken);
 
 
    
    return 0; 
}