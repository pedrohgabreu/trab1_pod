#ifndef _BUCKET_H_
#define _BUCKET_H_

void BucketSort(int arr[], int n, int n_bucket, int interval);
void BucketSortMerge(int arr[], int n, int n_bucket, int interval);
void BucketSortQuick(int arr[], int n, int n_bucket, int interval);
void BucketSortHeap(int arr[], int n, int n_bucket, int interval);

int VerificaOrdenado(int arr[], int tam);

void print(int ar[], int n);
int getBucketIndex(int value, int interval);
void swap(int *a, int *b);


#endif