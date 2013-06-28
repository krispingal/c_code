#include<stdio.h>

void bubblesort (int array[], int size){
  int i, j, k, temp = 0;
  for(i = 0; i < size; i++){
    for(j = 0; j < (size -i - 1); j++){
      if (array[j] > array[j+1]){
	temp = array[j+1];
	array[j+1] = array[j];
	array[j] = temp;
      }
    }
    //    printf("\nIteration %d:\n", i+1);
    //     for(k = 0; k < 8; k++)
    //    printf("%d\t", array[k]);

  }
}

int main(){
  int array[] = {23, 34, 45, 1, 56, 25, 67, 9, 4 ,13};
  int i, size = 10;
  for(i = 0; i < size; i++)
    printf("%d\t", array[i]);
  printf("\nAfter sorting\n");
  bubblesort(array, size);
  for(i = 0; i < size; i++)
    printf("%d\t", array[i]);
  printf("\n");
  return 0;
}
