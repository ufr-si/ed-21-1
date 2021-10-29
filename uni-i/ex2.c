#include <stdio.h>
//Fac ̧a um algoritmo recursivo para 
//calcular a soma dos N primeiros nu ́meros. 
//(para ser recursivo, vocˆe
//  n ̃ao deve usar a f ́ormula de Progress ̃ao Aritm ́etica)

//ex: n=10 ==> 1+2+3+4+5+6+7+8+9+10.

int soma_n(int n){
    int soma = 0;
    for (int i=1;i<=n;i++){ // 
        printf("%d + ",i); // 
        soma = soma + i; 
    }
    return soma; 
}


int soma_nrrr(int n){ // fim 
    int soma;
    if(n==1){ // inicio
        return 1;
    }else{
        soma = n + soma_nrrr(n-1);
    }
    return soma;
}



// n == 5 
int lista[100];

void soma_recursivo(int i,int n){ //1 ,5 
    int soma =0;
    if(i==n){ // base da recursaox
       // return n; //
    }else{
        printf("%d",lista[i]); 
        soma_recursivo(i+1,n); // 4, 5
       // soma = 3 + 9; //12 
    }
    // return soma; //12 
}

int soma_nr(int n){ // 
    soma_recursivo(0,n); // n = 5
}


int main(void){
    int n;
    printf("Digite um valor: \n");
    scanf("%i",&n);
    
    int res = soma_nr(n);
    
    printf("Resultado: %d",res);

    return 0;
}