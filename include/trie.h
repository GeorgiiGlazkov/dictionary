#include <stdbool.h>

#define MAX_CHILDREN 27

typedef struct TrieNode {
    struct trieNode *children[MAX_CHILDREN];
    bool isTerminal;
    bool isLetter;
} TrieNode;

void addWord(TrieNode* root, char* word);

