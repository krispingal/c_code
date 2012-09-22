//this program is tocreate a binary search tree
#include<stdio.h>
#include<stdlib.h>

struct bstree{                                 
  int data;
  struct bstree *right;
  struct bstree *left;

}*root;

struct bstree* insert (struct bstree *current , int dat){
  if ( current == NULL){
    current = malloc( sizeof(struct bstree));
    current->data = dat;
    current->right = NULL;
    current->left = NULL;
    printf("\n  Allocating %d to terminal node",current->data);
    }
  else if ( current->data < dat){
    printf("\nputting %d to right of %d",dat,current->data);
    current->right = insert(current->right,dat);    
    }
  else{
    printf("\nputting %d to left of %d",dat,current->data);
    current->left =insert(current->left,dat);
    }
  return (current);
}

void inorder(struct bstree *current ){
  if (current == NULL)
    return;
  inorder(current->left);
  printf("%d\t",current->data);
  inorder(current->right);
  return;
}

void preorder(struct bstree *current){
  if (current == NULL)
    return;
  printf("%d \t",current->data);
  preorder(current->left);
  preorder(current->right);
  return;
}
void postorder(struct bstree *current){
  if (current == NULL)
    return;
  postorder(current->left);
  postorder(current->right);
  printf("%d \t",current->data);
  return;
}
int findgp(struct bstree *current, int t){
  int key= -999;
  if(current ==NULL){
    printf("\nno. not present in bst"); 
    return(-999);
  }
  if(current->data ==t)
    return(-26);
    else if(current->data < t)
      key = findgp(current->right , t);
    else
      key = findgp(current->left , t);
  if (key == -26)
    return(-25);
  else if (key == -25)
    return (current->data);
  else
    return(key);
}
int main(){
  int k, i ,ar[10];
  root = NULL;
  printf("Enter any +ve numbers\n");
  for (i =0;i < 10; i++)
    scanf("%d",&ar[i]);

  //the next section of code will invoke bstree fn. which will create the binary search tree
  for( i = 0;i < 10; i++){
    k = ar[i];
    root = insert(root,k);
  }
  printf("\n");
  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
  printf("\nEnter a no. to be searched in the tree and to find it's grandparent");
  scanf("%d",&i);
  k = i;
  i=findgp(root,i);
  if(i < 0)
    printf("\n%d has no gp in the bst",k);
  else
    printf("\n%d has %d as it's gp",k,i);
  return 0;
}
