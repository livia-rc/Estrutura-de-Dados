#include <stdio.h>
#include <stdlib.h>
#include "ListaEstaticaSequencial.h"

Lista* cria_lista(){
    Lista *li; //declaração do ponteiro que apontará para uma estrutura Lista
    li = (Lista*) malloc(sizeof(struct lista)); //alocação de memória
    if(li != NULL){ //verificar se criou a lista e alocou memória corretamente
        li->quantidade = 0; //Isso significa que a lista acabou de ser criada e possui zero elementos.
    }
    return li; //a função devolve o endereço da lista criada
}

void libera_lista(Lista* li){
    free(li); // free() devolve para o sistema operacional a memória que havia sido reservada anteriormente pelo malloc()
}

int tamanho_lista(Lista* li){ //Retorna a quantidade de elementos atualmente armazenados na lista
    if (li == NULL){ //se a lista não existir vai retornar -1 ou seja um sinal de erro
        return -1;
    } else {
        return li->quantidade; //se a lista existir vai retornar a quantidade de elementos armazenados
    }
}
int lista_cheia(Lista* li){ //verifica se a lista atingiu a capacidade máxima
    if (li == NULL){ //se a lista não existir vai retornar -1 ou seja um sinal de erro
        return -1;
    } else {
        return (li->quantidade == MAX); 
        // Se quantidade == MAX, não existe mais espaço para inserir novos elementos.
        // A expressão retorna:
        //     1 (verdadeiro) -> lista cheia
        //     0 (falso)      -> lista não cheia
    } 
}

int lista_vazia(Lista* li){
    if (li == NULL){ //se a lista não existir vai retornar -1 ou seja um sinal de erro
        return -1;
    } else {
        return (li->quantidade == 0);
        // Se quantidade == 0, significa que nenhum elemento foi inserido na lista.
        // A expressão retorna:
        //     1 (verdadeiro) -> lista vazia
        //     0 (falso)      -> lista possui elementos
    }
    
}

int insere_lista_inicio(Lista* li, struct aluno aluno){ //insere um novo elemento na primeira posição da lista
    if (li == NULL){ //verifica se a lista existe
        return 0;
    } else if (lista_cheia(li)){ //verifica se a lista está cheia
        return 0;
    } else {
        for (int i = li->quantidade-1; i >= 0; i--){ //começa a percorrer pelo último elemento existente ou seja percorre de trás para frente
            li->dados[i+1] = li->dados[i]; //copia o elemento da posição i para a posição i+1 para que assim a posição 0 fique livre
        }
        li->dados[0] = aluno; //colocamos o novo elemento na posição 0
        li->quantidade++; //a lista é incrementada
    }
    return 1; //retorna 1 indicando que a inserção foi realizada
}

int insere_lista_final(Lista* li, struct aluno aluno){ //insere um novo elemento no final da lista. Nessa função não precisamos deslocar nenhum elemento.
    if (li == NULL){ //verifica se a lista existe
        return 0;
    } else if (lista_cheia(li)){//verifica se a lista está cheia
        return 0;
    } else {
        // quantidade indica a próxima posição livre.
        // Se temos:
        // dados[0]
        // dados[1]
        // dados[2]
        // quantidade = 3 e próxima posição livre é dados[3].
        li->dados[li->quantidade] = aluno;
        li->quantidade++; //a lista é incrementada
    }
    return 1; //retorna 1 indicando que a inserção foi realizada
}

int insere_lista_ordenada(Lista* li, struct aluno aluno){// Insere um aluno mantendo a lista ordenada pela matrícula.
    if (li == NULL){// Verifica se a lista existe.
        return 0;
    } else if (lista_cheia(li)){// Verifica se a lista está cheia.
        return 0;
    } else {
        int k, i = 0;
        // Enquanto:
        // 1. ainda não chegamos ao final da lista
        // 2. a matrícula atual é menor que a matrícula do novo aluno
        // continuamos avançando.
        while (i < li->quantidade && li->dados[i].matricula < aluno.matricula){
            i++;
        }
        //percorremos de trás para frente para deslocar os elementos para a direita e abrir espaço para adicionar um novo elemento na posição i
        for (k = li->quantidade-1; k >= i; k--){
            li->dados[k+1] = li->dados[k];
        }
        li->dados[i] = aluno; // Inserimos o novo aluno na posição i
        li->quantidade++; // A lista ganhou um novo elemento.
    }
    return 1; // Inserção realizada com sucesso.
}

int remove_lista_final(Lista* li){
    if(li == NULL){ //verifica se a lista existe 
        return 0;
    } else if (li->quantidade == 0){ //verificanse há elementos na lista
        return 0;
    } else{ //aqui a lista existe e possui pelo menos um elemento
        li->quantidade--; //o ultimo elemento é removido e a lista é decrementada
    }
    return 1; //remoção concluída
}

int remove_lista_inicio(Lista* li){
    if (li == NULL){ //verifica se a lista existe se li for null não temos uma lista válida
        return 0;
    } else if (li->quantidade == 0){ //verifica se há elementos na lista
        return 0;
    } else {
        for (int i = 0; i < li->quantidade - 1; i++){ //esse for desloca todos os elementos uma posição para a esquerda 
            li->dados[i] = li->dados[i+1];
        }
        li->quantidade--; //decrementa a lista em uma posição
    }
    return 1; //remoção concluída
}

//essa função vai remover um aluno procurando pela matrícula
int remove_lista(Lista* li, int mat){
    if(li == NULL){ //verifica se a lista existe 
        return 0;
    } else if(li->quantidade == 0){ //verifica se a há elementos na lista
        return 0;
    }

    int k,i = 0; //a variável i é usada para procurar elementos e a variável k é usada para deslocar elementos
    
    while(i < li->quantidade && li->dados[i].matricula != mat){ //procurar em qual posição está a matrícula que desejamos remover
        // Percorremos a lista enquanto:
        // i ainda estiver dentro da quantidade de elementos e a matrícula encontrada na posição i for diferente da matrícula que estamos procurando.
        i++;
    }

    if(i == li->quantidade){ //Se i chegou a ser igual à quantidade, significa que percorremos toda a parte válida da lista e não encontramos a matrícula.
        return 0; //dessa forma retorna 0
    }

    // A matrícula foi encontrada na posição i. Agora precisamos remover o elemento dessa posição e deslocar todos os elementos que estão
    // depois do elemento removido uma posição para a esquerda.
    for(k=i; k< li->quantidade-1; k++){
        li->dados[k] = li->dados[k+1];
    }

    li->quantidade--;
    return 1;
}

int consulta_lista_posicao(Lista* li, int posicao, struct aluno *aluno){
    if (li == NULL || posicao <= 0 || posicao > li->quantidade){ //se a lista não existir ou a posição for menor ou igual a zero ou a posição for maior que a quantidade de elementos da lista vai retornar null
        return 0;
    } else {
        *aluno = li->dados[posicao - 1]; 
        // A posição informada pelo usuário começa em 1 mas os índices do vetor começam em 0.
        // Exemplo:
        // posicao = 1
        // índice do vetor = 1 - 1 = 0
        // Depois de encontrar o aluno, copiamos seus dados para a variável apontada por 'aluno'.
    }
    return 1; //retorna 1 quando a consulta for realizada com sucesso
}

int consulta_lista_matricula(Lista* li, int matricula, struct aluno *aluno){ // A função recebe a lista que será consultada, matrícula que queremos procurar e endereço da variável que receberá o aluno
    if (li == NULL){ //veificamos se a lista existe 
        return 0;
    }

    int i = 0;

    //procedimento de busca igual como fizemos para remover por matrícula
    while (i < li->quantidade && li->dados[i].matricula != matricula){ //percorremos a lista procurando a matrícula
        // O while continua enquanto:
        // 1. i ainda estiver dentro da quantidade de elementos;
        // 2. a matrícula do aluno atual for diferente da matrícula que estamos procurando.
        i++;
    }
    
    if(i == li->quantidade){ //chegou ao final da lista e não achamos a matrícula vai retornar null indicando que a consulta falhou
        return 0;
    }
    
    // Se chegamos aqui, significa que encontramos a matrícula na posição 'i'.
    // Copiamos o aluno encontrado para a variável apontada por 'aluno'.
    *aluno = li->dados[i];
    return 1; // Retorna 1 indicando que o aluno foi encontrado.
}

// Essa função percorre todos os alunos armazenados e mostra seus dados na tela.
void imprime_lista(Lista* li){
    if(li == NULL){ // Verifica se a lista existe.
        return;
    }
    int i;
    for(i=0; i< li->quantidade; i++){
        printf("Matricula: %d\n",li->dados[i].matricula); //exib a matrícula do aluno atual
        printf("Nome: %s\n",li->dados[i].nome); //exibe o nome do aluno atual
        printf("Notas: %.2f %.2f %.2f\n",li->dados[i].n1, //exibe as tres notas do aluno atual
                                   li->dados[i].n2,
                                   li->dados[i].n3);
        printf("-------------------------------\n"); // Imprime uma linha para separar um aluno do próximo e organizar a saída
    }
}