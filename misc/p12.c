/*Problem statement:WAP to evaluate a string that has only 
integers and operators '+' & '*'.The evaluation should be 
done in a single pass. For example passing "3*2+5*6" should 
result in this function returning 36
SOURCE: carrercup
*/

#include<stdio.h>
#include<string.h>

int foo (char t[]){
  int len, i, accum, prod, temp;
  char prev_op = '+';
  len = strlen(t);
  accum = 0;
  temp = 0;

  for (i = 0; i <= len; i++){
    if (t[i] >= '0' && t[i] <= '9')
      temp = temp * 10 + (t[i] - '0');           //if number is more than 1-digit

    else if (t[i] == '*' ){
      if (prev_op == '+'){
	prod = temp;
      }
      else
	prod *= temp;
      temp = 0;
      prev_op = '*';    
    }
    else if (t[i] == '+'|| t[i] == '\0'){
      if (prev_op == '*'){
	prod *= temp;
	accum += prod;
	prod = 0;
      }
      else
	accum += temp;
      temp = 0;
      prev_op = '+';
    }
    else{
      error("Error: Invalid operand");
      return 0;
    }
  }
  return (accum);
}

int main(){
  int res;
  char t[] = "3+2+1*2+5*6+21";
  res = foo(t);
  printf("result: %d\n",res);
  return 0;
}
 
