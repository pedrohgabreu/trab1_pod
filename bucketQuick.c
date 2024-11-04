#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "bucket.h"

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}



void BucketSortQuick(int arr[], int n, int n_bucket, int interval) {
    int** buckets = (int**)malloc(n_bucket * sizeof(int*));
    int* bucket_sizes = (int*)malloc(n_bucket * sizeof(int));

    int i, j;

    for (i = 0; i < n_bucket; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        bucket_sizes[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int pos = arr[i] / interval;
        if (pos >= n_bucket) {
            pos = n_bucket - 1;
        }
        buckets[pos][bucket_sizes[pos]] = arr[i];
        bucket_sizes[pos]++;
    }

    /*for (i = 0; i < n_bucket; i++) {
        printf("Bucket[%d]: ", i);
        for (j = 0; j < bucket_sizes[i]; j++) {
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }*/

    for (i = 0; i < n_bucket; i++) {
        quick_sort(buckets[i], 0, bucket_sizes[i] - 1);
    }

    /*printf("-------------\n");
    printf("Bucktets after sorting\n");
    for (i = 0; i < n_bucket; i++) {
        printf("Bucket[%d]: ", i);
        for (j = 0; j < bucket_sizes[i]; j++) {
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }*/

    int k = 0;
    for (i = 0; i < n_bucket; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucket_sizes);
}

