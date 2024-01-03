#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
struct User {
    char phone_number[12];
    char username[50];
    char address[100];
};
struct ListNode {
    struct User *user;
    struct ListNode *next;
};
struct HashTable {
    struct ListNode *table[TABLE_SIZE];
};
unsigned long hash_function_1(char *phone_number) {
    unsigned long hash = 5381;
    int c;
    while ((c = *phone_number++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}
void insert_chaining(struct HashTable *hash_table, struct User *user) {
    unsigned long index = hash_function_1(user->phone_number);
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->user = user;
    new_node->next = NULL;
    if (hash_table->table[index] == NULL) {
        hash_table->table[index] = new_node;
    } else {
        struct ListNode *current = hash_table->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
float calculate_collision_rate(struct HashTable *hash_table) {
    int collision_count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table->table[i] != NULL && hash_table->table[i]->next != NULL) {
            collision_count++;
        }
    }
    return (float)collision_count / TABLE_SIZE;
}
float calculate_avg_search_length(struct HashTable *hash_table, struct User *users, int num_users) {
    int total_search_length = 0;
    for (int i = 0; i < num_users; i++) {
        unsigned long index = hash_function_1(users[i].phone_number);
        if (hash_table->table[index] != NULL) {
            struct ListNode *current = hash_table->table[index];
            int search_length = 1;
            while (current != NULL) {
                if (strcmp(current->user->phone_number, users[i].phone_number) == 0) {
                    total_search_length += search_length;
                    break;
                }
                current = current->next;
                search_length++;
            }
        }
    }

    return (float)total_search_length / num_users;
}

int main() {
    int num_users;
    printf("请输入用户数量：");
    scanf("%d", &num_users);

    struct User *users_data = (struct User *)malloc(num_users * sizeof(struct User));
    for (int i = 0; i < num_users; i++) {
        printf("请输入第 %d 个用户的电话号码：", i + 1);
        scanf("%s", users_data[i].phone_number);
        printf("请输入第 %d 个用户的用户名：", i + 1);
        scanf("%s", users_data[i].username);
        printf("请输入第 %d 个用户的地址：", i + 1);
        scanf("%s", users_data[i].address);
    }

    struct HashTable *hash_table = (struct HashTable *)malloc(sizeof(struct HashTable));
    memset(hash_table->table, 0, sizeof(hash_table->table));

    for (int i = 0; i < num_users; i++) {
        insert_chaining(hash_table, &users_data[i]);
    }

    float collision_rate = calculate_collision_rate(hash_table);
    float avg_search_length = calculate_avg_search_length(hash_table, users_data, num_users);

    printf("冲突率: %.2f\n", collision_rate);
    printf("平均查找长度: %.2f\n", avg_search_length);

    free(users_data);
    return 0;
}

