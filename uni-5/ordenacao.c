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
/// PIOR CASO: lista inversamente ordenada
// ex: 5,4,3,2,1 4
//     4,3,2,1,5 3 ... 2.... 1
     
    int fez_troca; //FLAG (GERALMENTE BOOLEANO)
    do{
        fez_troca = 0; 

        // n-1 vezes.
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

                // ///printf("Passo:\n");
                // for (int i = 0 ; i<tamanho_lista;i++){
                //    // printf("%d,",lista[i]);
                // }
                // //printf("\n");
            }

        }
        // tamanho_lista--;
    
    }while(fez_troca == 1);
    
    
}

void merge (int lista[],int inicio,int meio,int fim){
 //printf("conquista");
 //print da (sublista) que vai de inicio até fim

    int indice1 = inicio; // até o meio
    int indice2 = meio+1; // fim

    int tamanho_l3 = fim-inicio+1;
    int l3[tamanho_l3];

    for(int i = 0;i<tamanho_l3;i++){
        if(indice1 <= meio && indice2 <=fim){
            if(lista[indice1] > lista[indice2]){
                l3[i] = lista[indice2];             
                indice2++;
            }else{ // lista[indice1] <=  lista[indice2] (menor ou igual ) 
                l3[i] = lista[indice1];
                indice1++;
            }
        }else{
            //quem chegou no fim da lista? 
            if(indice2 > fim){
                //l2 "esgotou"
                l3[i]=lista[indice1];
            }else{
                l3[i] = lista[indice2];
            }
        }
    }
    int i = 0;
    for(int j = inicio;j<=fim;j++){
        lista[j] = l3[i];
        i++;
    }
}

// divisao e conquista
int merge_sort(int lista[],int inicio,int fim){
    //printf("divisao");

    if(fim > inicio){
           // meio 
        int meio = floor(inicio+fim)/2; // (0 + 1) / 2 = 0,5 => 0 

        merge_sort(lista,inicio,meio); 
        merge_sort(lista,meio+1,fim);
        
        // inicio = 0, meio =  0, fim = 1 
        //merge(lista,0,0,1);
        merge(lista,inicio,meio,fim);
    }
}

int main(void){
    int tamanho_lista = 128000;
    int valor = tamanho_lista;

    printf("Lista desordenada: ");
    for (int i =0;i<tamanho_lista;i++){
        //loop para gerar numeros aleatorios.
        lista[i] = (int) rand()/1000;
        //lista[i] = i;
        // valor--;
        //printf(" %d,",lista[i]);
    }
    printf("\n");
   clock_t t;
   t = clock();
   // bubble sort 
    // bubble_sort(lista,tamanho_lista);
    //insertion_sort(lista,tamanho_lista);
    merge_sort(lista,0,tamanho_lista-1);
   
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   
   printf("Lista ordenada: ");
   for (int i= 0;i<tamanho_lista/100;i++){
       printf("%d,",lista[i]);
   }

   printf("\n\nO programa levou %f segundos para rodar", time_taken);
    
    return 0; 
}