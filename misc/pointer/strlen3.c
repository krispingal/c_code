//This is yet another code to find out string length
//This code als like the previous one uses character pointer 
//as formal argument for function strlen, but this one uses 
//pointer arithmetic

#include <stdio.h>

int str_len (char *s){
  char *p = s;
  printf("Length of string \"%s\" is :", s);
  for (; *p != '\0'; p++);
  return (p - s);
}

int main(){
  char *a = "Hello World!";
  int i;
  i = str_len (a);
  printf("%d\n",i);
  i = str_len ("Hi, I'm krispin");
  printf("%d\n",i);
  return 0;
}
