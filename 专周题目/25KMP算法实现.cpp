#include <stdio.h>
#include <string.h>
void computeNext(const char *pattern, int *next, int length) {
    int i = 1;
    int j = 0;
    next[0] = 0;

    while (i < length) {
        if (pattern[i] == pattern[j]) {
            next[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }
}
int KMPSearch(const char *text, const char *pattern) {
    int lenText = strlen(text);
    int lenPattern = strlen(pattern);
    if (lenPattern == 0) return 0;
    int next[lenPattern];
    computeNext(pattern, next, lenPattern);
    int i = 0;
    int j = 0;
    while (i < lenText) {
        if (text[i] == pattern[j]) {
            if (j == lenPattern - 1) {
                return i - j;
            }
            i++;
            j++;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}
int main() {
    const char *text1 = "ababcabcacbab";
    const char *pattern1 = "abcac";
    const char *text2 = "hello world";
    const char *pattern2 = "world";
    int pos1 = KMPSearch(text1, pattern1);
    int pos2 = KMPSearch(text2, pattern2);
    printf("Pattern 1的位置: %d\n", pos1);
    printf("Pattern 2的位置: %d\n", pos2);
    return 0;
}

