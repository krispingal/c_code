///Problem statement:WAP to create a mirror of a binary tree.

#include <stdio.h>
#include <stdlib.h>

struct btree{
  int KEY;
  struct btree *RIGHT;
  struct btree *LEFT;
}*root, *temp;

struct btree* add_node (struct btree *current, int data){
  if (current != NULL)
    current->KEY = data;
  else{
    current = malloc (sizeof (root));
    current->KEY = data;
    current->RIGHT= NULL;
    current->LEFT= NULL;
  }
  return current;
}

struct btree* create_mirror (struct btree *tree, struct btree *mbtree){
  if (tree == NULL)
    mbtree = NULL;
  else{ 
    mbtree = malloc(sizeof (root));
    mbtree = add_node(mbtree, tree->KEY);
    mbtree->RIGHT = create_mirror(tree->LEFT, mbtree->RIGHT);
    mbtree->LEFT = create_mirror(tree->RIGHT, mbtree->LEFT);
  }
  return (mbtree);
}
void traversal (struct btree *current){
  if (current == NULL)
    return;
  printf("%d\t", current->KEY);
  traversal (current->LEFT);
  traversal (current->RIGHT);
  return;
}

int main(){
  root = NULL;
  temp = NULL;
  root = add_node(root,14);
  root->LEFT = add_node(root->LEFT, 1);
  root->RIGHT = add_node(root->RIGHT, 6);
  root->LEFT->LEFT = add_node(root->LEFT->LEFT, 9);
  printf("Btree original : ");
  traversal(root);
  temp = create_mirror(root, temp);
  printf("\nMirror of binary tree : ");
  traversal(temp);
  printf("\n");
  return 0;
}
