///Problem statement:Eliminate duplicate characters from string
///This code uses copies characters, which were not encountered
///before, to a string. Characters are checked if they appeared 
///before by re-checking our newly created string
///Worst case : O(n^2)
///Code sees upper case and lower case characters differently
 
#include <stdio.h>
#include <string.h>

char* el_dup (char *s, char *t){
  int i, j;
  char temp;
  *t = *s;
  for(i = 1; *(s + i) != '\0'; i++){
    temp = *(s + i);
    for (j = 1; *(t + j) != '\0'; j++){
      if (*(t+j) == temp){
	break;
      }
    }
    if (*(t + j) =='\0'){
      *(t + j) = temp;
      *(t+j+1) = '\0';
    }
  }
  return (t);
}

int main(){
  char *a = "krishna pingal";
  char *p;
  p = malloc(sizeof(strlen (a)));
  printf("Original string : \"%s\"", a);
  a = el_dup (a, p);
  printf("\nString after eliminating duplicate elements: %s\n", p);
  return 0;
}
