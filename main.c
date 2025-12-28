#include "tests/include/tests.h"
#include "common/include/utility.h"

#include <stdio.h>

int main(void) {
   #ifdef TEST
      printf("Running tests for findWord(): ");
      testFindWord();
      printf("OK\n");
      
      TrieNode *root = init();
      char word[MAX_WORD_LEN] = {0};
      drawTrie(root, word, 0); 
      freeTrie(root);
      
      printf("Running tests for addWord(): ");
      testAddWord();
      printf("OK\n");

      printf("Running tests for deleteWord(): ");
      testDeleteWord();
      printf("OK\n");
   #endif
   printf("hello, world\n"); 
}