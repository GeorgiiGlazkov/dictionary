#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../../include/trie.h"
#include "../include/utility.h"

#define ASCII_a 97

size_t getChildIndexFromLetter(char letter) {
    return letter - ASCII_a;
}

void freeTrieAndExit(TrieNode *root) {
    freeTrie(root);
    exit(1);
}

TrieNode* createTrieNode(TrieNode* root) {
    TrieNode* newTrieNode = malloc(sizeof(TrieNode));
    
    if (newTrieNode == NULL) {
        freeTrieAndExit(root);
    }

    for (int i = 0; i < MAX_CHILDREN;  i++) {
        newTrieNode->children[i] = NULL;
    }
    
    newTrieNode->isTerminal = false;

    return newTrieNode;
}

bool isOnlyChild(TrieNode* node, char letter) {
    for (size_t i = 0; i < MAX_CHILDREN; i++) {
        if (node->children[i] != NULL && i != getChildIndexFromLetter(letter)) return false;
    }

    return true;
}

bool isChildless(TrieNode* node) {
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (node->children[i] != NULL) return false;
    }

    return true;
}

void processCommand(TrieNode* root, char *command) {
    char* helpMessage = "Commands are separated from their arguments by a newline character.\n\n"
    "add <word> -- adds new word to the dictionary\n"
    "delete <word> -- deletes existing word from the dictionary\n"
    "draw -- prints all the words from the dictionary\n"
    "find -- checks if the word exists in the dictionary\n"
    "help -- see this help message\n"
    "exit -- exits the program\n";

    char* commandsList = "add delete draw find help exit";
    
    if (strcmp(command, "help") == 0) {
        printf("%s", helpMessage);
    }

    if (strcmp(command, "add") == 0) {
        char word[MAX_WORD_LEN];
        safeScanf(word, sizeof(word));

        addWord(root, word);
        printf("Added word: %s\n", word);
    }

    if (strcmp(command, "delete") == 0) {
        char word[MAX_WORD_LEN];
        safeScanf(word, sizeof(word));

        if (deleteWord(root, word)) {
            printf("Deleted word: %s\n", word);
        } else {
            printf("There was no such word: %s\n", word);
        }
    }

    if (strcmp(command, "draw") == 0) {
        char word[MAX_WORD_LEN] = {0};
        drawTrie(root, word, 0);
    }

    if (strcmp(command, "find") == 0) {
        char word[MAX_WORD_LEN];
        safeScanf(word, sizeof(word));

        if (findWord(root, word) == true) {
            printf("Word %s is in the dictionary\n", word);
        } else {
            printf("Word %s is not in the dictionary\n", word);
        }
    }

    if (strcmp(command, "exit") == 0) {
        freeTrieAndExit(root);
    }

    if (strstr(commandsList, command) == NULL) {
        printf("Unknown command. Use help to see list of available ones.\n");
    }    
}

void safeScanf(char *buff, size_t sizeOf) {
    fgets(buff, sizeOf, stdin);

    if (strstr(buff, "\n") != NULL) {
        buff[strcspn(buff, "\n")] = '\0';
    }
}