#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void BucketSort(int arr[], int n, int n_bucket, int interval) {
    int** buckets = (int**)malloc(n_bucket * sizeof(int*));
    int* bucket_sizes = (int*)malloc(n_bucket * sizeof(int));

    int i, j;

    for (i = 0; i < n_bucket; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        bucket_sizes[i] = 0;
    }

    /* Distribui os elementos nos baldes */
    for (i = 0; i < n; i++) {
        int pos = arr[i] / interval;
        if (pos >= n_bucket) {
            pos = n_bucket - 1;
        }
        buckets[pos][bucket_sizes[pos]] = arr[i];
        bucket_sizes[pos]++;
    }

    /* Imprime os baldes antes de ordenar */
    for (i = 0; i < n_bucket; i++) {
        printf("Bucket[%d]: ", i);
        for (j = 0; j < bucket_sizes[i]; j++) {
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }

    /* Ordena cada balde usando Merge Sort */
    for (i = 0; i < n_bucket; i++) {
        if (bucket_sizes[i] > 1) {
            merge_sort(buckets[i], 0, bucket_sizes[i] - 1);
        }
    }

    /* Imprime os baldes após ordenar */
    printf("-------------\n");
    printf("Buckets after sorting\n");
    for (i = 0; i < n_bucket; i++) {
        printf("Bucket[%d]: ", i);
        for (j = 0; j < bucket_sizes[i]; j++) {
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }

    /* Junta os baldes de volta no array original */
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

/* Implementação do Merge Sort */
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* Função de mesclagem para o Merge Sort */
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    int i, j, k;

    /* Copia os elementos para os arrays temporários L e R */
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    /* Mescla os arrays temporários de volta no array original */
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

    /* Copia os elementos restantes de L, se houver */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copia os elementos restantes de R, se houver */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void print(int ar[], int n) {
  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
    int *array;  /* Array dinâmico, tamanho será definido pelo usuário */
    int n = 0;   /* Contador de elementos lidos */
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
    int INTERVAL = (int)(NARRAY/NBUCKET)+1;

    /* Aloca memória para o array */
    array = (int *)malloc(NARRAY * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    /* Abre o arquivo para leitura */
    FILE *file = fopen(argv[2], "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", argv[2]);
        free(array);  /* Libera a memória em caso de erro */
        return 1;
    }

    /* Lê números do arquivo até o final ou até atingir o limite de NARRAY */
    while (fscanf(file, "%d", &array[n]) == 1 && n < NARRAY) {
        n++;
    }
    fclose(file);

    printf("Initial array: ");
    print(array, n);
    printf("-------------\n");

    BucketSort(array, n, NBUCKET, INTERVAL);
    
    printf("-------------\n");
    printf("Sorted array: ");
    print(array, n);

    /* Libera a memória alocada */
    free(array);

    return 0;
}