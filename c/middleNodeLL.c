#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* middleNode(struct ListNode* head){
  struct ListNode *slow=head,*fast=head;
  while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
}
  return slow;
}

struct ListNode * createLL(int n, struct ListNode *node)
{
  struct ListNode * newNode;
  if (n>0){
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = n;
    if (node)
      newNode->next = node;
    return createLL(n-1, newNode);
  }
  else
    return node;
}

void print(struct ListNode *node)
{
  do printf("%d--",node->val);
  while((node=node->next));
  printf("\n");
}

int main()
{
  struct ListNode *head, *middle;
  head = createLL(10,NULL);
  print(head);
  middle = middleNode(head);
  print(middle);
  printf("---------------------\n");

  head = createLL(9,NULL);
  print(head);
  middle = middleNode(head);
  print(middle);
  printf("---------------------\n");
  return 0;
}
