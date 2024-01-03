#include <stdio.h>
void findchange(int amount) {
    int coins[] = {25, 10, 5, 1};
    int coincount[4] = {0};
    printf("���� %d �֣����������", amount);
    for (int i = 0; i < 4; ++i) {
        coincount[i] = amount / coins[i];
        amount %= coins[i];
    }
    for (int i = 0; i < 4; ++i) {
        if (coincount[i] > 0) {
            printf("%d �� %d ��Ӳ�� ", coincount[i], coins[i]);
        }
    }
    printf("\n");
}
int main() {
    findchange(32); 
    findchange(50); 
    return 0;
}

