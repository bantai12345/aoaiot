#include <stdio.h>
#include <string.h>

int LCS_table[20][20];

int lcsAlgo(char S1[], char S2[]) {
    int i, j, m, n;
    m = strlen(S1);
    n = strlen(S2);

    for (i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++)
        LCS_table[0][i] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j];
            } else {
                LCS_table[i][j] = LCS_table[i][j - 1];
            }
        }
    }

    int lcsLength = LCS_table[m][n];

    int index = lcsLength;
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';
    int k = m, l = n;
    while (k > 0 && l > 0) {
        if (S1[k - 1] == S2[l - 1]) {
            lcsAlgo[index - 1] = S1[k - 1];
            k--;
            l--;
            index--;
        } else if (LCS_table[k - 1][l] > LCS_table[k][l - 1]) {
            k--;
        } else {
            l--;
        }
    }

    printf("S1 : %s \nS2 : %s \n", S1, S2);
    printf("LCS: %s\n", lcsAlgo);
    printf("Length of LCS: %d\n", lcsLength);

    return lcsLength;
}

int main() {
    char S1[20], S2[20];
    printf("Enter the first string: ");
    scanf("%s", S1);
    printf("Enter the second string: ");
    scanf("%s", S2);
    lcsAlgo(S1, S2);
    return 0;
}

