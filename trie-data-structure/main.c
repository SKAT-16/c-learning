#include "trie.h"
#include <stdio.h>

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

    printf("Search 1 (cat):\n");
    trie_autocomplete_search(trie, "cat");

    printf("\nSearch 2 (do):\n");
    trie_autocomplete_search(trie, "do");
    printf("\n\n");

    trie_free(trie);

    return 0;
}