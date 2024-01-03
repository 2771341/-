#include <stdio.h>
#include <stdbool.h>
#define N 8
int board[N];
bool is_safe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}
void print_solution() {
    for (int i = 0; i < N; ++i) {
        printf("(%d, %d) ", i, board[i]);
    }
    printf("\n");
}
void solve_n_queens(int row) {
    if (row == N) {
        print_solution();
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (is_safe(row, col)) {
            board[row] = col;
            solve_n_queens(row + 1);
        }
    }
}
int main() {
    solve_n_queens(0);
    return 0;
}

