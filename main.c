#include "tests/include/tests.h"
#include "common/include/utility.h"

#include <stdlib.h>
#include <stdio.h>

int main(void) {
   #ifdef TEST
      testAll();
   #endif

   TrieNode* root = createTrieNode(NULL);

   while (true) {
      char command[MAX_COMMAND_LEN];
      safeScanf(command, sizeof(command));

      processCommand(root, command);
   }
}