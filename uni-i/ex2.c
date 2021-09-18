#include <stdio.h>
//Fac ̧a um algoritmo recursivo para 
//calcular a soma dos N primeiros nu ́meros. 
//(para ser recursivo, vocˆe
//  n ̃ao deve usar a f ́ormula de Progress ̃ao Aritm ́etica)

//ex: n=10 ==> 1+2+3+4+5+6+7+8+9+10.

int soma_n(int n){
    int soma = 0;
    for (int i=1;i<=n;i++){
        printf("%d + ",i);
        soma = soma + i; 
    }
    return soma; 
}

int soma_nrrr(int n){
    int soma;
    if(n==1){
        return 1;
    }else{
        soma = n + soma_nrrr(n-1);
    }
    return soma;
}

int soma_nrr(int i,int n){
    printf("entrou na funcao, valores: i =%d, n = %d \n\n",i,n);
    int soma =0;
    
    if(i==n){
        printf("BASE! n=%d\n",n);
        return n;
    }else{
        int passo_recursivo = soma_nrr(i+1,n);
        printf("Vou somar agora i =%d com %d \n ",i,passo_recursivo);
        soma = i + passo_recursivo;
    }
    
    return soma;
}

int soma_nr(int n){
    return soma_nrr(1,n);
}


int main(void){
    int n;
    printf("Digite um valor: \n");
    scanf("%i",&n);
    
    int res = soma_nr(n);
    
    printf("Resultado: %d",res);

    return 0;
}