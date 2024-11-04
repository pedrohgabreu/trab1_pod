#include <stdio.h>
#include <stdlib.h>
#include "bucket.h"

/* Função auxiliar para trocar elementos */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getBucketIndex(int value, int interval) {
  return value / interval;
}