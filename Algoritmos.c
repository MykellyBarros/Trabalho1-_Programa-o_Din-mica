#include <stdio.h>
#include <string.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// recursivo — O(2^n)
int lcs_recursivo(char* X, char* Y, int m, int n, int* interactions) {
    (*interactions)++;

    if (m == 0 || n == 0) return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs_recursivo(X, Y, m - 1, n - 1, interactions);
    else
        return max(lcs_recursivo(X, Y, m, n - 1, interactions), lcs_recursivo(X, Y, m - 1, n, interactions));
}

// programação dinâmica — O(m * n)
int lcs_dinamico(char* X, char* Y, int m, int n, int* interactions) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            (*interactions)++;
            
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
    char X[100], Y[100];
    printf("primeira string: ");
    scanf("%s", X);
    printf("segunda string: ");
    scanf("%s", Y);

    int m = strlen(X), n = strlen(Y);
    int interactions_rec = 0, interactions_dp = 0;

    clock_t start, end;
    double cpu_time;

    // recursivo
    start = clock();
    int result_rec = lcs_recursivo(X, Y, m, n, &interactions_rec);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLCS recursivo: %d | tempo: %.6fs | interacoes: %d\n", result_rec, cpu_time, interactions_rec);

    // Dinâmico
    start = clock();
    int result_dp = lcs_dinamico(X, Y, m, n, &interactions_dp);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLCS dinamico: %d | tempo: %.6fs | interacoes: %d\n", result_dp, cpu_time, interactions_dp);

    return 0;
}
