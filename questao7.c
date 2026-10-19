#include <stdio.h>
#include <stdlib.h>

int comparar_tempos(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void minimizar_tempo_medio(int n, int t[]) {
    // Ordena as tarefas por tempo de duracao crescente (SPT - Shortest Processing Time)
    qsort(t, n, sizeof(int), comparar_tempos);

    double soma_conclusao = 0;
    int tempo_acumulado = 0;

    printf("Ordem das tarefas: ");
    for (int i = 0; i < n; i++) {
        tempo_acumulado += t[i];
        soma_conclusao += tempo_acumulado;
        printf("%d ", t[i]);
    }
    printf("\nTempo medio de conclusao: %.2f\n", soma_conclusao / n);
}

int main() {
    int tarefas[] = {15, 3, 8, 2}; // Exemplo de duracoes
    minimizar_tempo_medio(4, tarefas);
    return 0;
}
