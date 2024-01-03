#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
void perform_dfs(int current_node, int N, int source);
int adj_matrix[MAX_NODES][MAX_NODES] = {0}; 
int durations[MAX_NODES] = {0};           
int visited[MAX_NODES] = {0};             
int max_duration = 0;                    
int path[MAX_NODES] = {0};
int path_index = 0;
void find_critical_paths(int N);
int main() {
    int N, M;
    printf("请输入节点总数N和箭头总数M：");
    scanf("%d %d", &N, &M);
    printf("请输入每条箭头的起始节点、终止节点和持续时间：\n");
    for (int i = 0; i < M; i++) {
        int start, end, duration;
        scanf("%d %d %d", &start, &end, &duration);
        adj_matrix[start][end] = 1;
        durations[end] = duration;
    }
    find_critical_paths(N);
    return 0;
}
void perform_dfs(int current_node, int N, int source) {
    visited[current_node] = 1;
    path[path_index++] = current_node;
    if (current_node == N) {
        int current_duration = 0;
        for (int i = 0; i < path_index - 1; i++) {
            current_duration += durations[path[i]];
        }
        if (current_duration > max_duration) {
            max_duration = current_duration;
        }
        for (int i = 0; i < path_index; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i <= N; i++) {
            if (adj_matrix[current_node][i] == 1 && !visited[i]) {
                perform_dfs(i, N, source);
            }
        }
    }
    visited[current_node] = 0;
    path_index--;
}
void find_critical_paths(int N) {
    for (int i = 0; i <= N; i++) {
        if (!visited[i]) {
            perform_dfs(i, N, i);
        }
    }
    printf("最长路径的持续时间：%d\n", max_duration);
}

