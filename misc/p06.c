/*Problem Statement:Find the majority number in a given sequence
of numbers (a number that occurs > N/2 times where N is the count 
of numbers in the sequence) Don't maintain a map of all occuring 
numbers along with a count. No number maybe a majority*/
//Problem from career cup

#include <stdio.h>

void bubble_sort (int A[], int size){
  int i, j, temp;
  for (i = 0; i < size; i++){
    for (j = 0; j < (size-i-1); j++){
      if (A[j] > A[j+1]){
	temp = A[j+1];
	A[j+1] = A[j];
	A[j] = temp;
      }
    }
  }
  return;
}
//After sorting posssible majority number will also occupy middlemost number, since
//count(majority number) > size/2, then start a count of this number & check if > size/2 
void majority_number (int A[], int size){
  int i, half_length, flag = 0;
  half_length = size/2;
  bubble_sort (A, size);     
  int temp = A[half_length]; 
  for (i = 0; i < half_length; i++){
    if (A[i] == temp && A[i+half_length] == temp){
      flag = 1;
      break;
    }
    else if (A[i] == temp)               // if no longer the majority(possible) number
      break;
  }
  if (flag)
    printf("\n%d is the majority no. in the list\n", temp);
  else
    printf("\nNo majority number in the list\n");
  return;
}

int main(){
  int a[] = {21, 18, 7, 82, 80, 8, 8, 7, 8, 8, 2, 4, 8, 8};
  int i, size = 10;
  printf("List is : ");
  for (i = 0; i < size; i++)
    printf("%d, ", a[i]);
  majority_number(a, size);
  return 0;
}
