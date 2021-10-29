#include <stdio.h>
#include <string.h>
typedef struct {
    char titulo[100];
    char data[11];
    char descricao[150];
    int responsavel;
} evento;

FILE *arquivo_calendario;

void remover_evento(char titulo[]);
int buscar_evento(char titulo[]);


// adiciona um novo evento no calendário
void ler_e_adicionar(){
    evento e;
    printf("Lendo informações do evento"); 
    // add_evento(e);
}

void add_evento(evento e){
    //abre o arquivo em modo escrita/append
    arquivo_calendario = fopen("calendario.csv","a");
    // o arquivo foi aberto corretamente?
    if (arquivo_calendario !=NULL){
        fprintf(arquivo_calendario,"%s;%s;%s;%d\n",e.titulo,e.data,e.descricao,e.responsavel);
        fflush(arquivo_calendario); // para adicionar de facto
        fclose(arquivo_calendario);
    }{
        printf("Erro ao adicionar evento."); 
    }
}

void perguntar_e_buscar(){
    printf("Qual evento gostaria de buscar? \n");
    char titulo[100];
    scanf("%s\n",titulo);
    buscar_evento(titulo);
}

void perguntar_e_remover(){
    printf("Qual evento gostaria de remover? \n");
    char titulo[100];
    scanf("%s\n",titulo);
    remover_evento(titulo);
}

int buscar_evento(char titulo[]){

    char buscado[100];
    strcpy(buscado,titulo);
    // aqui posso procurar no arquivo todo
    // e depois volto o ponteiro do arquivo para o começo
    arquivo_calendario = fopen("calendario.csv","r"); // modo leitura, vou só procurar
    // o arquivo foi aberto corretamente?
    if (arquivo_calendario !=NULL){
        evento e;
        while (!feof(arquivo_calendario)){
            // pego as informações
            fscanf(arquivo_calendario,"%[^*;];%[^*;];%[^*;];%d\n",e.titulo,e.data,e.descricao,&e.responsavel);
            if (strncmp(buscado,e.titulo,sizeof(buscado))== 0) {
                printf("Evento encontrado:\n %s\n %s\n%s\n%d",e.titulo,e.data,e.descricao,e.responsavel);
                return 0;
            }
        }
        printf("Nada encontrado!");
        return -1;
    }
    fclose(arquivo_calendario);
}

void remover_evento(char titulo[]){
// TODO
}

evento calendario[365];// temos um limite aqui
//recursivo!    
void listar_eventos_nao_recursivo(){
    
    // de forma não recursiva, o processo é simples: basta abrir o arquivo e ler até o final dele!
    int indice_calendario = 0;
    arquivo_calendario = fopen("calendario.csv","r"); // modo de leitura!
    if(arquivo_calendario != NULL){    
        while (!feof(arquivo_calendario)){
            // pego as informações
            evento e; // crio um novo evento
            fscanf(arquivo_calendario,"%[^*;];%[^*;];%[^*;];%d\n",e.titulo,e.data,e.descricao,&e.responsavel);
            // apresento elas
            calendario[indice_calendario] = e; 
            indice_calendario++; // numero de elementos que tem no calendário
            // indice do próximo vazio

        }
        fclose(arquivo_calendario);
    }
   
    int tamanho = indice_calendario;
    for (int i=0;i<tamanho;i++){ // 
        printf("%s\n \t %s, %s, %d\n\n",calendario[i].titulo,calendario[i].data,calendario[i].descricao,calendario[i].responsavel);    
    }
}

void lista_rec2(FILE *arquivo){
    printf("Entrou!\n");
    if(feof(arquivo)){
        printf("Chegou no fim!\n");
    }else{
        evento e;
        fscanf(arquivo_calendario,"%[^*;];%[^*;];%[^*;];%d\n",e.titulo,e.data,e.descricao,&e.responsavel);
        lista_rec2(arquivo);
        printf("%s \n \t %s\n%s \n %d\n\n",e.titulo,e.data,e.descricao,e.responsavel);
    }
}


void imprime_lista(int indice,int fim){ // 4,5
    if(indice == fim){ // cheguei no fim da lista! 
            // 5, 5
    }else{
        printf("%s\n \t %s, %s, %d\n\n",calendario[indice].titulo,calendario[indice].data,calendario[indice].descricao,calendario[indice].responsavel);    
        imprime_lista(indice+1,fim); //5,5
    }
}



void listar_eventos_recursivo(){
    // nesse caso, vamos fazer duas funções, como vimos em aula:
    // esta aquim que recebe a "solicitação", 
    // e que vai organizar tudo para realizarmos a recursao .
    
    // para saber quantas linhas ele tem, e a partir dai, gerar a lista de calendario
    int indice_calendario = 0;
    arquivo_calendario = fopen("calendario.csv","r"); // modo de leitura!
    if(arquivo_calendario != NULL){
        
        while (!feof(arquivo_calendario)){
            // pego as informações
            evento e; // crio um novo evento
            fscanf(arquivo_calendario,"%[^*;];%[^*;];%[^*;];%d\n",e.titulo,e.data,e.descricao,&e.responsavel);
            // apresento elas
            calendario[indice_calendario] = e;
            indice_calendario++;
        }
    }
    // neste momento, terei um calendario em uma lista! basta agora iterar sobre ela, recursivamente.
    imprime_lista(0,indice_calendario); // ou seja, vou de 0 até o numero de itens

}
void show_opcoes(){
    printf("Ola, bem vindo ao calendario!Escolha sua opcao:\n"); 
    printf("1 - Novo evento\n");
    printf("2 - Buscar eventos\n");
    printf("3 - Remover evento\n");
    printf("4 - Listar eventos (não recursivamente)\n");
    printf("5 - Listar eventos (recursivamente)\n");
    printf("6 - Tchau!\n");
}
void menu(){
    show_opcoes();
    int opcao;
    scanf("%d",&opcao);
    while(opcao != 6){
        switch(opcao){
        case 1:
        ler_e_adicionar();
        break;
        case 2:
        perguntar_e_buscar();
        break;
        case 3:
        perguntar_e_remover();
        break;
        case 4:
        listar_eventos_nao_recursivo();
        break;
        case 5:        
            arquivo_calendario = fopen("calendario.csv","r");
            if(arquivo_calendario != NULL){
                lista_rec2(arquivo_calendario);
            }
        break;
    };
        show_opcoes();
        scanf("%d",&opcao);
    }    
}

int main (void){
    menu();
    return 0; 
}
