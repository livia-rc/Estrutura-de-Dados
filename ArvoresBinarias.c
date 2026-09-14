#include <stdio.h>
#include <stdlib.h>

int main(){

    typedef struct no{
        struct no* pai; // ponteiro para o nó pai
        struct no* esquerda; // ponteiro para o nó filho a esquerda
        struct no* direita; // ponnteiro para o nó filho a direita
        float v; // variável para guardar o conteúdo de um nó da árvore
    }No;

    typedef struct arvore{
        struct no* raiz;
    }Arvore;

return 0;
}