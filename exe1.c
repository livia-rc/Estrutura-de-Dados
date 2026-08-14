/*Enunciado: Dado um vetor de números inteiros v de tamanho n e um número k, retorne verdadeiro
se a soma de qualquer par de números em v for igual a k.
○ Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17*/

#include <stdio.h>
#include <stdbool.h>

bool somaNum(int v[], int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] + v[j] == k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int v[100];
    int k, n, valor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    printf("Digite os valores que deseja inserir no vetor:\n");

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        v[i] = valor;
    }

    printf("Digite o valor de k: ");
    scanf("%d", &k);

    if (somaNum(v, n, k)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}