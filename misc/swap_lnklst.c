/*Problem: Given a singly linked list, swap l'th node from beginning with kth node 
from end. Swapping of data is not allowed, only pointers should be changed
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  int KEY;
  struct node *NEXT;
}*start, *temp;

struct node* addnode (struct node *current, int t){
  if (current == NULL){
    current = malloc(sizeof (start));
    current->KEY = t;
    current->NEXT = NULL;
  }
  else{
    temp = NULL;
    temp = malloc(sizeof (start));
    temp->KEY = t;
    temp->NEXT = current;
    current = temp;
  }
  return (current);
}

void traversal(struct node *current){
  if (current == NULL)
    return;
  printf("%d\t", current->KEY);
  traversal(current->NEXT);
}
/* swap_k function we swap with the pointers of 
temp1(k'th node) & temp2 (n - k)'th node
the case when k = 0 is an exception and is 
a bit tricky
First the pointers of parents of temp1 and temp2 are swapped (for k = 0 temp1 has no parent)
 */
struct node* swap_k(struct node *current, int k){
  int i, l;
  temp = current;
  struct node *temp1;
  struct node *temp2;
  struct node *tmp;

  if (k == 0)                   //if k == 1, i.e in case k = 1 ,we do not have to reset pointer
    temp1 = temp;                //of start

  for (i = 0; temp != NULL; temp = temp->NEXT, i++)
    if (i == (k - 1))
      temp1 = temp;
  l = i - 1;

  if (l < k){
    error ("%d > length of linked list", k);
    return NULL;
  }
  l =  l - k;
  temp = current;
  for (i = 0; i < l -1; temp = temp->NEXT, i++);
  //swapping the pointers of next's of k-1 & l-k-1
  temp2 = temp;

  tmp = temp1->NEXT;
  if (k != 0){
    temp1->NEXT = temp2->NEXT;
    temp2->NEXT = tmp;
  }
  else{
    tmp = temp2->NEXT;
    temp2->NEXT = temp1;
  }
  //moving to k'th & l-k'th terms
  /*It's a bit tricky or i think i made it complex here
basically when k != 0 : parent1->NEXT = parent2->NEXT & parent2->NEXT = parent1->NEXT
then we move to temp1 & temp2 (but by orginal concept temp2 = parent1->NEXT ...
& in the case for k = 0, since root has no parent we store root's next in temp
and then we swap it with temp2(conceptual)->NEXT 
   */
  if (k != 0){
    temp1 = temp1->NEXT;
    temp2 = temp2->NEXT;
  //swapping the pointers of next's of k'th & l-k'th terms
    tmp = temp1->NEXT;
    temp1->NEXT = temp2->NEXT;
    temp2->NEXT = tmp;
  }
  else{
    tmp->NEXT = temp1->NEXT;
    temp1->NEXT = NULL;
    current = tmp;
  }

  return (current);;
}
int main(){
  int i, size = 9;
  int t[] = {12, 42, 55, 71, 10, 27, 97, 85, 29};
  start = NULL;
  for (i = 0; i < size; i++)
    start = addnode(start, t[i]);
  printf("Before swapping\n");
  traversal(start);
  printf("\nEnter k(>0 & < %d): ", size);
  scanf("%d", &i);
  start = swap_k(start, i-1);
  printf("After swapping\n");
  traversal(start);
  printf("\n");
  return 0;
}
