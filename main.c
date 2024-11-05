/* Aqui faremos as comparacoes dos algoritmos de ordenacao, criando um relatorio com base nas medidas de cada variacao do algoritmo */
/*para compilar: gcc -ansi -o main main.c bucket.c bucketInsert.c bucketMerge.c bucketHeap.c bucketQuick.c -lm*/ 
/*para executar: ./main 100 100 >> final.txt*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "bucket.h"

int iniValues(int argc, char *argv[], int *nArr, int *nBuck, int *inter){
    /* Verifica se foram passados os argumentos corretos */
    if (argc != 3) {
        printf("Uso: %s <tamanho_do_array> <arquivo_com_numeros>\n", argv[0]);
        return 1;
    }

    /* Converte o primeiro argumento para o tamanho máximo do array */
    *nArr = atoi(argv[1]);
    if (*nArr <= 0) {
        printf("O tamanho do array deve ser um número positivo.\n");
        return 1;
    }

    *nBuck = (int)sqrt(*nArr);
    *inter = (int)(*nArr / *nBuck) + 1;
    return 0;
}

void testWithPrint(int *array, int NARRAY, int NBUCKET, int INTERVAL, char *fileName){
    clock_t start, end;
    double time_spent;

    geraArray(array, NARRAY, fileName);
    printf("Dados iniciais de tamanho %d: \n", NARRAY);
    printf("-------------\n");

    /*Heap Sort*/
    printf("    Bucket com Heap Sort:\n");
    start = clock(); 
    BucketSortHeap(array, NARRAY, NBUCKET, INTERVAL);
    end = clock(); 
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    geraArray(array, NARRAY, fileName);
    printf("    -------------\n");

    /*Merge Sort*/
    printf("    Bucket com Merge Sort:\n");
    start = clock();
    BucketSortMerge(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    geraArray(array, NARRAY, fileName);
    printf("    -------------\n");

    /*Quick Sort*/
    printf("    Bucket com Quick Sort:\n");
    start = clock();
    BucketSortQuick(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    geraArray(array, NARRAY, fileName);
    printf("    -------------\n");

    /*Insert Sort*/
    printf("    Bucket com Insert Sort:\n");
    start = clock();
    BucketSort(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));
}

int main(int argc, char *argv[]) {
    int *array;
    int NARRAY, NBUCKET, INTERVAL;

    if(iniValues(argc, argv, &NARRAY, &NBUCKET, &INTERVAL) == 1) return 1; /*Erro*/

    /* Aloca memória para o array */
    array = (int *)malloc(NARRAY * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    char *fileName = argv[2];
    testWithPrint(array, NARRAY, NBUCKET, INTERVAL, fileName);

    free(array);

    return 0;
}
