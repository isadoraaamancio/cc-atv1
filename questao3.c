#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int a[], int na, int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < na) c[k++] = a[i++];
    while (j < nb) c[k++] = b[j++];
}

void mergesort(int n, int v[]) {
    if (n < 2) return;
    int meio = n / 2;
    mergesort(meio, v);
    mergesort(n - meio, v + meio);
    
    int *w = (int*) malloc(n * sizeof(int));
    intercala(v, meio, v + meio, n - meio, w);
    for (int i = 0; i < n; i++) v[i] = w[i];
    free(w);
}

void insertion_sort(int n, int v[]) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main() {
    int tamanhos[] = {1000, 10000, 100000};
    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        int *v1 = (int*) malloc(n * sizeof(int));
        int *v2 = (int*) malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            v1[i] = rand();
            v2[i] = v1[i];
        }

        clock_t inicio = clock();
        insertion_sort(n, v1);
        clock_t fim = clock();
        double tempo_insertion = (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        mergesort(n, v2);
        fim = clock();
        double tempo_merge = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("N = %d -> Insertion: %.4fs | Merge: %.4fs\n", n, tempo_insertion, tempo_merge);

        free(v1); free(v2);
    }
    return 0;
}
}
