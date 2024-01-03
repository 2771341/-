#include <stdio.h>
#include <string.h>
#include <ctype.h>
void formatSentence(char *s) {
    int i = 0, j = 0;
    int len = strlen(s);
    while (isspace((unsigned char)s[i])) {
        i++;
    }
    while (i < len) {
        if (!isspace((unsigned char)s[i]) || (i > 0 && !isspace((unsigned char)s[i - 1]))) {
            s[j++] = s[i];
        }
        i++;
    }
    if (j > 0 && isspace((unsigned char)s[j - 1])) {
        j--;
    }
    s[j] = '\0';
}
int main() {
    char sentence1[] = "This is an example sentence.";
    char sentence2[] = " Hello world! ";
    printf("����: \"%s\"\n", sentence1);
    formatSentence(sentence1);
    printf("�������: \"%s\"\n\n", sentence1);
    printf("����: \"%s\"\n", sentence2);
    formatSentence(sentence2);
    printf("�������: \"%s\"\n", sentence2);
    return 0;
}

