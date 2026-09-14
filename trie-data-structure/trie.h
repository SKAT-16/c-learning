#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct trie_node {
    struct trie_node *children[ALPHABET_SIZE];
    bool is_at_end;
} TrieNode;

void trie_init(TrieNode **trie);
void trie_free(TrieNode *trie);
void trie_insert_word(TrieNode *trie, const char *word);
bool trie_search(TrieNode *trie, const char *word);
void trie_autocomplete_search(TrieNode *trie, const char *word);
void trie_print(TrieNode *trie);