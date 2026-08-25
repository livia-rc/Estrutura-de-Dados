#include <stdio.h>
#include <stdlib.h>
#include "ListaEstaticaSequencial.h"

int main(){
    //criação de um vetor do tipo struct aluno com 4 elementos(alunos)
    struct aluno a[4] = {{2,"Bruno",9.5,7.8,8.5},
                            {4,"Ricardo",7.5,8.7,6.8},
                            {1,"Bianca",9.7,6.7,8.4},
                            {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista(); //função que cria a lista
    int i;
    for(i=0; i < 4; i++){
        insere_lista_ordenada(li,a[i]); //vai ordenar a lista pela matrícula
    }

    imprime_lista(li); //vai imprimir a lista
    printf("\n\n");

    for(i=0; i < 5; i++){
        if (!remove_lista(li,i)){ // ! é um operador de negação ou seja esse if quer dizer: Se a remoção NÃO foi realizada...
            //nesse caso a função vai remover pelo índice
            printf("Erro\n\n");
        }

        imprime_lista(li); //imprime a lista após cada tentativa
        printf("\n\n");
    }

    libera_lista(li);
    system("pause");
    return 0;
}