#include "../../include/trie.h"
#include "../../common/include/utility.h"

#include <assert.h>

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

    TrieNode* root = init();
    assert(findWord(root, "cat") == true);
    assert(findWord(root, "cat") == true);
    assert(findWord(root, "cockroach") == false);
    
    freeTrie(root);
}

void testAddWord() {
    TrieNode* root = createTrieNode(NULL);

    addWord(root, "catterpillar");
    assert(findWord(root, "catterpillar") == true);
    assert(findWord(root, "cat" == false));

    addWord(root, "cat");
    assert(findWord(root, "cat") == true);

    freeTrie(root);
}