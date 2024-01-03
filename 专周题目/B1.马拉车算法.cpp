#include <stdio.h>
#include <string.h>
int min(int a, int b) {
    return a < b ? a : b;
}
char* longestPalindrome(char *s) {
    int n = strlen(s);
    if (n == 0) {
        return "";
    }
    int N = 2 * n + 1;
    int L[N];
    L[0] = 0;
    L[1] = 1;
    int C = 1; 
    int R = 2; 
    int maxLen = 0; 
    int maxIndex = 0; 
    for (int i = 2; i < N; i++) {
        int i_mirror = 2 * C - i;
        L[i] = 0;
        if (R > i) {
            L[i] = min(R - i, L[i_mirror]);
        }
        while (i + 1 + L[i] < N && i - 1 - L[i] >= 0 &&
               ((i + 1 + L[i]) % 2 == 0 || s[(i + 1 + L[i]) / 2] == s[(i - 1 - L[i]) / 2])) {
            L[i]++;
        }
        if (i + L[i] > R) {
            C = i;
            R = i + L[i];
        }
        if (L[i] > maxLen) {
            maxLen = L[i];
            maxIndex = i;
        }
    }
    int start = (maxIndex - maxLen) / 2;
    s[start + maxLen] = '\0';
    return &s[start];
}
int main() {
    char sequence[] = "ATGCCTAGGTGAGTTAC";
    char *longestPalindromicSequence = longestPalindrome(sequence);
    printf("最长回文子序列: %s\n", longestPalindromicSequence);
    return 0;
}

