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


TrieNode* createTrieNode(void) {
    TrieNode* newTrieNode = malloc(sizeof(TrieNode));
    
    if (newTrieNode == NULL) {
        /* TODO:
        Implement another utility function that takes pointer to root,
        and exits from the program after freeing all the memory.
        
        Which in turn implies, that a freeTrie function has to be implemented as well.
        */

        // freeTrieAndExit(newTrieNode *root);
        return NULL;
    }

    newTrieNode->children = {NULL};
    newTrieNode->isTerminal = false;

    return newTrieNode;
}