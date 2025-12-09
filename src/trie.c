#include "../include/trie.h"

void addWord(TrieNode* root, char* word) {
    int len = sizeof(word);
    TrieNode* currTrieNode = root;
    //Node* newNode = malloc(sizeof(Node));
    for (int i = 0; i < len - 1; i++) {
        char symbol = word[i];
        currTrieNode->children[atio(symbol) - 97] = malloc(sizeof(TrieNode));
        currTrieNode = currTrieNode->children[atio(symbol) - 97];
        currTrieNode->isLetter = word[i];
        currTrieNode->isTerminal = 0;
    }
    
    char symbol = word[len - 1];
    currTrieNode = currTrieNode->children[atio(symbol) - 97];
    currTrieNode->isLetter = word[len - 1];
    currTrieNode->isTerminal = 0;
}
