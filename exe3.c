#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 6

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}

int main() {
    int vetor[M];

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o vetor com valores aleatórios
    for (int i = 0; i < M; i++) {
        vetor[i] = rand() % 100;
    }

    // Mostra o vetor antes da ordenação
    printf("Vetor antes da ordenacao:\n");

    for (int i = 0; i < M; i++) {
        printf("%d ", vetor[i]);
    }

    // Ordena o vetor
    insertionSort(vetor, M);

    // Mostra o vetor depois da ordenação
    printf("\n\nVetor depois da ordenacao:\n");

    for (int i = 0; i < M; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}