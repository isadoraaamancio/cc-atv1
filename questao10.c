#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala_inplace(int v[], int esq, int meio, int dir) {
    int i = esq, j = meio + 1;
    while (i <= meio && j <= dir) {
        if (v[i] <= v[j]) {
            i++;
        } else {
            int val = v[j];
            int idx = j;
            while (idx != i) {
                v[idx] = v[idx - 1];
                idx--;
            }
            v[i] = val;
            i++; meio++; j++;
        }
    }
}

void mergesort_inplace(int v[], int esq, int dir) {
    if (esq >= dir) return;
    int meio = esq + (dir - esq) / 2;
    mergesort_inplace(v, esq, meio);
    mergesort_inplace(v, meio + 1, dir);
    intercala_inplace(v, esq, meio, dir);
}

int main() {
    int n = 10000;
    int *v = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) v[i] = rand();

    clock_t inicio = clock();
    mergesort_inplace(v, 0, n - 1);
    clock_t fim = clock();

    printf("Merge Sort In-Place (N=%d): %.4fs\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);
    free(v);
    return 0;
}
