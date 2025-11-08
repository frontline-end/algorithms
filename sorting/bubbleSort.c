#include <stdio.h>
#include <stdlib.h>

int main() {

  int arr[] = {58,   -53, 92,  37,  -54, -82, -21, 73,  -57, 30,
               -100, 47,  -27, -60, -38, -46, -99, -44, -26, -7};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);  
  return EXIT_SUCCESS;  
}  
