#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort_trecho(int v[], int esq, int dir) {
    for (int i = esq + 1; i <= dir; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= esq && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void intercala_trecho(int v[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int *a = (int*) malloc(n1 * sizeof(int));
    int *b = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) a[i] = v[esq + i];
    for (int j = 0; j < n2; j++) b[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }
    while (i < n1) v[k++] = a[i++];
    while (j < n2) v[k++] = b[j++];

    free(a); free(b);
}

void mergesort_hibrido(int v[], int esq, int dir, int k) {
    if (dir - esq + 1 <= k) {
        insertion_sort_trecho(v, esq, dir);
        return;
    }
    int meio = esq + (dir - esq) / 2;
    mergesort_hibrido(v, esq, meio, k);
    mergesort_hibrido(v, meio + 1, dir, k);
    intercala_trecho(v, esq, meio, dir);
}

int main() {
    int n = 100000;
    int ks[] = {1, 4, 8, 16, 32, 64, 128};

    for (int i = 0; i < 7; i++) {
        int *v = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) v[j] = rand();

        clock_t inicio = clock();
        mergesort_hibrido(v, 0, n - 1, ks[i]);
        clock_t fim = clock();

        printf("k = %3d | Tempo: %.4fs\n", ks[i], (double)(fim - inicio) / CLOCKS_PER_SEC);
        free(v);
    }
    return 0;
}
