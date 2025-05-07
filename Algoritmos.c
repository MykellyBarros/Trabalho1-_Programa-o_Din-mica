#include <stdio.h>
#include <string.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// recursivo — O(2^n)
int lcs_recursivo(char* X, char* Y, int m, int n, int* interactions, char* subsequence) {
    (*interactions)++;

    if (m == 0 || n == 0) {
        subsequence[0] = '\0';
        return 0;
    }
    
    if (X[m - 1] == Y[n - 1]) {
        int length = lcs_recursivo(X, Y, m - 1, n - 1, interactions, subsequence);
        subsequence[length] = X[m - 1];
        subsequence[length + 1] = '\0';
        return length + 1;
    } else {
        char sub1[100], sub2[100];
        int len1 = lcs_recursivo(X, Y, m, n - 1, interactions, sub1);
        int len2 = lcs_recursivo(X, Y, m - 1, n, interactions, sub2);
        
        if (len1 > len2) {
            strcpy(subsequence, sub1);
            return len1;
        } else {
            strcpy(subsequence, sub2);
            return len2;
        }
    }
}

// programação dinâmica — O(m * n)
int lcs_dinamico(char* X, char* Y, int m, int n, int* interactions, char* subsequence) {
    int L[m + 1][n + 1];
    
    // Preenchendo a matriz
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
    
    // Imprimindo a matriz para debug
    printf("\nMatriz de Programação Dinâmica:\n");
    printf("    ");
    for (int j_print = 0; j_print < n; j_print++) {
        printf("%c ", Y[j_print]);
    }
    printf("\n");
    
    for (int i_print = 0; i_print <= m; i_print++) {
        if (i_print > 0) printf("%c ", X[i_print-1]);
        else printf("  ");
        for (int j_print = 0; j_print <= n; j_print++) {
            printf("%d ", L[i_print][j_print]);
        }
        printf("\n");
    }
    
    // Reconstruindo a subsequência
    int current_lcs_length = L[m][n];
    subsequence[current_lcs_length] = '\0';
    
    int i_recon = m, j_recon = n;
    while (i_recon > 0 && j_recon > 0 && current_lcs_length > 0) {
        if (X[i_recon - 1] == Y[j_recon - 1]) {
            subsequence[current_lcs_length - 1] = X[i_recon - 1];
            i_recon--;
            j_recon--;
            current_lcs_length--;
        } else if (L[i_recon - 1][j_recon] > L[i_recon][j_recon - 1]) {
            i_recon--;
        } else {
            j_recon--;
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
    char subsequence_rec[100], subsequence_dp[100];

    clock_t start, end;
    double cpu_time;

    // recursivo
    start = clock();
    int result_rec = lcs_recursivo(X, Y, m, n, &interactions_rec, subsequence_rec);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLCS recursivo: %d | subsequencia: %s | tempo: %.6fs | interacoes: %d\n", 
           result_rec, subsequence_rec, cpu_time, interactions_rec);

    // Dinâmico
    start = clock();
    int result_dp = lcs_dinamico(X, Y, m, n, &interactions_dp, subsequence_dp);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLCS dinamico: %d | subsequencia: %s | tempo: %.6fs | interacoes: %d\n", 
           result_dp, subsequence_dp, cpu_time, interactions_dp);

    return 0;
}