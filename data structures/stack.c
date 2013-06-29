///This code implements a stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
  int DATA;
  struct node *NEXT;
}*top, *temp;

struct node* push (struct node *current, int data){
  if (current == NULL){
    current = malloc(sizeof (top));
    current->DATA = data;
    current->NEXT = NULL;
  }
  else{
    struct node *tmp = malloc(sizeof (top));
    tmp->DATA = data;
    tmp->NEXT = current;
    current = tmp;
  }
  return (current);
}

struct node* pop (struct node *current){
  temp = current;
  if (current == NULL){
    printf("\nUnderflow\n");
    return (current);
  }
  current = current->NEXT;
  free(temp);
  return (current);
}

void traversal (struct node *current){
  if (current == NULL)
    return;
  printf("%d\t", current->DATA);
  traversal(current->NEXT);
}

int main(){
  int i, size;
  int t[] = {12, 32, 52, 7, 857, 4};
  size = 6;
  top = NULL;
  for (i = 0; i < size ; i++)
    top = push(top, t[i]);
  printf("Stack:\n");
  traversal(top);
  printf("\nStack after pop: ");
  top = pop(top);
  traversal(top);

  printf("\n");
  return 0;
}

 
