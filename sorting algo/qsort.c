#include<stdio.h>
// This is is a modified version of 
// the quicksort algorithm
void qsort(int ar[] ,int m ,int n){
  if (m >= n)
    return;
  int t ,i ,j , k;
  t = ar[(m + n)/2];
  for (i = m, j = n; i < j;){
    for (; ar[i] < t && i < n ;i++);
    for (; ar[j] > t  && j > i;j--);
    k = ar[i];
    ar[i] = ar[j];
    ar[j] = k;
  }
  for(i = m;ar[i] != t && i <= n; i++); //this loop is to find the position
  //of the partition of the list 
  if (i == m)
    qsort(ar ,i + 1, n);
  else
    qsort(ar ,m ,i - 1);
  if (i == n)
    qsort(ar ,m , i-1);
  else
    qsort(ar ,i+1, n);
  return;
}
int main(){
  int i ;
  int ar[]={9,7,34,28,56,12,30,18};
  for (i =0; i <= 7; i++)
    printf("%d\t",ar[i]);
  qsort(ar, 0, 7);
  printf("\nafter sorting the list is :\n");
  for (i =0; i <= 7; i++)
    printf("%d\t",ar[i]);
  printf("\n");
  return 0;
}
