#include<stdio.h>

void merge(int ar[] ,int p ,int r ,int q){
  int i ,j ,t;
  int *b ,*c;
  i = 0;
  while(i <= (r-p)){
    *(b + i) = ar[p+i];
    printf("*(b + i) = %d\n",*(b + i));
    i++;
  } 
  *(b + i) = '\0';
  j = 0;
  while(j <= (q-r+1)){
    *(c + j) = ar[r+j+1];
    printf("*(c + j) = %d\n",*(c + j));
    j++;
  }
  *(c + j) = '\0';
  printf("value of *b = %d \t",*(b));
  //c = ar + r +1;
  printf("value of *c = %d\n",*c);
  for(i = 0 ,j = 0 ,t = 0; i <= (r - p) && j <= (q-r+1) ; t++){
    printf("*(b + i) = %d ,*(c + j) = %d\n",b[i],c[j]);
    if (b[i] <= c[j]){
      ar[t] = b[i];
      printf("value of ar[%d] (1)= %d\n",t ,ar[t]);
      i++;
    }
    else {
      ar[t] = c[j];
      printf("value of ar[%d] (2) = %d\n",t ,ar[t]);
      j++;
    }
  }
  if(i > (r - p)){
    while (*(c + j) != '\0'){
      printf("ar[%d] = %d (1) \n",t,*(c+j));
      ar[t] = c[j];
      t++;
      j++;
    }
  }
  else {
    while (*(b + i) != '\0'){
      printf("ar[%d] = %d (2) \n",t,*(c+j));
      ar[t] = *(b + i);
      t++;
      i++;
    }
  }
}
void mergesort(int ar[] ,int p ,int q){
  int r;
  r = (p + q)/2;
  if (p < q){
    printf("calling mergesort with p = %d and r = %d\n",p,r);
    mergesort(ar ,p ,r);
    printf("\ncalling mergesort with p = %d and r = %d \n",r+1,q);
    mergesort(ar ,r+1, q);
    printf("\ncalling merge with p = %d, r = %d and q = %d \n",p,r,q);
    merge(ar, p, r, q);
  }
  return;
}

int main(){
  int ar[] = {5,7,1,3};
  int i ;
  printf("the array before mergesort: \n");
  for(i = 0; i <=3 ;i++)
    printf("%d\t",ar[i]);
  printf("\nThe array after sorting: \n");
  mergesort(ar , 0 ,3);
  for(i = 0; i <=3 ; i++)
    printf("%d\t",ar[i]);
  printf("\n");
  return 0;
}
