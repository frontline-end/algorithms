#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void caesarCipher(char key, int offset);

int main() {

  char userInput[512];
  ssize_t bytes = read(STDIN_FILENO, userInput, sizeof(userInput));
  (bytes > 0) ? userInput[strcspn(userInput, "\n")] = 0 : perror("cant read");

  int offset = 10;
  
  for (int i = 0; i < bytes; i++) {
    if ((userInput[i] >= 'a' && userInput[i] <= 'z') ||
        (userInput[i] >= 'A' && userInput[i] <= 'Z')) {
      caesarCipher(userInput[i], offset);
    } else {
      printf("%c", userInput[i]);      
    }      
  }    
  
  return EXIT_SUCCESS;  
}

void caesarCipher(char key, int offset) {
  int cipher;
  int cipherValue;
  cipherValue = ((int)key - 97 + offset) % 26 + 97;
  cipher = (char)cipherValue;
  printf("%c", cipher);  
}  
