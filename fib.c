// This prog. calculates the n'th fibonacci no. for any 
// given n by recursion method but a more time efficient
// method not good in dealing with big no.

#include<stdio.h>

int a[25];

int fibonacci(int t){
  if(t == 1 || t == 0)
    return 1;
  if(a[t] == 0)
    a[t] = fibonacci(t-1) + fibonacci(t-2);
  return (a[t]);
}

int main(int argc, char *argv[]){
  int f ,h;
  for(f = 0;f < 25; f++)
    a[f] = 0;
  f = atoi(argv[1]);
  //  printf("Enter any n (< 25) to find the n'th fibonacci no.:");
  //scanf("%d",&f);
  h = fibonacci(f);
  printf("The %d'th fibonacci no. is %d\n",f,h);
  return 0;
}
