#include <stdio.h>
#include <stdlib.h>

// Implementacao do Merge Sort necessaria para a Opcao A
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

// Opcao A: Ordenar tudo e devolver v[(n-1)/2]
int mediana_ordenando_tudo(int n, int v[]) {
    mergesort(n, v);
    int idx = (n - 1) / 2;
    return v[idx];
}

// Opcao B: Executar k passadas do Selection Sort
int mediana_selection_parcial(int n, int v[]) {
    int k = (n - 1) / 2 + 1;
    for (int i = 0; i < k; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) min_idx = j;
        }
        int temp = v[i];
        v[i] = v[min_idx];
        v[min_idx] = temp;
    }
    return v[k - 1];
}

int main() {
    // Exemplo testando a mediana do vetor do enunciado: [1, 299, 2]
    int v1[] = {1, 299, 2};
    int v2[] = {1, 299, 2};
    
    printf("Mediana (Opcao A - Ordenar tudo): %d\n", mediana_ordenando_tudo(3, v1));
    printf("Mediana (Opcao B - Selection Parcial): %d\n", mediana_selection_parcial(3, v2));
    
    return 0;
}
