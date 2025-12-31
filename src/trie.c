#include "../include/trie.h"
#include "../common/include/utility.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ASCII_a 97

void freeTrie(TrieNode *root) {
    if (root == NULL) return;

    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (root->children[i] != NULL) freeTrie(root->children[i]);
    }
    
    free(root);
}


void addWord(TrieNode* root, char* word) {
    if (root == NULL) {
        freeTrieAndExit(root);
    }
    
    size_t len = strlen(word);

    if (len >= MAX_WORD_LEN) {
        printf("Only words under %d characters are supported. Addition cancelled\n", MAX_WORD_LEN);
        return;
    }

    TrieNode* currTrieNode = root;

    for (int i = 0; i < len; i++) {
        size_t index = getChildIndexFromLetter(word[i]);

        if (currTrieNode->children[index] == NULL) {
            currTrieNode->children[index] = createTrieNode(root);
        }

        currTrieNode = currTrieNode->children[index];
        if (i == len - 1) currTrieNode->isTerminal = true;
    }
}

bool findWord(TrieNode* root, char* word) {
    if (root == NULL) return false;

    size_t len = strlen(word);
    TrieNode* currTrieNode = root;

    for (size_t i = 0; i < len; i++) {
        if (currTrieNode == NULL) {
            return false;
        }

        currTrieNode = currTrieNode->children[getChildIndexFromLetter(word[i])];
    }
    
    return currTrieNode->isTerminal;
}

bool deleteWord(TrieNode* root, char* word) {
    size_t len = strlen(word), lastUnsafeLetterIndex = 0;

    TrieNode* currTrieNode = root, *lastUnsafeToDeleteNode = root;
    int indexOfLetter = 0;

    for (; indexOfLetter < len - 1; indexOfLetter++) {
        if (currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])] == NULL) {
            return false;
        }
        
		if (!isOnlyChild(currTrieNode, word[indexOfLetter]) || currTrieNode->isTerminal) {
			lastUnsafeToDeleteNode = currTrieNode;
			lastUnsafeLetterIndex = indexOfLetter;
		}

		currTrieNode = currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])];
    }
    
    TrieNode* nextTrieNode = currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])];

    if (nextTrieNode == NULL) {
        return false;
    }
    
    if (isChildless(nextTrieNode)) {
        size_t childIndex = getChildIndexFromLetter(word[lastUnsafeLetterIndex]);

        freeTrie(lastUnsafeToDeleteNode->children[childIndex]);
        lastUnsafeToDeleteNode->children[childIndex] = NULL;
	} else {
        nextTrieNode->isTerminal = false;
	}

    return true;
}

void drawTrie(TrieNode* root, char word[MAX_WORD_LEN], size_t wordLen) {
    for (unsigned char i = 0; i < MAX_CHILDREN; i++) {
        TrieNode* child = root->children[i];

        if (child == NULL) {
            continue;
        }
        
        word[wordLen] = i + ASCII_a;
        word[wordLen + 1] = '\0';
        
        if (child->isTerminal) {
            printf("%s\n", word);
            if (isChildless(child)) continue;
        }

        drawTrie(child, word, wordLen + 1);
    }
}
