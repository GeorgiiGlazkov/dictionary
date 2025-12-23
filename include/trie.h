#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_CHILDREN 27

typedef struct TrieNode {
    struct TrieNode *children[MAX_CHILDREN];
    bool isTerminal;
} TrieNode;

void freeTrie(TrieNode *root);

void addWord(TrieNode* root, char* word);

bool findWord(TrieNode* root, char* word);

void deleteWord(TrieNode* root, char* word);

void drawTrie(TrieNode* root, char word[]);

#endif // TRIE_H