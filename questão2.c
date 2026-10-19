#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort_al(int n, int v[]) {
    for (int j = 1; j < n; ++j) {
        int x = v[j];
        int i;
        for (i = j - 1; i >= 0; --i) {
            if (rand() > RAND_MAX / 2)
                v[i + 1] = v[i];
            else 
                break;
        }
        v[i + 1] = x;
    }
}

int obter_id_permutacao(int v[]) {
    if (v[0]==1 && v[1]==2 && v[2]==3) return 0;
    if (v[0]==1 && v[1]==3 && v[2]==2) return 1;
    if (v[0]==2 && v[1]==1 && v[2]==3) return 2;
    if (v[0]==2 && v[1]==3 && v[2]==1) return 3;
    if (v[0]==3 && v[1]==1 && v[2]==2) return 4;
    if (v[0]==3 && v[1]==2 && v[2]==1) return 5;
    return -1;
}

int main() {
    srand(time(NULL));
    int contagem[6] = {0};
    int total_execucoes = 600000;

    for (int k = 0; k < total_execucoes; k++) {
        int v[3] = {1, 2, 3};
        insertionsort_al(3, v);
        int id = obter_id_permutacao(v);
        if (id != -1) contagem[id]++;
    }

    printf("Frequencia das permutacoes apos %d execucoes:\n", total_execucoes);
    printf("(1,2,3): %d\n", contagem[0]);
    printf("(1,3,2): %d\n", contagem[1]);
    printf("(2,1,3): %d\n", contagem[2]);
    printf("(2,3,1): %d\n", contagem[3]);
    printf("(3,1,2): %d\n", contagem[4]);
    printf("(3,2,1): %d\n", contagem[5]);

    return 0;
}
