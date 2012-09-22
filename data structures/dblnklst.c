#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
}*root ,*temp;

struct node* insert(struct node *current  ,int dat ,int pos){
  if( current == NULL){
    temp =( struct node *) malloc(sizeof(root));
    temp->data =dat;
    temp->next = NULL;
    temp->prev = NULL;
    current = temp;
    return (current);
    printf("\t %d is inserted",dat);
  }
  struct node *nxt = current->next;
  if (pos == 1 && nxt != NULL){
    temp = malloc(sizeof(root));
    temp->data = dat;
    temp->next = nxt;
    temp->prev = current;
    current->next = temp;
    nxt->prev = temp;
    printf("\t %d is inserted",dat);

  }
  else if(pos == 0){
    temp = malloc(sizeof(root));
    temp->data = dat;
    temp->next = current;
    temp->prev = NULL;
    current->prev = temp;
    return(temp);
  }
  else if(pos == 1){
    temp = malloc(sizeof(root));
    temp->data = dat;
    temp->next = NULL;
    temp->prev = current;
    current->next = temp;
  }
  else
    current->next = insert(current->next, dat, pos - 1);
  return(current);
}

void displist(struct node *current){
  if (current == NULL)
    return;
  printf("%d \t",current->data);
  displist(current->next);
  return;
}

struct node* delete(struct node *current , int tar){
  if(current == NULL){
    printf("\nElement not present");
    return(current);
  }
  if(current->data == tar && current->prev == NULL){
    temp = current->next;
    temp->prev = NULL;
    free(current);
    return (temp);
  }
  else if(current->data == tar && current->next == NULL){
    temp = current->prev;
    temp->next = NULL;
    free(current);
    return (temp);
  }
  else if(current->data == tar){
    temp = current->prev;
    temp->next = current->next;
    temp = current->next;
    temp->prev = current->prev;
    free(current);
    return(temp);
  }
  current->next = delete(current->next ,tar);
  return(current);
}

int main(){
  int t , i , n, pos;
  root =NULL;
  printf("Enter the no. of elements to be entered in the doubly linked list:");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i =0 ;i < n ; i++){
    scanf("%d",&t);
    root = insert(root ,t ,i);
  }
  displist(root);
  printf("\nEnter a no. to be inserted & it's position( <= %d)\n",n);
  scanf("%d%d",&t,&pos);
  root = insert(root ,t ,pos-1);
  displist;
  printf("Enter any no.in the list to be deleted:");
  scanf("%d",&t);
  root = delete(root ,t);
  printf("List after modification:");
  displist(root);
  return 0;

}
