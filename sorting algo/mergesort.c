#include<stdio.h>

void merge (int ar[], int p, int q, int r){
  int n, m, i, j, k;
  n = q - p + 1;
  m = r - q;
  int L[n + 1];
  int R[m + 1];
  for (i = 0; i < n; i++)
    L[i] = ar[p + i];
  L[i] = 7890989;
  for (j = 0; j < m; j++)
    R[j] = ar[q + j + 1];
  R[j] = 9999999;
  for (k = p, i = 0, j = 0; k <= r; k++){
    if (L[i] <= R[j]){
      ar[k] = L[i];
      i++;
    }
    else{
      ar[k] = R[j];
      j++;
    }
  }
}

void mergesort (int ar[], int p, int r){
  int q;
  if (p < r){
    q = (p + r) / 2;
    mergesort (ar, p, q);
    mergesort (ar, q + 1, r);
    merge (ar, p , q, r);
  }
  return;
}

int main(){
  int i, size = 10;
  int t[] = {92, 23, 54, 56, 56, 1, 83, 20, 19, 8};
  printf("Unsorted array:");
  for (i = 0; i < size; i++)
    printf("%d\t", t[i]);
  mergesort (t, 0, size - 1);
  printf("\nArray after sort:");
  for (i = 0; i < size; i++)
    printf("%d\t", t[i]);
  printf("\n");
  return 0;
}
