#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
struct User {
    char phone_number[12];
    char username[50];
    char address[100];
};
struct HashNode {
    struct User *user;
};
struct HashTable {
    struct HashNode *table[TABLE_SIZE];
};
unsigned long hash_function_1(char *phone_number) {
    unsigned long hash = 5381;
    int c;

    while ((c = *phone_number++)) {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % TABLE_SIZE;
}
void insert_linear_probe(struct HashTable *hash_table, struct User *user) {
    unsigned long index = hash_function_1(user->phone_number);
    unsigned long original_index = index;
    do {
        if (hash_table->table[index] == NULL) {
            hash_table->table[index] = (struct HashNode *)malloc(sizeof(struct HashNode));
            hash_table->table[index]->user = user;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != original_index);
    
    printf("��ϣ���������޷����롣\n");
}
float calculate_collision_rate(struct HashTable *hash_table) {
    int collision_count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table->table[i] != NULL) {
            collision_count++;
        }
    }
    return (float)collision_count / TABLE_SIZE;
}
float calculate_avg_search_length(struct HashTable *hash_table, struct User *users, int num_users) {
    int total_search_length = 0;
    for (int i = 0; i < num_users; i++) {
        unsigned long index = hash_function_1(users[i].phone_number);
        unsigned long original_index = index;
        int search_length = 1;
        while (hash_table->table[index] != NULL) {
            if (strcmp(hash_table->table[index]->user->phone_number, users[i].phone_number) == 0) {
                total_search_length += search_length;
                break;
            }
            index = (index + 1) % TABLE_SIZE;
            search_length++;
            if (index == original_index) {
                // Not found
                break;
            }
        }
    }
    return (float)total_search_length / num_users;
}
int main() {
    int num_users;
    printf("�������û�������");
    scanf("%d", &num_users);
    struct User *users_data = (struct User *)malloc(num_users * sizeof(struct User));
    for (int i = 0; i < num_users; i++) {
        printf("������� %d ���û��ĵ绰���룺", i + 1);
        scanf("%s", users_data[i].phone_number);
        printf("������� %d ���û����û�����", i + 1);
        scanf("%s", users_data[i].username);
        printf("������� %d ���û��ĵ�ַ��", i + 1);
        scanf("%s", users_data[i].address);
    }
    struct HashTable *hash_table = (struct HashTable *)malloc(sizeof(struct HashTable));
    memset(hash_table->table, 0, sizeof(hash_table->table));
    for (int i = 0; i < num_users; i++) {
        insert_linear_probe(hash_table, &users_data[i]);
    }
    float collision_rate = calculate_collision_rate(hash_table);
    float avg_search_length = calculate_avg_search_length(hash_table, users_data, num_users);
    printf("��ͻ��: %.2f\n", collision_rate);
    printf("ƽ�����ҳ���: %.2f\n", avg_search_length);
    free(users_data);
    return 0;
}

