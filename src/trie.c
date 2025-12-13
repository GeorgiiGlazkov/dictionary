#include "../include/trie.h"
#include "../include/utility.h"

#include <string.h>
#include <stdbool.h>


void freeTrie(TrieNode *root) {
    TrieNode* currTrieNode = root;
    
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (currTrieNode->children[i] != NULL) 
        freeTrie(currTrieNode->children[i]);    
    }
    
    free(currTrieNode);
}


TrieNode* addWord(TrieNode* root, char* word) {
    if (root == NULL) {
        root = createTrieNode(root);
    }

    int len = strlen(word);

    TrieNode* nextTrieNode = NULL, *currTrieNode = root;

    for (int i = 0; i < len; i++) {
        char letter = word[i];

        nextTrieNode = currTrieNode->children[getChildIndexFromLetter(letter)];

        if (nextTrieNode == NULL) {
            nextTrieNode = createTrieNode(root);
        }

        currTrieNode = nextTrieNode;
        if (i == len - 1) currTrieNode->isTerminal = true;
    }   
}

bool findWord(TrieNode* root, char* word) {
    int len = sizeof(word);
    TrieNode* currTrieNode = root;
    for (int i = 0; i < len; i++) {
        char letter = word[i];
        currTrieNode = currTrieNode->children[getChildIndexFromLetter(letter)];
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