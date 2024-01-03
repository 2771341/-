#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct {
    int row;
    int col;
    int value;
} Term;
typedef struct {
    Term terms[MAX_TERMS];
    int rows;
    int cols;
    int num_terms;
} SparseMatrix;
void initSparseMatrix(SparseMatrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->num_terms = 0;
}
void addTerm(SparseMatrix *matrix, int row, int col, int value) {
    if (matrix->num_terms >= MAX_TERMS) {
        printf("稀疏矩阵已满，无法添加更多元素。\n");
        return;
    }
    matrix->terms[matrix->num_terms].row = row;
    matrix->terms[matrix->num_terms].col = col;
    matrix->terms[matrix->num_terms].value = value;
    matrix->num_terms++;
}
SparseMatrix addSparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        printf("矩阵维度不匹配，无法相加。\n");
        exit(EXIT_FAILURE);
    }
    SparseMatrix result;
    initSparseMatrix(&result, matrix1.rows, matrix1.cols);
    int i = 0, j = 0;
    while (i < matrix1.num_terms && j < matrix2.num_terms) {
        if (matrix1.terms[i].row < matrix2.terms[j].row || 
           (matrix1.terms[i].row == matrix2.terms[j].row && matrix1.terms[i].col < matrix2.terms[j].col)) {
            addTerm(&result, matrix1.terms[i].row, matrix1.terms[i].col, matrix1.terms[i].value);
            i++;
        } else if (matrix1.terms[i].row == matrix2.terms[j].row && matrix1.terms[i].col == matrix2.terms[j].col) {
            addTerm(&result, matrix1.terms[i].row, matrix1.terms[i].col, matrix1.terms[i].value + matrix2.terms[j].value);
            i++;
            j++;
        } else {
            addTerm(&result, matrix2.terms[j].row, matrix2.terms[j].col, matrix2.terms[j].value);
            j++;
        }
    }
    while (i < matrix1.num_terms) {
        addTerm(&result, matrix1.terms[i].row, matrix1.terms[i].col, matrix1.terms[i].value);
        i++;
    }
    while (j < matrix2.num_terms) {
        addTerm(&result, matrix2.terms[j].row, matrix2.terms[j].col, matrix2.terms[j].value);
        j++;
    }
    return result;
}
SparseMatrix multiplySparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2) {
    if (matrix1.cols != matrix2.rows) {
        printf("矩阵维度不匹配，无法相乘。\n");
        exit(EXIT_FAILURE);
    }
    SparseMatrix result;
    initSparseMatrix(&result, matrix1.rows, matrix2.cols);
    int resultValue[result.rows][result.cols];
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            resultValue[i][j] = 0;
        }
    }
    for (int i = 0; i < matrix1.num_terms; i++) {
        for (int j = 0; j < matrix2.num_terms; j++) {
            if (matrix1.terms[i].col == matrix2.terms[j].row) {
                resultValue[matrix1.terms[i].row][matrix2.terms[j].col] += matrix1.terms[i].value * matrix2.terms[j].value;
            }
        }
    }
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            if (resultValue[i][j] != 0) {
                addTerm(&result, i, j, resultValue[i][j]);
            }
        }
    }
    return result;
}
void printSparseMatrix(SparseMatrix matrix) {
    printf("稀疏矩阵的行数：%d\n", matrix.rows);
    printf("稀疏矩阵的列数：%d\n", matrix.cols);
    printf("稀疏矩阵的非零元素数量：%d\n", matrix.num_terms);
    printf("稀疏矩阵的三元组表示：\n");
    for (int i = 0; i < matrix.num_terms; i++) {
        printf("(%d, %d, %d)\n", matrix.terms[i].row, matrix.terms[i].col, matrix.terms[i].value);
    }
}
int main() {
    SparseMatrix matrix1;
    initSparseMatrix(&matrix1, 3, 3);
    addTerm(&matrix1, 0, 0, 1);
    addTerm(&matrix1, 0, 1, 2);
    addTerm(&matrix1, 1, 1, 3);
    addTerm(&matrix1, 1, 2, 4);
    addTerm(&matrix1, 2, 0, 5);
    addTerm(&matrix1, 2, 2, 6);
    SparseMatrix matrix2;
    initSparseMatrix(&matrix2, 3, 3);
    addTerm(&matrix2, 0, 0, 1);
    addTerm(&matrix2, 0, 1, 2);
    addTerm(&matrix2, 1, 1, 3);
    addTerm(&matrix2, 1, 2, 4);
    addTerm(&matrix2, 2, 0, 5);
    addTerm(&matrix2, 2, 2, 6);
    printf("测试用例1：\n");
    printf("矩阵相加结果：\n");
    SparseMatrix addResult = addSparseMatrices(matrix1, matrix2);
    printSparseMatrix(addResult);
    printf("\n矩阵相乘结果：\n");
    SparseMatrix multiplyResult = multiplySparseMatrices(matrix1, matrix2);
    printSparseMatrix(multiplyResult);
    SparseMatrix matrix3;
    initSparseMatrix(&matrix3, 4, 4);
    addTerm(&matrix3, 0, 0, 1);
    addTerm(&matrix3, 0, 3, 2);
    addTerm(&matrix3, 1, 2, 3);
    addTerm(&matrix3, 2, 1, 4);
    addTerm(&matrix3, 3, 0, 5);
    addTerm(&matrix3, 3, 3, 6);
    SparseMatrix matrix4;
    initSparseMatrix(&matrix4, 4, 4);
    addTerm(&matrix4, 0, 0, 1);
    addTerm(&matrix4, 0, 1, 2);
    addTerm(&matrix4, 1, 2, 3);
    addTerm(&matrix4, 2, 3, 4);
    addTerm(&matrix4, 3, 0, 5);
    addTerm(&matrix4, 3, 3, 6);
    printf("\n测试用例2：\n");
    printf("矩阵相加结果：\n");
    SparseMatrix addResult2 = addSparseMatrices(matrix3, matrix4);
    printSparseMatrix(addResult2);
    printf("\n矩阵相乘结果：\n");
    SparseMatrix multiplyResult2 = multiplySparseMatrices(matrix3, matrix4);
    printSparseMatrix(multiplyResult2);
    return 0;
}

