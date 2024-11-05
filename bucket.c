#include <stdio.h>
#include <stdlib.h>
#include "bucket.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getBucketIndex(int value, int interval) {
  return value / interval;
}

void print(int ar[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int VerificaOrdenado(int arr[], int tam){
    int i, j, k; 
    long int count = 0;
    for(i = 1; i<tam; i++){
        j = arr[i-1];
        k = arr[i];
        if(j<=k) count ++;
    }
    if(tam == count+1) return 1;
    return 0;
}

/* Função para gerar o array a partir do arquivo */
void geraArray(int *array, int NARRAY, char *fileName) {
    int n = 0; 

    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", fileName);
        free(array);  
        return;
    }

    while (fscanf(file, "%d", &array[n]) == 1 && n < NARRAY) {
        n++;
    }
    fclose(file);
}