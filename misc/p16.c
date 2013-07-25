///Problem: Reverse a linked list in-order

#include <stdio.h>
#include <stdlib.h>

struct node{
  int DATA;
  struct node *NEXT;
}*root;

struct node* Reverse (struct node *current, struct node *parent){
  if (current == NULL)
    return NULL;
  else if (current->NEXT == NULL){
    root = current;
    current->NEXT = parent;
    if (parent != NULL)
      return parent;
    else
      return root;
  }
  else {
    current = Reverse (current->NEXT, current);
    current->NEXT = parent;
  if (parent == NULL)
    return root;
  else
    return (parent);
  }
}

void traversal (struct node *current){
  if (current == NULL)
    return;
  printf("%d\t", current->DATA);
  traversal(current->NEXT);
  return;
}

struct node* add_node (struct node *current, int key){
  if (current == NULL){
    current = malloc(sizeof (root));
    current->DATA = key;
    current->NEXT = NULL;
  }
  else{
    struct node *temp = malloc(sizeof (root));
    temp->DATA = key;
    temp->NEXT = current;
    current = temp;
  }
  return current;
}
int main(){
  int A[] = {15, 12, 6, 87, 92, 18};
  int i, size = 6;
  root = NULL;
  for (i = 0; i < size; i++)
    root = add_node(root, A[i]);
  printf("Linked list before reversal: ");
  traversal(root);
  root = Reverse(root, NULL);
  printf("\nLinked list after reversal: ");
  traversal(root);
  printf("\n");
  return 0;
}
