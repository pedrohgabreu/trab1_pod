/* Aqui faremos as comparacoes dos algoritmos de ordenacao, criando um relatorio com base nas medidas de cada variacao do algoritmo */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "bucket.h"

/* Função para gerar o array a partir do arquivo */
void geraArray(int *array, int NARRAY, char *argv[]) {
    int n = 0;   /* Contador de elementos lidos */
    /* Abre o arquivo para leitura */
    FILE *file = fopen(argv[2], "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", argv[2]);
        free(array);  /* Libera a memória em caso de erro */
        return;
    }

    /* Lê números do arquivo até o final ou até atingir o limite de NARRAY */
    while (fscanf(file, "%d", &array[n]) == 1 && n < NARRAY) {
        n++;
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    int *array;  /* Array dinâmico, tamanho será definido pelo usuário */
    int NARRAY;  /* Número máximo de elementos no array */

    /* Verifica se foram passados os argumentos corretos */
    if (argc != 3) {
        printf("Uso: %s <tamanho_do_array> <arquivo_com_numeros>\n", argv[0]);
        return 1;
    }

    /* Converte o primeiro argumento para o tamanho máximo do array */
    NARRAY = atoi(argv[1]);
    if (NARRAY <= 0) {
        printf("O tamanho do array deve ser um número positivo.\n");
        return 1;
    }

    int NBUCKET = (int)sqrt(NARRAY);
    int INTERVAL = (int)(NARRAY / NBUCKET) + 1;

    /* Aloca memória para o array */
    array = (int *)malloc(NARRAY * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    /* Gera o array e imprime os dados iniciais */
    geraArray(array, NARRAY, argv);
    /*printf("Dados iniciais para todas as ordenacoes: ");
    print(array, NARRAY);
    printf("-------------\n\n");*/

    /* Ordenação com Bucket Sort usando Merge Sort */
    printf("    Bucket com Insert Sort:\n");
    clock_t start = clock();  /* Marca o início */
    BucketSort(array, NARRAY, NBUCKET, INTERVAL);
    clock_t end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", time_spent);
    printf("Ordenado = %d\n", VerificaOrdenado(array, NARRAY));

    /* Gera o array novamente para a próxima ordenação */
    geraArray(array, NARRAY, argv);
    printf("-------------\n\n");

    printf("    Bucket com Merge Sort:\n");
    start = clock();  /* Marca o início */
    BucketSortMerge(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", time_spent);
    printf("Ordenado = %d\n", VerificaOrdenado(array, NARRAY));


    /* Gera o array novamente para a próxima ordenação */
    geraArray(array, NARRAY, argv);
    printf("-------------\n\n");

    /* Ordenação com Bucket Sort usando Quick Sort */
    printf("    Bucket com Quick Sort:\n");
    start = clock();  /* Marca o início */
    BucketSortQuick(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", time_spent);
    printf("Ordenado = %d\n", VerificaOrdenado(array, NARRAY));



    /* Gera o array novamente para a próxima ordenação */
    geraArray(array, NARRAY, argv);
    printf("-------------\n\n");

    /* Ordenação com Bucket Sort usando Quick Sort */
    printf("    Bucket com Heap Sort:\n");
    start = clock();  /* Marca o início */
    BucketSortHeap(array, NARRAY, NBUCKET, INTERVAL);
    end = clock();  /* Marca o final */

    /* Calcula e exibe o tempo de execução */
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", time_spent);
    printf("Ordenado = %d\n", VerificaOrdenado(array, NARRAY));


    

    /* Libera a memória alocada */
    free(array);

    return 0;
}
