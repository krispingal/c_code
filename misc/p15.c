///Find out the endianness of a system

#include <stdio.h>

int foo (){
  int r, x =0x1;
  char *p = (char *)&x;
  if (*p == 1)
    r = 1;
  else
    r = 0;
  return r;
}

int main(){
  int i;
  i = foo();
  if (i)
    printf("Little Endian\n");
  else
    printf("Big Endian\n");
  return 0;
}
