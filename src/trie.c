#include "../include/trie.h"
#include "../include/utility.h"

#include <string.h>
#include <stdbool.h>


void freeTrie(TrieNode *root) {
    TrieNode* currTrieNode = root;
    
    for (int i = 0; i < MAX_CHILDREN; i++) {
        TrieNode* currChild = currTrieNode->children[i];
        if (currChild != NULL) freeTrie(currChild);
    }
    
    free(currTrieNode);
}


TrieNode* addWord(TrieNode* root, char* word) {
    if (root == NULL) {
        root = createTrieNode(root);
    }

    size_t len = strlen(word);

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
    size_t len = strlen(word);
    TrieNode* currTrieNode = root;

    for (size_t i = 0; i < len - 1; i++) {
        if (currTrieNode == NULL) return false;

        currTrieNode = currTrieNode->children[getChildIndexFromLetter(word[i]);
    }

    return currTrieNode->isTerminal;
}

void deleteWord(TrieNode* root, char* word) {
    size_t len = strlen(word);
    TrieNode* currTrieNode = root;
    TrieNode* lastUnsafeToDeleteNode = NULL;
	size_t lastUnsafeLetterIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if (currTrieNode->children[getChildIndexFromLetter(word[i])] == NULL) {
            printf("Deletion cancelled: no such word (%s)\n", word);
            return;
        }

		size_t children = 0;

		for (int i = 0; i < MAX_CHILDREN; i++) {
			if (currTrieNode->children[i] != NULL) children++;
		}

		if (children > 1 || (currTrieNode->isTerminal == 1 && i < len - 1)) {
			lastUnsafeToDeleteNode = currTrieNode;
			lastUnsafeLetterIndex = i;
		}

		currTrieNode = currTrieNode->children[getChildIndexFromLetter(word[i])];
    }

	size_t children = 0;

	for (int i = 0; i < MAX_CHILDREN; i++) {
		if (currTrieNode->children[i] != NULL) children++;
	}

	if (children > 0) {
	currTrieNode->isTerminal = false;
	}else {
	freeTrie(lastUnsafeToDeleteNode->children[getChildIndexFromLetter(word[i])];
	}





}

