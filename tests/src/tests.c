#include "../../include/trie.h"
#include "../../common/include/utility.h"
#include "../include/tests.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

TrieNode* init(void) {
    char* cat = "cat";
    char* catterpillar = "catterpillar";
    size_t lenCat = strlen(cat);
    size_t lenCatterpillar = strlen(catterpillar); 
    TrieNode* root = createTrieNode(NULL);
    TrieNode* currTrieNode = root;
  
    for (int i = 0; i < lenCatterpillar; i++) {
        currTrieNode->children[getChildIndexFromLetter(catterpillar[i])] = createTrieNode(root);
        currTrieNode = currTrieNode->children[getChildIndexFromLetter(catterpillar[i])];

        if (i == lenCat - 1 || i == lenCatterpillar - 1) currTrieNode->isTerminal = true;
    }
    
    return root;
}

void testFindWord(void) {
    TrieNode* root = NULL;
    assert(findWord(root, "cat") == false);
    assert(findWord(root, "") == false);

    root = init();
    assert(findWord(root, "cat") == true);
    assert(findWord(root, "cat") == true);
    assert(findWord(root, "cockroach") == false);
    
    freeTrie(root);
}

void testAddWord() {
    TrieNode* root = createTrieNode(NULL);
    addWord(root, "catterpillar");
    
    assert(findWord(root, "catterpillar") == true);
    assert(findWord(root, "cat") == false);

    addWord(root, "cat");
    assert(findWord(root, "cat") == true);

    freeTrie(root);
}

void testDeleteWord() {
    TrieNode* root = init();
    // deleteWord(root, "cockroach");
    // printf("\n");
    deleteWord(root, "cat");
    assert(findWord(root, "cat") == false);
    assert(findWord(root, "catterpillar") == true);

    deleteWord(root, "catterpillar");
    printf("1");
    assert(findWord(root, "catterpillar") == false);
    
    freeTrie(root);
    
    root = init();

    deleteWord(root, "catterpillar");
    assert(findWord(root, "catterpillar") == false);
    assert(findWord(root, "cat") == true);
    printf("Flag");
    freeTrie(root);

}

