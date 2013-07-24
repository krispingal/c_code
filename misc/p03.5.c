/// Problem statement : Eliminate duplicates from string
/// this code uses hashing
#include <stdio.h>

void el_dup(char *s, char *p){
  int H[256];
  int i, t, k;
  for(i = 0; i < 256; i++)
    H[i] = 0;
  for(i = 0, k = 0; *(s+i) != '\0'; i++){
    t = (int) (*(s+i));
    if (H[t] == 0){
      p[k] =s[i];
      H[t] = 1;
      k++;
    }
  }
  *(p + k) = '\0';
}

int main(){
  char *p = "krishna pingal";
  char *r;
  r = malloc(sizeof(strlen(p)));
  printf("Original string: \"%s\" \n", p);
  el_dup (p,r);
  printf("String after eliminating duplicates: %s\n", r);
  return 0;
}
