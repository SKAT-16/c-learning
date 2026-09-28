#ifndef HASH_TABLE_HASH_H
#define HASH_TABLE_HASH_H

#include <stdbool.h>

typedef struct {
    int key;
    char *data;
    bool in_use;
    bool deleted;
} Entry;

typedef struct {
    Entry *entries;
    int count;
    int capacity;
} HashTable;

long int hash_table_hash_data(const char *data);
int hash_table_get_key(long int hash, int capacity);

HashTable *hash_table_init(int capacity);
void hash_table_free(HashTable *table);

void hash_table_add(char *data, HashTable *table);
Entry *hash_table_get(int key, HashTable *table);
bool hash_table_contains(char *data, HashTable *table);
void hash_table_remove(int key, HashTable *table);

void hash_table_print(HashTable *table);

#endif