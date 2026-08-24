#include <stdio.h>
#include <stdlib.h>
#include "ListaEstáticaSequencial.h"

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