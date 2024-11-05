/* Aqui faremos as comparacoes dos algoritmos de ordenacao, criando um relatorio com base nas medidas de cada variacao do algoritmo */

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

int main(int argc, char *argv[]) {
    int *array;  /* Array dinâmico, tamanho será definido pelo usuário */
    int NARRAY;
    int NBUCKET;
    int INTERVAL;

    if(iniValues(argc, argv, &NARRAY, &NBUCKET, &INTERVAL) == 1) return 1; /*Erro*/

    /* Aloca memória para o array */
    array = (int *)malloc(NARRAY * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    geraArray(array, NARRAY, argv);
    printf("Dados iniciais de tamanho %d: \n", NARRAY);
    /*print(array, NARRAY);*/
    printf("-------------\n");

    clock_t start;
    clock_t end;
    double time_spent;

    /* Ordenação com Bucket Sort usando Merge Sort */
    printf("    Bucket com Heap Sort:\n");
    start = clock(); 
    BucketSortHeap(array, NARRAY, NBUCKET, INTERVAL);
    end = clock(); 

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    /* Gera o array novamente para a próxima ordenação */
    geraArray(array, NARRAY, argv);
    printf("    -------------\n");

    printf("    Bucket com Merge Sort:\n");
    start = clock();  /* Marca o início */
    BucketSortMerge(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));
    /*print(array, NARRAY);*/


    /* Gera o array novamente para a próxima ordenação */
    geraArray(array, NARRAY, argv);
    printf("    -------------\n");

    /* Ordenação com Bucket Sort usando Quick Sort */
    printf("    Bucket com Quick Sort:\n");
    start = clock();  /* Marca o início */
    BucketSortQuick(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    /* Gera o array novamente para a próxima ordenação */
    geraArray(array, NARRAY, argv);
    printf("    -------------\n");

    /* Ordenação com Bucket Sort usando Quick Sort */
    printf("    Bucket com Insert Sort:\n");
    start = clock();  /* Marca o início */
    BucketSort(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("        Tempo de execução: %.6f segundos\n", time_spent);
    printf("        Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    /* Libera a memória alocada */
    free(array);

    return 0;
}
