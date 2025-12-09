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

bool findWord(TrieNode* root, char* word) {
    int len = sizeof(word);
    TrieNode* currTrieNode = root;
    for (int i = 0; i < len; i++) {
        char symbol = word[i];
        currTrieNode = currTrieNode->children[atio(symbol) - 97];
        if (currTrieNode->isLetter == 0) return 0;
    }
    return currTrieNode->isTerminal;
}

void deleteWord(TrieNode* root, char* word) {
    if (findWord(root, word) == 0) {
        printf("There is no word %s", word);
        return;
    }
    int len = sizeof(word);
    TrieNode* currTrieNode = root;
    int lastTerminal = 1;
    for (int i = 0; i < len- 1; i++) {
        currTrieNode = currTrieNode->children[atio(word[i]) - 97];
        if (currTrieNode->isTerminal == 1) lastTerminal = i;
    }
    
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (currTrieNode->children[i] == 1) return; 
    }

    currTrieNode = root;

    for (int i = 0; i < lastTerminal; i++) {
        currTrieNode = currTrieNode->children[atio(word[i]) - 97];
    }

    TrieNode* TrieNodeToDelete = currTrieNode;

    while (currTrieNode->isTerminal != 1) {
        currTrieNode = currTrieNode->children[word[++lastTerminal]];
        free(TrieNodeToDelete);
    }
}