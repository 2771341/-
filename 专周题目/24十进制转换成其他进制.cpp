#include <stdio.h>
void decimalToBinary(int n) {
    printf("ʮ���� %d ת��Ϊ������: ", n);
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}
void decimalToOctal(int n) {
    printf("ʮ���� %d ת��Ϊ�˽���: %o\n", n, n);
}
void decimalToHexadecimal(int n) {
    printf("ʮ���� %d ת��Ϊʮ������: %X\n", n, n);
}
int main() {
    int num1 = 10;
    int num2 = 31;
    decimalToBinary(num1);
    decimalToOctal(num1);
    decimalToHexadecimal(num1);
    decimalToBinary(num2);
    decimalToOctal(num2);
    decimalToHexadecimal(num2);
    return 0;
}

