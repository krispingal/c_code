#include<stdio.h>

void sort (int ar[], int size){
  int i, j, k, temp;
  for (i = 1; i < size; i++){
    temp = ar[i];
    for (j = i; j >= 0 && temp < ar[j -1] ; j--)
	ar[j] = ar[j - 1];
      ar[j] = temp;
  }
}

int main(){
  int array[] = {12, 24, 14, 35, 90, 42, 72, 3, 20};
  int i, size = 9;        //size stores the size of target array
  for (i = 0; i < size; i++)
    printf("%d\t", array[i]);

  sort(array, size);
  printf("\nAfter sorting:\n");
  for (i = 0; i < size; i++)
    printf("%d\t", array[i]);
  printf("\n");
  return 0;
}
