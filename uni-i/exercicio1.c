#include <stdio.h>
//  Faca um algoritmo 
//  recursivo para realizar 
//  a exponenciacao entre 
//  2 numeros. (ex.: 2^5)

// ENTRADA: dois numeros
// x,y , 
// SAIDA: x^y
// pensando no problema: 
// ex.: 2^2: 2*2
// 3^5: 3*3*3*3*3
int expon(int x,int y){
    
    int res = 1;
    
    while(y !=0){ // condicao de parada - caso base
        res = res*x; 
        y = y-1; // passo 
    }

    //SAIDA
    return res;

}

int exponr(int x,int y){

    int res = 1;

    if(y==0){
        return 1;
    }else{
        res = res * x * exponr(x,y-1);
    }

    return res;
}


int main (void){
    int x = 0;
    int y = 0;
    printf("Leia o primeiro valor: ");
    
    scanf("%i",&x);
    printf("Leia o segundo valor: ");
    scanf("%i",&y);
    
    int res = exponr(x,y);
    printf("O resultado é: %d\n",res);
    return 0;
}
