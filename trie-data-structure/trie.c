#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_index(char c) { return c - 'a'; }
static char get_char(int index) { return 'a' + index; }

int main(void) {
    char *words[] = {
        "cat",  "car", "cattle", "cart", "carton", "dog",
        "door", "do",  "apple",  "zoo",  "zebra",
    };
    int num_words = sizeof(words) / sizeof(words[0]);

    TrieNode *trie;
    trie_init(&trie);

    for (int i = 0; i < num_words; i++)
        trie_insert_word(trie, words[i]);

    printf("-----Trie Tree-----\n");
    trie_print(trie);
    printf("\n\n");

    printf("-----Autocomplete Search-----\n");

    // Search 1: Partially matches "cat" but fails on 's'
    printf("Search 1 (cat):\n");
    trie_autocomplete_search(trie, "cat");

    // Search 2: A perfectly valid search that should output [do] [dog] [door]
    printf("\nSearch 2 (do):\n");
    trie_autocomplete_search(trie, "do");
    printf("\n\n");

    trie_free(trie);

    return 0;
}

void trie_init(TrieNode **trie) {
    *trie = malloc(sizeof(TrieNode));
    if (*trie != NULL) {
        (*trie)->is_at_end = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            (*trie)->children[i] = NULL;
        }
    }
}

void trie_free(TrieNode *trie) {
    if (trie == NULL)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->children[i] != NULL)
            trie_free(trie->children[i]);
    }

    free(trie);
}

void trie_insert_word(TrieNode *trie, const char *word) {
    int index;
    for (const char *w = word; *w != '\0'; w++) {
        index = get_index(*w);

        if (trie->children[index] == NULL) {
            trie->children[index] = malloc(sizeof(TrieNode));
            trie->children[index]->is_at_end = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                trie->children[index]->children[i] = NULL;
        }
        trie = trie->children[index];
    }

    trie->is_at_end = true;
}

bool trie_search(TrieNode *trie, const char *word) {
    for (const char *w = word; *w != '\0'; w++) {
        int index = get_index(*w);
        if (trie->children[index] == NULL) {
            return false;
        }

        trie = trie->children[index];
    }

    return trie->is_at_end;
}

void trie_autocomplete_search(TrieNode *trie, const char *word) {
    static char buffer[100];
    static int level = 0;

    if (word != NULL && *word != '\0') {
        int index = get_index(*word);
        buffer[level++] = *word++;

        if (trie->children[index] != NULL)
            trie_autocomplete_search(trie->children[index], word);
        level--;

        return;
    }

    if (trie == NULL)
        return;

    if (trie->is_at_end) {
        buffer[level] = '\0';
        printf("[%s] ", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->children[i] != NULL) {
            buffer[level++] = get_char(i);
            trie_autocomplete_search(trie->children[i], NULL);
            level--;
        }
    }
}

void trie_print(TrieNode *trie) {
    static char buffer[100];
    static int level = 0;

    if (trie == NULL)
        return;

    if (trie->is_at_end) {
        buffer[level] = '\0';
        printf("[%s] ", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->children[i] != NULL) {
            buffer[level++] = get_char(i);
            trie_print(trie->children[i]);
            level--;
        }
    }
}
