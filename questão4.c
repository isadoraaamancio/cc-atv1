#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Implementação completa do Merge Sort necessária para a questão
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

// Solução 1: Ordenando primeiro O(n log n)
void calcular_distintos_e_moda_ordenado(int n, int v[]) {
    mergesort(n, v);
    int distintos = 1;
    int moda = v[0], max_freq = 1;
    int freq_atual = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            distintos++;
            if (freq_atual > max_freq) {
                max_freq = freq_atual;
                moda = v[i - 1];
            }
            freq_atual = 1;
        } else {
            freq_atual++;
        }
    }
    if (freq_atual > max_freq) {
        max_freq = freq_atual;
        moda = v[n - 1];
    }
    printf("[Ordenado O(n log n)] Distintos: %d | Moda: %d (%d vezes)\n", distintos, moda, max_freq);
}

// Solução 2: Ingênua com 2 laços O(n^2)
void calcular_distintos_e_moda_ingenuo(int n, int v[]) {
    int distintos = 0;
    int moda = v[0], max_freq = 0;

    for (int i = 0; i < n; i++) {
        int ja_visto = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) { ja_visto = 1; break; }
        }
        if (!ja_visto) distintos++;

        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j]) freq++;
        }
        if (freq > max_freq) {
            max_freq = freq;
            moda = v[i];
        }
    }
    printf("[Ingenuo O(n^2)] Distintos: %d | Moda: %d (%d vezes)\n", distintos, moda, max_freq);
}

int main() {
    int n = 10000;
    int *v1 = (int*) malloc(n * sizeof(int));
    int *v2 = (int*) malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v1[i] = rand() % 1000;
        v2[i] = v1[i];
    }

    clock_t inicio = clock();
    calcular_distintos_e_moda_ordenado(n, v1);
    clock_t fim = clock();
    printf("Tempo Ordenado: %.4fs\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    calcular_distintos_e_moda_ingenuo(n, v2);
    fim = clock();
    printf("Tempo Ingenuo: %.4fs\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    free(v1); free(v2);
    return 0;
}
