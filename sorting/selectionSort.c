#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printAll(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));    
  }
}

void selectionSort(int *arr, int size) {
  int left = 0, right = size - 1;
  while (left <= right) {
    int minIndex = left;
    for (int i = left; i < size; i++) {
      if (arr[minIndex] > arr[i]) {
	minIndex = i;        
      }
    }
    swap(&arr[minIndex], &arr[left]);
    left++;    
  }    
}  
int main() {

  int arr[] = {-71, 2, -69, -93, -100, -22, -33, -46, 95, -90};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);
  puts("");
  
  selectionSort(arr, size);

  printAll(arr, size);
  
  return EXIT_SUCCESS;  
}  
