//This code uses very basic concepts of strings
//The function strlen has a formal argument of character array
#include <stdio.h>

int str_len(char a[]){
  int i;
  printf("Length of string \" %s\" is :", a);
  for (i = 0; a[i] != '\0'; i++);
  return i;
}

int main(){
  char *a = "Hello world!";
  int i;
  i = str_len (a);
  printf("%d\n", i);
  i = str_len ("Hi, I'm krispin");
  printf("%d\n", i);
  return 0;
}
