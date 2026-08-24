/*Enunciado: Dado um vetor de números inteiros v, retorne um novo vetor de forma que cada
elemento no índice i seja o produto de todos os números na matriz original, com
exceção de i.
○ Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24]
○ Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6]*/

#include <stdio.h>

int main(){
    int v[100];
    int tamanho, valores;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    printf("\nDigite os valores que deseja inserir no vetor:\n");
    for (int i = 0; i < tamanho; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valores);
    }
    
    return 0;
}

int produtoNum(int v[], int tamanho){
    int g[100], produto; 
    for (int i = 0; i < tamanho; i++){
        for (int j = 1; j < tamanho; j++){
            v[i] * v[j] == produto;
            g[i] == produto;
        }
        
    }
    
}