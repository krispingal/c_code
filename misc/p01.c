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
  int FLAG;
  struct btree *DATA;
  struct node *NEXT;
}*top, *temp_node;

struct node* push (struct node *current, struct btree *data){
  if (current == NULL){
    current = malloc(sizeof (top));
    current->FLAG = 0;                           //FLAG = {0,1,2} = 0:reached node, 1:traversed left sub tree ,2:traversed right sub tree
    current->DATA = data;
    current->NEXT = NULL;
    printf("\n%d\t:",(current->DATA)->KEY);
  }
  else{
    struct node *tmp = malloc(sizeof (top));
    tmp->DATA = data;
    tmp->NEXT = current;
    current = tmp;
    printf("\n%d\t:",(current->DATA)->KEY);
    traversal(current->NEXT);
  }
  return (current);
}

struct node* pop (struct node *current){
  temp_node = current;
  if (current == NULL){
    printf("\nUnderflow\n");
    return (current);
  }
  current = current->NEXT;
  free(temp_node);
  return (current);
}

void traversal (struct node *current){
  if (current == NULL)
    return;
  printf("%d\t", (current->DATA)->KEY);
  traversal(current->NEXT);
}

struct node* find_ancestor (struct btree *current){
  top = NULL;
  top = push (top, current);
  while (top != NULL){
    temp_tree = top->DATA;
    if (top->FLAG == 0){
      if (temp_tree->LEFT != NULL)
	top = push (top, temp_tree->LEFT);
      else      
	top->FLAG = 1;
    }
    else if (top->FLAG == 1){
      if (temp_tree->RIGHT != NULL)
	top = push (top, temp_tree->RIGHT);
      else      
	top->FLAG = 2;
    }
    else {
      top = pop (top);
      if (top != NULL)
	top->FLAG++;              ///tells the parent of previous top that, that subtree has been succesfully passed
    }
  }
}
struct btree* addnode(struct btree *current, int t){
  if (current == NULL){
    current = malloc(sizeof (root));
    current->KEY = t;
    current->LEFT = NULL;
    current->RIGHT = NULL;
  }
  else 
    current->KEY = t;
  return current;
}
int main(){
  root = NULL;
  root = addnode(root, 1);
  root->LEFT = addnode(root->LEFT, 2);
  root->RIGHT = addnode(root->RIGHT, 3);
  root->LEFT->LEFT = addnode(root->LEFT->LEFT, 4);
  root->LEFT->RIGHT = addnode(root->LEFT->RIGHT, 5);
  root->RIGHT->RIGHT = addnode(root->RIGHT->RIGHT, 6);
  root->LEFT->RIGHT->LEFT = addnode (root->LEFT->RIGHT->LEFT, 7);
  root->RIGHT->RIGHT->LEFT = addnode (root->RIGHT->RIGHT->LEFT, 8);
  
 find_ancestor(root);
  printf("\n");
  return 0;
}
