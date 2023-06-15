#include <stdio.h>
#include <stdlib.h>

/*
 * Faster Appoach can be just figure out longest list first and directly mutate it
 * Instead of storing values in array
 */


struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *addTwoNumbers(ListNode *, ListNode *);

ListNode *addNode(ListNode *p,int val)
{
  ListNode *q = (ListNode *)malloc(sizeof(ListNode));
  q->val = val;
  q->next = p;
  return q;
}

void printNode(ListNode *p)
{
  for(;p != NULL;p=p->next)
    printf("%d--",p->val);
  printf("\n");
}


ListNode *addTwoNumbers(ListNode *p, ListNode *q)
{
  int i, sum,c=0,numbers[100];
  ListNode *r,*s = NULL;
  for(i=0;p != NULL && q != NULL;p=p->next,q=q->next)
  {
    sum = (p->val + q->val)+c;
    numbers[i++] = sum%10;
    c = sum/10;
  }

  for(;p != NULL;p=p->next){
    sum = p->val +c;
    numbers[i++] = sum%10;
    c = sum/10;
}

  for(;q != NULL;q=q->next){
    sum = q->val+c;
    numbers[i++] = sum%10;
    c = sum/10;
}
  while (c)
    numbers[i++] = c--;

  while((c=--i) >= 0){
    r = (ListNode *)malloc(sizeof(ListNode));
    r->val = numbers[c];
    r->next = s;
    s = r;
  }
  return r;
}

int main()
{
  ListNode *p, *q, *r;
  p = addNode(NULL,3);
  p = addNode(p,4);
  p = addNode(p,2);
  printNode(p);

  q = addNode(NULL,4);
  q = addNode(q,6);
  q = addNode(q,5);
  printNode(q);

  r = addTwoNumbers(p,q);
  printNode(r);
  printf("------------------\n");

  p = addNode(NULL,0);
  printNode(p);

  q = addNode(NULL,0);
  printNode(q);

  r = addTwoNumbers(p,q);
  printNode(r);
  printf("------------------\n");

  p = addNode(NULL,9);
  p = addNode(p,9);
  p = addNode(p,9);
  p = addNode(p,9);
  p = addNode(p,9);
  p = addNode(p,9);
  p = addNode(p,9);
  printNode(p);

  q = addNode(NULL,9);
  q = addNode(q,9);
  q = addNode(q,9);
  q = addNode(q,9);
  printNode(q);

  r = addTwoNumbers(p,q);
  printNode(r);
  printf("------------------\n");

  return 0;
}
