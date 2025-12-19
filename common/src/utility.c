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

    for (int i = 0; i < MAX_CHILDREN;  i++) {
        newTrieNode->children[i] = NULL;
    }
    
    newTrieNode->isTerminal = false;

    return newTrieNode;
}

bool isOnlyChild(TrieNode* node, char letter) {
    for (size_t i = 0; i < MAX_CHILDREN; i++) {
        if (node->children[i] != NULL && i != getChildIndexFromLetter(letter)) return false;
    }

    return true;
}

bool isChildless(TrieNode* node) {
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (node->children[i] != NULL) return false;
    }

    return true;
}