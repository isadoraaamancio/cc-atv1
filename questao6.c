#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ini;
    int fim;
} Intervalo;

int comparar_intervalos(const void *a, const void *b) {
    Intervalo *i1 = (Intervalo*) a;
    Intervalo *i2 = (Intervalo*) b;
    return i1->ini - i2->ini;
}

void unificar_reunioes(int n, Intervalo inter[]) {
    qsort(inter, n, sizeof(Intervalo), comparar_intervalos);

    int ini_atual = inter[0].ini;
    int fim_atual = inter[0].fim;
    int tempo_total = 0;

    printf("Intervalos unificados: ");
    for (int i = 1; i < n; i++) {
        if (inter[i].ini <= fim_atual) {
            if (inter[i].fim > fim_atual) fim_atual = inter[i].fim;
        } else {
            printf("[%d, %d] ", ini_atual, fim_atual);
            tempo_total += (fim_atual - ini_atual);
            ini_atual = inter[i].ini;
            fim_atual = inter[i].fim;
        }
    }
    printf("[%d, %d]\n", ini_atual, fim_atual);
    tempo_total += (fim_atual - ini_atual);

    printf("Tempo total em reuniao: %d minutos (%.2f horas)\n", tempo_total, tempo_total / 60.0);
}

int main() {
    // Exemplo: [9,12] [11,13] [15,16]
    Intervalo lista[] = {{9, 12}, {11, 13}, {15, 16}};
    unificar_reunioes(3, lista);
    return 0;
}
