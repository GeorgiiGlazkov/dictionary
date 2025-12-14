#include <stdlib.h>
#include <stdbool.h>

#include "../include/trie.h"
#include "../include/utility.h"

#define ASCII_a 97

size_t getChildIndexFromLetter(char letter) {
    return atio(letter) - ASCII_a;
}


void freeTrieAndExit(TrieNode *root) {
    freeTrie(root);
    exit(1);
}


TrieNode* createTrieNode(TrieNode* root) {
    TrieNode* newTrieNode = malloc(sizeof(TrieNode));
    
    if (newTrieNode == NULL) {
        freeTrieAndExit(root);
    }

    newTrieNode->children = {NULL};
    newTrieNode->isTerminal = false;

    return newTrieNode;
}

bool isOnlyChild(TrieNode* node, char letter) {
    for (size_t i = 0; i < MAX_CHILDREN; i++) {
        if (node->children[i] != NULL && i != getChildIndexFromLetter(letter) return false;
    }

    return true;
}