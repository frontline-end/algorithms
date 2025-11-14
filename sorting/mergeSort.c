#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int right, int merge);
void printArray(int *arr, int size);

int main() {

  int arr[] = {32, 14, 18, 62, 44, 66, 64, 63, 46, 87};
  int size = sizeof(arr) / sizeof(arr[0]);

  int left = 0;
  int right = size - 1;
  
  printArray(arr, size);

  puts("");
  
  mergeSort(arr, left, right);

  printArray(arr, size);
  
  return EXIT_SUCCESS;
}

void mergeSort(int *arr, int left, int right) {
  if(left < right){
    int m = left + (right - left) / 2;

    mergeSort(arr, left, m);
    mergeSort(arr, m + 1, right);

    merge(arr, left, right, m);    
  }    
}

void merge(int *arr, int left, int right, int merge) {
  int n1, n2;

  n1 = merge - left + 1;
  n2 = right - merge;

  int leftArray[n1], rightArray[n2];
  int i, j, k; // i for index of leftArray, j for rightArray, k for subarray

  for (i = 0; i < n1; i++) {
    leftArray[i] = arr[left + i];
  }

  for (j = 0; j < n2; j++) {
    rightArray[j] = arr[merge + 1 + j];
  }

  i = j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (leftArray[i] > rightArray[j]) {
      arr[k] = rightArray[j];
      j++;
    } else {
      arr[k] = leftArray[i];
      i++;
    }
    k++;    
  }

  while (i < n1) {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rightArray[j];
    j++;
    k++;    
  }
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));    
  }    
}  
