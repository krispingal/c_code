//This code is an attempt to do heapsort
//using arrays

#include<stdio.h>

void max_heapify (int A[], int i, int heapsize){
  int l = (2 * i) + 1;
  int r = (2 * i) + 2;
  int largest, temp;
 
  if (l <= heapsize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if (r <= heapsize && A[r] > A[largest])
    largest = r;

  if (largest != i){
    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    max_heapify(A, largest, heapsize);
  }
  return;
}

void build_max_heap (int A[], int size){
  int i;
  for (i = size/2; i >= 0; i--){
    max_heapify(A, i, size);
  }
  return;
}

void heapsort (int A[], int size){
  int i, temp;
  build_max_heap(A, size);
  for (i = size; i >= 1; i--){
    temp = A[i];
    A[i] = A[0];
    A[0] = temp;
    size--;
    max_heapify(A, 0, size);
  }
  return;
}

int main(){
  int i, size = 8;
  int t[] = {21, 83, 27, 13, 12, 734, 62, 84};
  printf("Unsorted Array: ");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);
  printf("\nAfter sorting: ");
  heapsort(t, size - 1);
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);
  printf("\n");
  return 0;
}


    
