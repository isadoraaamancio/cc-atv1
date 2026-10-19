#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char original[100];
    char chave[100];
} Palavra;

void gerar_chave(char *src, char *dst) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) dst[i] = tolower(src[i]);
    dst[len] = '\0';

    // Ordena as letras da palavra
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (dst[i] > dst[j]) {
                char tmp = dst[i]; dst[i] = dst[j]; dst[j] = tmp;
            }
        }
    }
}

int comparar_palavras(const void *a, const void *b) {
    Palavra *p1 = (Palavra*) a;
    Palavra *p2 = (Palavra*) b;
    return strcmp(p1->chave, p2->chave);
}

int main() {
    char *lista_bruta[] = {"amor", "Roma", "ramo", "mora", "carro", "orrac"};
    int n = 6;
    Palavra *palavras = (Palavra*) malloc(n * sizeof(Palavra));

    for (int i = 0; i < n; i++) {
        strcpy(palavras[i].original, lista_bruta[i]);
        gerar_chave(lista_bruta[i], palavras[i].chave);
    }

    qsort(palavras, n, sizeof(Palavra), comparar_palavras);

    printf("Grupos de Anagramas:\n");
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(palavras[i].chave, palavras[i - 1].chave) != 0) {
            printf("\nGrupo [%s]: %s ", palavras[i].chave, palavras[i].original);
        } else {
            printf("%s ", palavras[i].original);
        }
    }
    printf("\n");
    free(palavras);
    return 0;
}
