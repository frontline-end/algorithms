#include <stdio.h>
#include <stdlib.h>

int main() {

  int arr[] = {1, 1, 2, 2, 3, 3, 3, 3, 3};
  int size = sizeof(arr) / sizeof(arr[0]);

  int left = 0;
  int longest = 1;

  for (int right = 1; right < size; right++) {
    if (arr[right] == arr[right - 1]) {
      int windowSize = right - left + 1;
      if (windowSize > longest) {longest = windowSize;}
    } else {
      left = right;
    }
  }

  printf("%d ", longest);
  
  return EXIT_SUCCESS;  
}  
