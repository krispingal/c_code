#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*start ,*temp;

struct node* enqueue(struct node *current ,int dat){
  if (current == NULL){
    current = malloc(sizeof(start));
    current->data = dat;
    current->next = NULL;
    return (current);
  }
  else
    current->next = enqueue(current->next ,dat);
  return (current);
}

struct node* dequeue(struct node *current){
  if (current == NULL)
    return (current);
  else if (current->next == NULL){
    temp = current->next;
    free(temp);
    current->next = NULL;
  }
  else
    current->next = dequeue(current->next);
  return (current);
}

void traversal(struct node *current){
  if (current == NULL)
    return;
  printf("%d \t",current->data);
  traversal(current->next);
  return;
}

int main(){
  int i , t ,n;
  start = NULL;
  printf("Enter the no. of elements to be entered in queue:");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for (i = 0; i < n; i++){
    scanf("%d",&t);
    start = enqueue(start , t);
  }
  traversal(start);
  printf("Enter a no. to be enqueued :");
  scanf("%d",&t);
  start = enqueue(start , t);
  traversal(start);
  printf("\nQueue after dequeued\n");
  start = dequeue(start);
  traversal(start);
  return(0);
}
