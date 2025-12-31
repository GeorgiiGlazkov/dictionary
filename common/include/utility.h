#ifndef UTILITY_H
#define UTILITY_H

#include "../../include/trie.h"

#include <stddef.h>

#define MAX_COMMAND_LEN 10

size_t getChildIndexFromLetter(char letter);

void freeTrieAndExit(TrieNode *root);

TrieNode* createTrieNode(TrieNode* root);

bool isOnlyChild(TrieNode* node, char letter);

bool isChildless(TrieNode* node);

void processCommand(TrieNode* root, char *command);

void safeScanf(char *buff, size_t sizeOf);

#endif // UTILITY_H