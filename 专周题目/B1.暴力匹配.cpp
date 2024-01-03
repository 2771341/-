#include <stdio.h>
#include <string.h>
int isPalindrome(char *s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return 0;
        }
    }
    return 1;
}
char* longestPalindrome(char *s) {
    int n = strlen(s);
    if (n == 0) {
        return "";
    }
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }
    s[start + maxLen] = '\0';
    return &s[start];
}
int main() {
    char sequence[] = "ATGCCTAGGTGAGTTAC";
    char *longestPalindromicSequence = longestPalindrome(sequence);
    printf("最长回文子序列: %s\n", longestPalindromicSequence);
    return 0;
}

