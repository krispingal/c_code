#include<stdio.h>

void csort(int ar[] , int n){
  int i , l, j ,temp;
  for(i = 0,j = n;i < j; i++ ,j--){
    for(l = i; l < j; l++){
      if(ar[l] > ar[l + 1]){ 
	temp = ar[l];
	ar[l] = ar[l + 1];
	ar[l + 1] = temp;
      }
    }
    for(l = j; l > i; l--){
      if(ar[l] < ar[l - 1]){
	temp =ar[l];
	ar[l] =ar[l - 1];
	ar[l - 1] = temp;
      }
    }
  }

}

int main(){
  int ar[8] ,i;
  printf("Enter any 8 no.\n");
  for(i = 0; i < 8; i++)
    scanf("%d",&ar[i]);
  csort(ar ,7);
  printf("\n");
  for(i = 0; i < 8;i++)
    printf("%d \t",ar[i]);
  return 0;
}
