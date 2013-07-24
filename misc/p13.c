//Problem statement: From a list find the max product of three numbers
//The way I did this problem was 
//* first sort the list (I used bubble sort)
//  compare the prod. of first two elements and last two elements
// then depending on this give the maximum possible product
#include <stdio.h>
#include <stdlib.h>

int main(){
  int ar[] = {1, 23, 8, -17, 4, -9, 12, 21, -12};
  int a, b, i, j, size = 9;
  int temp;
  printf("List is :");
  for(i =0; i < size; i++)
    printf("%d\t", ar[i]);
  for (i = 0; i < size; i++){
    for (j = 0; j < size-i-1; j++){
      if (ar[j] > ar[j+1]){
	temp = ar[j+1];
	ar[j+1] = ar[j];
	ar[j] = temp;
      }
    }
  }
  a = ar[0] * ar[1];
  b = ar[size-1] * ar[size-2];
  temp = (a > b)? (a * ar[size-1]): (b * ar[size-3]); 
  printf("\nMax product of three elements of the list is :%d\n", temp);
  return 0;
}

