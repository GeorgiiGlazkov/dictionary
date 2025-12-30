#include "tests/include/tests.h"
#include "common/include/utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

   TrieNode* root = createTrieNode(NULL);

   char* commandsList = "add  delete  draw  find  free";
   while (1) {
      char command[10];
      scanf("%s", command);

      if (strcmp(command, "help") == 0) printf("%s\n", commandsList);
      
      if (strcmp(command, "add") == 0) {
         char word[45];
         scanf("%s", word);

         addWord(root, word);
      }

      if (strcmp(command, "delete") == 0) {
         char word[45];
         scanf("%s", word);

         deleteWord(root, word);
      }

      if (strcmp(command, "draw") == 0) {
         char word[MAX_WORD_LEN] = {0};
         drawTrie(root, word, 0);
      }

      if (strcmp(command, "find") == 0) {
         char word[45];
         scanf("%s", word);

         if (findWord(root, word) == true) {
            printf("YES\n");
         } else {
            printf("NO\n");
         }
      }

      if (strcmp(command, "free") == 0) {
         freeTrie(root);
         exit(1);
      }

      if (strstr(commandsList, command) == NULL) {
         printf("We don't have this command. You can use this commands: %s\n", commandsList);
      }
   }
}