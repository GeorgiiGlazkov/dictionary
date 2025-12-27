#include "../include/trie.h"
#include "../common/include/utility.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ASCII_a 97

void freeTrie(TrieNode *root) {
    // printf("Begin\n");
    if (root == NULL) return;

    // printf("Before loop\n");

    for (int i = 0; i < MAX_CHILDREN; i++) {
        // printf("%d\n", i);
        freeTrie(root->children[i]);
       // printf("End of the loop\n");
    }
    
        free(root);

    // printf("Finished\n");
}


void addWord(TrieNode* root, char* word) {
    if (root == NULL) {
        freeTrieAndExit(root);
    }
    
    size_t len = strlen(word);

    TrieNode* nextTrieNode = NULL, *currTrieNode = root;

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

void deleteWord(TrieNode* root, char* word) {
    size_t len = strlen(word), lastUnsafeLetterIndex = 0;

    TrieNode* currTrieNode = root, *lastUnsafeToDeleteNode = root;
    int indexOfLetter = 0;
    while (indexOfLetter < len - 1) {
        if (currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])] == NULL) {
            return;
        }
        
       // printf("%d, %c\n", indexOfLetter, word[indexOfLetter]);

        

		if (!isOnlyChild(currTrieNode, word[indexOfLetter]) || currTrieNode->isTerminal) {
			lastUnsafeToDeleteNode = currTrieNode;
			lastUnsafeLetterIndex = indexOfLetter;
		}

		currTrieNode = currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])];
        indexOfLetter++;
    }
    
    if (currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])] == NULL) {
            return;
        }
    
    TrieNode* NextTrieNode = currTrieNode->children[getChildIndexFromLetter(word[indexOfLetter])];
    
    // printf("%d, %c\n", indexOfLetter, word[indexOfLetter]);
	
    if (!isChildless(NextTrieNode)) {
	    // printf("Последний - терминальный\n");
        NextTrieNode->isTerminal = false;
        // printf("OK\n");
	} else {
	    // printf("Удаляем дерево\n");
        freeTrie(lastUnsafeToDeleteNode->children[getChildIndexFromLetter(word[lastUnsafeLetterIndex])]);
        // printf("OK\n");
	}

    printf("Delete is fixed");
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