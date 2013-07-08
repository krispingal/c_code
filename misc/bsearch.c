#include<stdio.h>
int bsearch(int ar[],int t ,int n){
  int m ,i;
  m = 0;
  i = n/2;
  while(m <= n){
    if(ar[i] == t)
      return (i);
    else if(ar[i] < t){
      m = i + 1;
      i =(m + n)/2;
    }
    else{
      n = i - 1;
      i =(m + n)/2;
    }
  }
  return (-1);
}
int main(){
  int t,ar[10]={0,1,2,3,4,5,6,7,8,9};
  printf("Enter no. to be searched \n");
  scanf("%d",&t);
  printf("%d is ",t);
  t =bsearch(ar,t,10);
  if (t == -1)
    printf("not present in the array");
  else
    printf("present in position %d",t+1);
  return 0;
} 
