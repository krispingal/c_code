//This code uses pointers to find string length
//The formal parameter passed to the funtion str_len is character pointer

#include <stdio.h>

int str_len (char *p){
  int i;
  printf("Length of string \"%s\" is :", p);
  for (i = 0; *p != '\0'; p++, i++);
  return i;
}

int main(){
  char *s = "Hello World!";
  int i;
  i = str_len (s);
  printf("%d\n", i);
  i = str_len ("Hi, I'm krispin");
  printf("%d\n", i);
  return 0;
}

