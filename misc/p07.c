//Problem Statement:Given two arrays of same size arrange the arrays 
//such that a1*b1 + a2*b2.... + an*bn should be minimum

//What i did was sort(bubble) both arrays one in increasing order other in 
//decreasing order. The sum we get by this order will give us
//the minimum sum

#include <stdio.h>

int main(){
  int a[] = {12, 34, 91, -3, 71, 30, -43, 9, 17};
  int b[] = {25, 51, -72, 49, 29, 10, -6, 83, 3};
  int i, j, temp,size = 9; 
  int sum;
  printf("Before sorting :\n");
  for (i = 0; i < size; i++)
    printf("%d\t", a[i]);
  printf("\n");
  for (i = 0; i < size; i++)
    printf("%d\t", b[i]);
  for (i = 0; i < size; i++)
    for (j = 0; j < size-i-1; j++){
      if (a[j] > a[j+1]){
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
      }
    }
  for (i = 0; i < size; i++)
    for (j = 0; j < size-i-1; j++){
      if (b[j] < b[j+1]){
	temp = b[j];
	b[j] = b[j+1];
	b[j+1] = temp;
      }
    }
  printf("\nAfter sorting: \n");
  for (i = 0; i < size; i++)
    printf("%d\t", a[i]);
  printf("\n");
  for (i = 0, temp = 1; i < size; i++){
    temp += a[i] * b[i];
    printf("%d\t", b[i]);
  }
  printf("\nThe sum of a[i]* b[i] = %d\n",temp);
  return 0;
}
