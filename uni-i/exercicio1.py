# entrada : um valor 0 <= n <= 10^1000000
# saida: n*n-1*n-2*....*1

res = ""
def imprime(i):
    global res
    res = res + str(i) # joga na string 
    if (i>1):
        res = res+"*"

def fat_n_recursivo(n):
    # loop de n até 1 , passo -1
    for i in range(n,0,-1):
        imprime(i)

    print(res)


# n = int(input())
# fat_n_recursivo(n)

        
            
               

                                                          
                                                                          

def fat(n):
    # caso base 
    #quando n chegar a 1, pare.
    res = 1
    if (n ==1): ## condicao de parada (similar ao while (n!= 1))
        return 1
    else:
        # passo (recursivo) 
        ### n = n-1
        res = n * fat(n-1)
        return res

## bobo(3)
#    ## bobo(2)
#    #    ## bobo(1)
#    #        ## 1
#    #    
#   # "2"
# "3"


def bobo(n):
    print("entrou em bobo("+str(n)+")")
    if (n==1):
        print("é 1!")
        return 1
    else:
        res = bobo(n-1)
        print("bobo! "+str(n))
        return res
#execucao
print(bobo(3))
 