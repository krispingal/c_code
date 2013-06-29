#include<stdio.h>

void selectionsort (int ar[], int size){
  int i, j, max, pos, k;
  for (i = 0; i < size; i++){
    pos = 0;
    max = ar[0];
    for (j = 0; j <= (size - i); j++){
      if (max < ar[j]){
	max = ar[j];
	pos = j;
      }
    }
    ar[pos] = ar[size-i];
    ar[size-i] = max;
  }
}

int main(){
  int i, size = 10;
  int t[] = {12, 34, 23, 5, 265, 63, 456, 246, 10, 92};
  printf("Unsorted array:");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);
  
  selectionsort (t, size-1);
  printf("\nAfter sorting:");
  for (i = 0; i < size; i++)
    printf("%d\t",t[i]);
  printf("\n");
  return 0;
}

