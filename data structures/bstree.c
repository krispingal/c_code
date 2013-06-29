/*This code implements a binary search tree
with options to perform
*preorder
*inorder
*postorder
traversal
find-grand parent of an element
*/

#include<stdio.h>
#include<stdlib.h>

struct bstree{
  int DATA;
  struct bstree *RIGHT;
  struct bstree *LEFT;
}*root, *temp;

struct bstree* insert (struct bstree *current, int data){
  if (current == NULL){
    current = malloc(sizeof (root));
    current->DATA = data;
    current->RIGHT = NULL;
    current->LEFT = NULL;
  }
  else {
    if (data <= current->DATA)
      current->LEFT = insert(current->LEFT, data);
    else 
      current->RIGHT = insert(current->RIGHT, data);
  }
  return (current);
}

void inorder (struct bstree *current){
  if (current == NULL)
    return;
  inorder (current->LEFT);
  printf("\t%d", current->DATA);
  inorder (current->RIGHT);
  return;
}

void preorder (struct bstree *current){
  if (current == NULL)
    return;
  printf("\t%d",current->DATA);
  preorder (current->LEFT);
  preorder (current->RIGHT);
  return;
}

void postorder (struct bstree *current){
  if (current == NULL)
    return;
  postorder(current->LEFT);
  postorder(current->RIGHT);
  printf("\t%d",current->DATA);
  return;
}

int find_gp (struct bstree *current, int tar){
  int count;
  if (current == NULL){
    printf("\nElement not present in tree\n");
    return (count);
  }
  if (tar == current->DATA)
    return (-2);
  else if (tar < current->DATA)
    count = find_gp(current->LEFT, tar);
  else 
    count = find_gp(current->RIGHT, tar);
  if (count == -2)
    return (-3);
  else  if (count == -3)
    return (current->DATA);

 return count;
}

int main(){
  int i,  size = 12;
  int t[] = {8, 12, 6, 14, 24, 5, 3, 7, 2, 54, 30, 20};
  root = NULL;
  printf("Input array:");
  for (i = 0; i < size; i++){
    printf("%d \t",t[i]);
    root = insert(root, t[i]);
  }
  printf("\nInorder traversal:");
  inorder(root);
  printf("\nPre-order traversal:");
  preorder(root);
  printf("\nPost-order traversal:");
  postorder(root);
  printf("\nEnter any element in the bst, to find it's grand parent: ");
  scanf("%d",&i);
  size = find_gp(root, i);
  if (size < 0)
    printf("No grandparent for element %d",i);
  else
    printf("Given element's grand parent is :%d", size);
  printf("\n");
  return 0;
}
