//This program is for adding 50 digit no's and displaying the first
//10 digits of the sum

//Can support maximum of 100 50 digit numbers

#include <stdio.h>

int main(){
  int i, n, carry, temp;
  int sum[52];
  char buf[50];
  FILE *fp;
  for (i = 0; i < 52; i++)
    sum[i] = 0;
  fp = fopen("out", "r");
  while ((fscanf(fp, "%s", buf)) > 0){
    printf("%s", buf);
    //    printf("\n");
    carry = 0;
    for (i = 51; i >= 0; i--){
      if (i > 1){
	temp = *(buf + i - 2) - '0';
      }
      else
	temp = 0;
      sum[i] += temp + carry;
      carry = sum[i] / 10;
      sum[i] %= 10;
    }
    printf("\n");
  }
  printf("First ten digits of sum\n");
  for (i = 0; i < 52 && sum[i] == 0; i++);                 ///We do not need the first digits which are 0, 002 -> 2 
  for (n = 0; n < 10 && i < 52; n++, i++)
    printf("%d", sum[i]);
  printf("\n");
  return 0;
}
