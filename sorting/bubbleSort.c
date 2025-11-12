#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int *arr, int size) {
  bool swaped = false;  
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
	swaped = true;        
      }
    }
 if (swaped == false) {
    break;    
 }    
  }
}

int main() {

  int arr[] = {58,   -53, 92,  37,  -54, -82, -21, 73,  -57, 30,
               -100, 47,  -27, -60, -38, -46, -99, -44, -26, -7};
  int size = sizeof(arr) / sizeof(arr[0]);

   bubbleSort(arr, size);
  
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  
  return EXIT_SUCCESS;  
}  
