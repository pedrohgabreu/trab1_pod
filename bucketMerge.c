#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bucket.h"

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    int i, j, k;

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void BucketSortMerge(int arr[], int n, int n_bucket, int interval) {
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

    for (i = 0; i < n_bucket; i++) {
        if (bucket_sizes[i] > 1) {
            merge_sort(buckets[i], 0, bucket_sizes[i] - 1);
        }
    }

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