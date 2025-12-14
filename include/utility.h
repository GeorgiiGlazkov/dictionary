#ifndef UTILITY_H
#define UTILITY_H

#include "trie.h"

#include <stddef.h>

size_t getChildIndexFromLetter(char letter);

void freeTrieAndExit(TrieNode *root);

TrieNode* createTrieNode(TrieNode* root);

bool isOnlyChild(TrieNode* node, char letter);

#endif // UTILITY_H