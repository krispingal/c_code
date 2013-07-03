//Problem statement: To find all the ancestors of a given binary
//tree without using recursion

//This code uses a stack to store the ancestors of a node

#include<stdio.h>
#include<stdlib.h>

struct btree{
  int KEY;
  struct btree *LEFT;
  struct btree *RIGHT;
}*root, *temp_tree;

struct node{
  struct btree DATA;
  struct node *NEXT;
}*top, *temp_node;

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

struct node* find_ancestor (struct btree *current){
  int flag = 0;
  top = push (top, current);
  while (top != NULL){
    print_ancestor (top);
    temp_tree = top->DATA;
    if (temp_tree->LEFT != NULL && flag == 0){
      top = push (top, temp_tree->LEFT);
      continue;
    }
    else if (temp_tree->RIGHT != NULL && flag == 1){
      top = push (top, temp_tree->RIGHT);
      continue;
    }
    else {
      top = pop (top);
      flag = 1;
    }
  }
