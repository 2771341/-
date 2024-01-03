#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
bool validateStackSequence(const char *sequence, const char *characters) {
    int seqLen = strlen(sequence);
    int stack[MAX_SIZE];
    int top = -1;
    int charIndex = 0;
    for (int i = 0; i < seqLen; i++) {
        while (sequence[i] != characters[charIndex] && characters[charIndex] != '\0') {
            charIndex++;
        }
        if (characters[charIndex] == '\0') {
            return false;
        }
        stack[++top] = charIndex;
        while (top != -1 && stack[top] == charIndex) {
            top--;
            charIndex--;
        }
    }
    return top == -1;
}
int main() {
    const char *seq1 = "edcba";
    const char *seq2 = "abcde";
    const char *charset = "abcde";
    bool isValid1 = validateStackSequence(seq1, charset);
    bool isValid2 = validateStackSequence(seq2, charset);
    if (isValid1) {
        printf("%s 是合法的出栈序列\n", seq1);
    } else {
        printf("%s 不是合法的出栈序列\n", seq1);
    }
    if (isValid2) {
        printf("%s 是合法的出栈序列\n", seq2);
    } else {
        printf("%s 不是合法的出栈序列\n", seq2);
    }
    return 0;
}

