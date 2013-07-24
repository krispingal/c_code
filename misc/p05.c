/*Problem statement:Given a linked list and two integers M and N.
Traverse the linked list such that you retain M nodes then delete the 
next N nodes, continue the same till the end of the linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  int DATA;
  struct node *NEXT;
}*root, *temp;

struct node* add_node (struct node *current, int key){
  if (current == NULL){
    current = malloc(sizeof (root));
    current->DATA = key;
    current->NEXT = NULL;
  }
  else 
    current->NEXT = add_node (current->NEXT, key);
  return (current);
}

struct node* build_list (int A[], int size){
  struct node *root = NULL;
  int i;
  for (i = 0; i < size; i++){
    root = add_node(root, A[i]);
  }
  return root;
}

struct node* delete_M_N (struct node *current, int M, int N){
  int i, flag = 0;
  struct node *tmp, *t;
  temp = current;
  for (i = 0; i < (M - 1); i++)
    temp = temp->NEXT;
  if (i > 0)
    tmp = temp->NEXT;
  else{
    flag = 1;
    tmp = temp;
  }
  for (i = 0; i < N && tmp != NULL; i++){
    t = tmp;
    tmp = tmp->NEXT;
    free (t);
  }
  if (flag)
    current = tmp;
  else
    temp->NEXT = tmp;
  return (current);
}

void traversal (struct node *current){
  if (current == NULL)
    return;
  printf("%d\t", current->DATA);
  traversal (current->NEXT);
  return;
}

int main(){
  int m, n, size = 9;
  int t[] = {12, 53, 28, 83, 63, 91, 85, 76, 40};
  root = NULL;
  root = build_list(t, size);
  printf("Linked list:");
  traversal (root);
  printf("\nEnter m & n:");
  scanf("%d%d", &m, &n);
  root = delete_M_N(root, m, n);
  printf("After deletion:");
  traversal(root);
  printf("\n");
  return 0;
}
