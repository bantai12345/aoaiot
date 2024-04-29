#include <stdio.h>
#include <string.h>
#define d 256
void search(char pat[], char txt[])
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]);
        t = (d * t + txt[i]);
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * (int)pow(d, M - 1)) + txt[i + M]);
        }
    }
}
int main()
{
    char txt[100], pat[100];
    printf("Enter the text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0';
    printf("Enter the pattern: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0'; 
    search(pat, txt);
    return 0;
}

