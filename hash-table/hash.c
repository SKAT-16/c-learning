#include "hash.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fputs("\n", stderr);
    exit(EXIT_FAILURE); // Terminate so the program doesn't crash downstream
}

static bool is_full(HashTable *table) {
    return table->capacity == table->count;
}

static bool is_empty(HashTable *table) { 
    return table->count == 0; 
}

long int hash_table_hash_data(const char *data) {
    unsigned long int hash_key = 2166136261U; // Use unsigned to prevent bad sign bits
    for (int i = 0; data[i] != '\0'; i++) {
        hash_key = hash_key ^ (unsigned char)data[i];
        hash_key = hash_key * 16777619;
    }
    return (long int)hash_key;
}

int hash_table_get_key(long int hash, int capacity) {
    int key = (int)(hash % capacity);
    if (key < 0) key += capacity; // Safeguard against negative remainders
    return key;
}

HashTable *hash_table_init(int capacity) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (!table) error("Out of memory");

    table->entries = (Entry *)malloc(sizeof(Entry) * capacity);
    if (!table->entries) error("Out of memory");

    for (int i = 0; i < capacity; i++) {
        table->entries[i] = (Entry){.data = NULL, .deleted = false, .in_use = false};
    }
    table->count = 0;
    table->capacity = capacity;

    return table;
}

void hash_table_free(HashTable *table) {
    if (!table) return;
    free(table->entries);
    free(table);
}

void hash_table_add(char *data, HashTable *table) {
    if (is_full(table))
        error("Error adding data: Table capacity full");

    int key = hash_table_get_key(hash_table_hash_data(data), table->capacity);
    
    // Linear probing loop using a single clean loop statement
    for (int i = 0; i < table->capacity; i++) {
        int idx = (key + i) % table->capacity;
        
        // We can overwrite a slot if it's not in use (never used, or deleted)
        if (!table->entries[idx].in_use) {
            table->entries[idx] = (Entry){.data = data, .deleted = false, .in_use = true};
            table->count++;
            return;
        }
    }
    error("Error adding data: Unknown error");
}

void hash_table_print(HashTable *table) {
    if (is_empty(table)) {
        printf("Table Empty\n");
        return;
    }

    printf("---------Table Data---------\n");
    for (int i = 0; i < table->capacity; i++) {
        if (table->entries[i].in_use)
            printf("%3d\t%.*s\n", i, 20, table->entries[i].data);
    }
    printf("---------End of Table---------\n");
}

Entry *hash_table_get(int key, HashTable *table) {
    if (key < 0 || key >= table->capacity || is_empty(table))
        return NULL;

    return &table->entries[key];
}

bool hash_table_contains(char *data, HashTable *table) {
    if (is_empty(table))
        return false;

    int key = hash_table_get_key(hash_table_hash_data(data), table->capacity);

    for (int i = 0; i < table->capacity; i++) {
        int idx = (key + i) % table->capacity;
        
        // If we hit an empty slot that was NEVER used, the item isn't in the table
        if (!table->entries[idx].in_use && !table->entries[idx].deleted) {
            return false;
        }
        
        // Check if the slot matches our string
        if (table->entries[idx].in_use && strcmp(table->entries[idx].data, data) == 0) {
            return true;
        }
    }

    return false;
}

void hash_table_remove(int key, HashTable *table) {
    if (key < 0 || key >= table->capacity || is_empty(table))
        return;

    if (table->entries[key].in_use) {
        table->entries[key].deleted = true; // Essential tombstone flag
        table->entries[key].in_use = false;
        table->entries[key].data = NULL;
        table->count--;
    }
}
