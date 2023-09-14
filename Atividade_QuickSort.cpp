#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparacoes = 0;
int trocas = 0;


	
void muda(char* arr[], int a, int b) {
    char* temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    trocas++;
}

int particao(char* arr[], int esq, int dir) {
    char* pivo = arr[dir];
    int i = (esq - 1);

    for (int j = esq; j <= dir - 1; j++) {
        comparacoes++;
        if (strcmp(arr[j], pivo) < 0) {
            i++;
            muda(arr, i, j);
        }
    }
    muda(arr, i + 1, dir);
    return (i + 1);
}
void quick(char* arr[], int esq, int dir) {
    if (esq < dir) {
        int pi = particao(arr, esq, dir);

        quick(arr, esq, pi - 1);
        quick(arr, pi + 1, dir);
    }
}


	//Aqui está a impressão no terminal, juntamente com o main!

int main() {
	
    char* arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

	printf("-------------------------------------------------------------\n");
    printf("-Antes de ordenar pelo quickSort, o vetor se encontrava assim:\n");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    quick(arr, 0, n - 1);

	printf("\n");
	printf("\n-------------------------------------------------------------\n");
    printf("-Depois de ser ordenado por quickSort, o vertor se encontra assim:\n");
    printf("-------------------------------------------------------------\n\n");
    
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
	printf("\n\n-------------------------------------------------------------");
    printf("\nForam feitas %d comparacoes e %d trocas\n", comparacoes,trocas);
	printf("-------------------------------------------------------------\n");
	
	
    // Aqui é calculado a palavra mediana!
    
    char* doMeio;
    if (n % 2 == 1) {
        doMeio = arr[n / 2];
    } else {
        doMeio = arr[n / 2 - 1];
    }
    printf("A mediana e: %s\n", doMeio);
    

    // Aqui é gerado um arquivo de saída
    
    FILE* quick_sort = fopen("Saída QuickSort.txt", "w");
    if (quick_sort == NULL) {
        printf("\nNao foi possivel abrir o arquivo de saida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(quick_sort, "%s\n", arr[i]);
    }

    fclose(quick_sort);

    return 0;
}

