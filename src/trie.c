#include "../include/trie.h"
#include "../common/include/utility.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ASCII_a 97

void freeTrie(TrieNode *root) {
    TrieNode* currTrieNode = root;
    
    for (int i = 0; i < MAX_CHILDREN; i++) {
        TrieNode* currChild = currTrieNode->children[i];
        if (currChild != NULL) freeTrie(currChild);
    }
    
    free(currTrieNode);
}


void addWord(TrieNode* root, char* word) {
    if (root == NULL) {
        freeTrieAndExit(root);
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
    if (root == NULL) return false;

    size_t len = strlen(word);
    TrieNode* currTrieNode = root;

    for (size_t i = 0; i < len; i++) {
        printf("test\n");
        if (currTrieNode == NULL) {
            printf("not found\n");
            return false;
        }
        currTrieNode = currTrieNode->children[getChildIndexFromLetter(word[i])];
    }
    
    return currTrieNode->isTerminal;
}

void deleteWord(TrieNode* root, char* word) {
    size_t len = strlen(word);
    TrieNode* currTrieNode = root;
    TrieNode* lastUnsafeToDeleteNode = NULL;
	size_t lastUnsafeLetterIndex = 0;
    for (int i = 0; i < len - 1; i++)
    {
        TrieNode* nextTrieNode = currTrieNode->children[getChildIndexFromLetter(word[i])];

        if (nextTrieNode == NULL) {
            printf("Deletion cancelled: no such word (%s)\n", word);
            return;
        }

		if (!isOnlyChild(root, word[i]) || (currTrieNode->isTerminal && i < len - 1)) {
			lastUnsafeToDeleteNode = currTrieNode;
			lastUnsafeLetterIndex = i;
		}

		currTrieNode = nextTrieNode;
    }


	if (!isChildless(currTrieNode)) {
	    currTrieNode->isTerminal = false;
	} else {
	    freeTrie(lastUnsafeToDeleteNode->children[getChildIndexFromLetter(word[lastUnsafeLetterIndex])]);
	}
}

void drawTrie(TrieNode* root, char word[]) {
    TrieNode* currTrieNode = root;
    
    while(!isChildless(currTrieNode)) {
        for (int i = 0; i < MAX_CHILDREN; i++) {
            TrieNode* child = currTrieNode->children[i];
            
            if (child != NULL) {
                if (child->isTerminal == 1) {
                    printf("%s\n", word);
                } else {
                    size_t len = strlen(word);
                    word[len] = i + ASCII_a;
                    word[len + 1] = '\0';
                    drawTrie(currTrieNode, word);
                } 
            }
        }
    }
} 