#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*start, *temp;

struct node* push(struct node *current , int dat){
  if (current == NULL){
    temp = malloc(sizeof(struct node));
    temp->data =dat;
    temp->next = NULL;
    current = temp;
  }
  else
    current->next = push(current->next,dat);
  return(current);
}

struct node* pop(struct node *current){
  if (current == NULL){
    printf("\nUnderflow");
    return(current);
  }
  else if(current->next == NULL){
    temp = current->next;
    current->next = NULL;
    free(temp);
    return(NULL);
  }
  else 
    current->next = pop(current->next);
  return(current);
}

void traversal(struct node*current){
  if (current == NULL)
    return;
  printf("%d \t",current->data);
  traversal(current->next);
  return;
}

int main(){
  int i , n, t;
  start = NULL;
  printf("Enter the no. of elements to be entered in the stack:");
  scanf("%d",&n);
  printf("Enter the no. in the stack\n");
  for(i = 0;i < n; i++){
    scanf("%d",&t);
    start = push(start ,t);
  }
  traversal(start);
  printf("Enter any no. to be pushed into stack:");
  scanf("%d",&t);
  start = push(start ,t);
  traversal(start);
  printf("\nstack after pop\n");
  start = pop(start);
  traversal(start);
  return 0;
}
