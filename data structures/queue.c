#include<stdio.h>
#include<stdlib.h>

struct node{
  int val;
  struct node *next;
}*start, *temp;

struct node* enqueue(struct node *current, int data){
  if (current == NULL){
    current = malloc(sizeof(start));
    current->val = data;
    current->next = NULL;
  }
  else
    current->next = enqueue(current->next, data);
  return (current);
}

struct node* dequeue (struct node *current){
  if (current == NULL){
    printf("\n Underflow\n");
    return current;
  }
  temp = current;
  free(temp);
  return (current->next);
}
void traversal (struct node *current){
  if (current == NULL)
    return;
  printf("%d \t",current->val);
  traversal(current->next);
}

int main(){
  int i, l , data;
  start = NULL;
  printf("Enter Queue length:\n");
  scanf("%d", &l);
  printf("Enter queue elements\n");
  for(i = 0; i < l; i++){
    scanf("%d", &data);
    start = enqueue(start, data);
  }
  printf("Queue: ");
  traversal(start);
  printf("\nQueue after dequeue: ");
  start = dequeue(start);
  traversal(start);
  return 0;
}
