#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
} *root,*temp;                         //root corresponds to the root node in the list

struct node* attachnode(struct node *current,int t){            //this fn. attaches new nodes
  if (current == NULL){
    temp = (struct node *) malloc(sizeof(root));
    temp->data = t;
    temp->next = NULL;
    current = temp;
    return (current);
  }
  else if (current->next == NULL){
    temp =(struct node *) malloc(sizeof (root));
    temp->data = t;
    temp->next = NULL;
    current->next =temp;
  }
  else
    attachnode(current->next,t);
  return(current);
}
void displist(struct node *current){
  if (current !=NULL){
    printf("%d\t",current->data);
    displist(current->next);
  }
  return;
}
int traversal (struct node *current ,int t){          //this function traverses through the list to see if t is present in the list
  int key =0;
  if (current ==NULL)
    return 0;
  if(current->data == t) 
    return 1;
  else 
    key =traversal(current->next ,t);
  return (key);
}
int main(){
  int y,ar[10]={1 ,2 ,2 ,5 ,6 ,32 ,21 ,54 ,78 ,41 };
  root = NULL;
  printf("The linked list is \n");
  root =attachnode(root,ar[0]);
  for(y = 1; y < 10; y++)
    attachnode(root,ar[y]);
  displist(root);
  printf("\nEnter a no. to be searched in the list:");
  scanf("%d",&y);
  if (traversal(root ,y))
    printf("\n%d is present in list\n",y);
  else
    printf("\n%d is not present in list\n",y);
  return 0;
}
