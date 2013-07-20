///Problem Statement:Given a string pattern of 0s, 1s, ?s(wildcards)
///generate all 0-1 strings that match this pattern
///e.g. 1?00?-> [10000, 10001,11000,11001]
///order is irrelevant
///Problem from careercup

#include <stdio.h>
#include <string.h>

void gen_string (char s[], int j){
  int i;
  for (i = j; s[i] != '\0'; i++){
    if (s[i] == '?'){
      s[i] = '0';
      gen_string (s, i+1);
      s[i] = '1';
      gen_string (s, i+1);
      s[i] = '?';
    }
    else {
      i++;
    }
  }
  for (i = 0; s[i] != '\0'; i++)           //This loop is so that strings created intermediately having '?'
    if (s[i] == '?')                       //are not printed insteadd they are returned
      return;
  printf("%s ,",s);
}

int main(){
  char a[] = "???";
  printf("String is %s, Generated strings :", a);
  gen_string (a, 0);
  printf("\n");
  return 0;
}
