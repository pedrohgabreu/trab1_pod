#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BUCKETS 10

void insertionSort(int *arr, int n);
void bucketSort(int *arr, int n);
void printArray(int *arr, int n);

int main() {
    int n = 1000000;
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }



    bucketSort(arr, n);



    free(arr);
    return 0;
}

void bucketSort(int *arr, int n) {
    int **buckets = (int **)malloc(NUM_BUCKETS * sizeof(int *));
    int *bucketCounts = (int *)calloc(NUM_BUCKETS, sizeof(int));

    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * NUM_BUCKETS / 1000;
        if (bucketIndex >= NUM_BUCKETS) {
            bucketIndex = NUM_BUCKETS - 1;
        }
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (bucketCounts[i] > 0) {
            insertionSort(buckets[i], bucketCounts[i]);
            for (int j = 0; j < bucketCounts[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


