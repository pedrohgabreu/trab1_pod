#include <stdio.h>
#include <stdlib.h>
#include "bucket.h"

/* Função para criar o heap máximo */
void heapify(int arr[], int n, int i) {
    int largest = i;          /* Inicializa o maior como raiz */
    int left = 2 * i + 1;     /* Filho à esquerda */
    int right = 2 * i + 2;    /* Filho à direita */

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);  /* Heapify a subárvore */
    }
}

/* Função principal do Heap Sort */
void HeapSort(int arr[], int n) {
    int i;
    /* Constrói o heap (reorganiza o array) */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Extrai um a um os elementos do heap */
    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);    /* Move a raiz para o final */
        heapify(arr, i, 0);        /* Chama heapify no heap reduzido */
    }
}

/* Função de Bucket Sort que usa Heap Sort */
void BucketSortHeap(int arr[], int n, int n_bucket, int interval) {
    /* Cria buckets */
    int **buckets = (int **)malloc(n_bucket * sizeof(int *));
    int *bucket_sizes = (int *)malloc(n_bucket * sizeof(int));
    int i, j = 0;
    for (i = 0; i < n_bucket; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucket_sizes[i] = 0;
    }

    /* Distribui os elementos nos buckets */
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] / interval;
        if (bucket_index >= n_bucket) bucket_index = n_bucket - 1;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    /* Ordena cada bucket individualmente usando Heap Sort e concatena */
    int index = 0;
    for (i = 0; i < n_bucket; i++) {
        if (bucket_sizes[i] > 0) {
            HeapSort(buckets[i], bucket_sizes[i]);
            for (j = 0; j < bucket_sizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
        free(buckets[i]);  /* Libera o bucket após uso */
    }

    free(buckets);
    free(bucket_sizes);
}
