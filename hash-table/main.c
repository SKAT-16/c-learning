#include "hash.h"

#include <stdio.h>

int main(void) {
    HashTable *table = hash_table_init(100);
    hash_table_add("my name", table);
    hash_table_add("1my name1", table);
    hash_table_add("2my name2", table);
    hash_table_add("my name3", table);
    hash_table_add("my name4", table);
    hash_table_add("my name5", table);

    hash_table_print(table);

    printf("Look for data: %s result is: %d\n", "my name",
           hash_table_contains("my name", table));

    printf("Entry at %d is: %s\n", 75, hash_table_get(75, table)->data);
    hash_table_remove(75, table);
    printf("Entry at %d is: %s\n", 75, hash_table_get(75, table)->data);

    hash_table_free(table);

    return 0;
}