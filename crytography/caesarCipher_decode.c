#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void caesarCipher_decode(char key, int offset);

int main() {

  char userInput[512];
  ssize_t bytes = read(STDIN_FILENO, userInput, sizeof(userInput));
  int offset = 10;
  
  (bytes > 0) ? userInput[strcspn(userInput, "\n")] = 0 : perror("cant read");

  for (int i = 0; i < bytes; i++) {
    if ((userInput[i] >= 'a' && userInput[i] <= 'z') ||
        (userInput[i] >= 'A' && userInput[i] <= 'Z')) {
      caesarCipher_decode(userInput[i], offset);
    } else {
      printf("%c", userInput[i]);      
    }      
  }    
  
  return EXIT_SUCCESS;
}

void caesarCipher_decode(char key, int offset) {
  int cipherValue;
  cipherValue = (((int)key - 'a' - offset + 26) % 26) + 'a';
  printf("%c", (char)cipherValue);
}  
