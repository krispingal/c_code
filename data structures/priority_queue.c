#include<stdio.h>

void max_heapify(int A[], int i, int size){
  int l = (2 * i) + 1;
  int r = (2 * i) + 2;
  int largest, temp;

  if (l <= size && A[l] > A[i])
    largest = l;
  else  
    largest = i;
  if (r <= size && A[r] > A[largest])
    largest = r;

  if (largest != i){
    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    max_heapify(A, largest, size);
  }

  return;
}

void build_maxheap (int A[], int size){
  int i;
  for (i = size/2; i >= 0; i--)
    max_heapify (A, i, size);
  return;
}

int heap_extract_max(int A[], int size){
  int i, max;
  if (size < 0)
    error("\nHeap underflow");
  max = A[0];
  A[0] = A[size];
  max_heapify(A, 0, size-1);
  return max;
}

void heap_increase_key (int A[], int t, int key){
  int i, temp;  
  if (key < A[t])
    error ("\nNew key less than previous key");
  A[t] = key;
  for (i = t; i > 0 && A[i] > A[i/2]; i = i/2){
    temp =A[i];
    A[i] = A[i/2];
    A[i/2] = temp;
  }
  return;
}
 
void max_heap_insert (int A[], int key, int size){
  size++;
  A[size] = -99999;
  heap_increase_key(A, size, key);
  return;
}

int main(){
  int i, size = 9;
  int t[] = {63, 73, 25, 19, 44, 2, 59, 38, 10};
  printf("Array before creating priority queue:");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);

  build_maxheap(t,size-1);
  printf("\nNewly built Priority queue : ");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);

  i = heap_extract_max(t, size-1);
  size--;
  printf("\nExtract maximum:%d\n",i);

  printf("Priority queue after extract maximum: ");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);

  printf("\nEnter a number to be inserted into the priority queue:");
  scanf("%d", &i);
  max_heap_insert(t, i, size-1);
  size++;
  printf("Priority queue after insert: ");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);

  printf("\n");
  return 0;
}
