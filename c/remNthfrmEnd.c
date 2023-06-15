/*
 * Given the head of a linked list,
 * remove the nth node from the end of the list and return its head.
 * */

#include <stdio.h>
#include <stdlib.h>

#define PRINT(a)     do {\
    if(a == NULL)        \
      printf("-\n");     \
    ListNode *ccc =a;    \
    while((ccc) != NULL) \
      printf("%d--",(ccc)->val),(ccc) = (ccc)->next;\
    printf("\n");                                   \
  } while(0)

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode ListNode ;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
  ListNode *p=head,*q;
  int l,i;
  for(q=head,l=0;q->next != NULL;q=q->next,l++)
    ;
  if (l == 0)
    return NULL;
  if (l-n == -1) {
    head = head->next;
    return head;
  }
  /* if (l == 1){ */
  /*   if (n == 2) */
  /*     head = head->next; */
  /*   else if (n==1) */
  /*     head->next = NULL; */
  /*   return head; */
  /* } */

  for(i=0;i < l-n;i++,p=p->next)
    ;
  q = p->next;
  p->next = q->next;
  return head;

}

ListNode *addfrmArr(int *a, int l)
{
  ListNode *p = NULL,*q;
  int *aa, ll;
  for(ll=0,aa = a;ll<l-1;ll++,aa++)
    ;
  for(ll=0;ll<l;aa--,ll++){
    q = p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p->val = *aa;
    p->next = q;

  }
  return p;
}


int main()
{

  ListNode *head;
  int n;

  int arr[] = {1,2,3,4,5};
  head = addfrmArr(arr,sizeof(arr)/sizeof(arr[0]));
  n = 2;
  PRINT(head);
  head = removeNthFromEnd(head,n);
  PRINT(head);
  printf("-------------------\n");

  int arr1[] = {1};
  head = addfrmArr(arr1,sizeof(arr1)/sizeof(arr1[0]));
  n = 1;
  PRINT(head);
  head = removeNthFromEnd(head,n);
  PRINT(head);
  printf("-------------------\n");

  int arr2[] = {1,2};
  head = addfrmArr(arr2,sizeof(arr2)/sizeof(arr2[0]));
  n = 1;
  PRINT(head);
  head = removeNthFromEnd(head,n);
  PRINT(head);
  printf("-------------------\n");

  int arr3[] = {1,2};
  head = addfrmArr(arr3,sizeof(arr3)/sizeof(arr3[0]));
  n = 2;
  PRINT(head);
  head = removeNthFromEnd(head,n);
  PRINT(head);
  printf("-------------------\n");

  int arr4[] = {1,2,3};
  head = addfrmArr(arr4,sizeof(arr4)/sizeof(arr4[0]));
  n = 3;
  PRINT(head);
  head = removeNthFromEnd(head,n);
  PRINT(head);
  printf("-------------------\n");

  return 0;
}
