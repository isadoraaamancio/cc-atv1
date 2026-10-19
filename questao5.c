#include <stdio.h>
#include <stdlib.h>

void mergesort(int n, int v[]);

int mediana_ordenando_tudo(int n, int v[]) {
    mergesort(n, v);
    int idx = (n - 1) / 2;
    return v[idx];
}

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
    int v1[] = {1, 299, 2}; // Exemplo do enunciado
    int v2[] = {1, 299, 2};
    printf("Mediana Opcao A: %d\n", mediana_ordenando_tudo(3, v1));
    printf("Mediana Opcao B: %d\n", mediana_selection_parcial(3, v2));
    return 0;
}
