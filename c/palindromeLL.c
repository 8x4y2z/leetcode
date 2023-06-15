#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

int isPalindrome(struct ListNode *head)
{
  struct ListNode *cur = head,*tmp,*prev = NULL;
  int l = 1, m;
  /* find length */
  for(;(head = head->next);++l)
    ;
  head = cur; /* reset head */

  if (l == 1)
    return 1;
  else if (l == 2)
    return head->val == head->next->val;

  m = l/2; /* mid-point */

  /* printf("l is %d\n",l); */
  /* printf("m is %d\n",m); */

  while(m--) head = head->next; /* move to mid */
  /* head = head->next; /\* move 1 more *\/ */

  /* reverse list from mid-point */
  while(head){
    tmp = head->next;
    head->next = prev;
    prev = head;
    head = tmp;
  }
  m = l/2; /* reset mid-point */

  if (m == 1)
    return cur->val == prev->val;

  /* if (even) --m; */

  /* Now compare */
  while(m-- && (cur->val == prev->val)){
    cur = cur->next;
    prev = prev->next;

  }
  return !(m+1);
}
  /* Additional check for even */
  /* switch (even) { */
  /*   case 0: */
  /*     return !(m+1); */
  /*   default: */
  /*     return !(m+1) && (cur->val == cur->next->val); */
  /* } */
/* } */

struct ListNode *add_front(struct ListNode *head, int val)
{
  struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->next = head;
  node->val = val;
  return node;

}

void print(struct ListNode *node)
{
  do printf("%d--",node->val);
  while((node=node->next));
  printf("\n");
}


int main() {
  int result;
  struct ListNode l1 = {1,NULL},*pl1 = &l1;
  pl1 = add_front(pl1,'a');
  pl1 = add_front(pl1,'b');
  pl1 = add_front(pl1,'c');
  pl1 = add_front(pl1,'d');
  pl1 = add_front(pl1,'e');
  print(pl1);
  result = isPalindrome(pl1);
  printf("list is palindrome %d\n",result);

  printf("-----------------------\n");

  l1.val = 'a';
  l1.next = NULL;
  pl1 = &l1;
  pl1 = add_front(pl1,'b');
  pl1 = add_front(pl1,'c');
  pl1 = add_front(pl1,'d');
  pl1 = add_front(pl1,'e');

  pl1 = add_front(pl1,'e');
  pl1 = add_front(pl1,'d');
  pl1 = add_front(pl1,'c');
  pl1 = add_front(pl1,'b');
  pl1 = add_front(pl1,'a');
  print(pl1);
  result = isPalindrome(pl1);
  printf("list is palindrome %d\n ",result);

  printf("-----------------------\n");

  l1.val = 1;
  l1.next = NULL;
  pl1 = &l1;
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,1);

  print(pl1);
  result = isPalindrome(pl1);
  printf("list is palindrome %d\n ",result);

  printf("-----------------------\n");

  l1.val = 1;
  l1.next = NULL;
  pl1 = &l1;
  pl1 = add_front(pl1,1);
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,1);
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,2);

  print(pl1);
  result = isPalindrome(pl1);
  printf("list is palindrome %d\n ",result);

  printf("-----------------------\n");

  l1.val = 1;
  l1.next = NULL;
  pl1 = &l1;
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,1);
  pl1 = add_front(pl1,1);

  print(pl1);
  result = isPalindrome(pl1);
  printf("list is palindrome %d\n ",result);

  printf("-----------------------\n");

  l1.val = 2;
  l1.next = NULL;
  pl1 = &l1;
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,1);
  pl1 = add_front(pl1,1);
  pl1 = add_front(pl1,2);
  pl1 = add_front(pl1,2);

  print(pl1);
  result = isPalindrome(pl1);
  printf("list is palindrome %d\n ",result);

  printf("-----------------------\n");

    /* print("-"*80) */

    /* ll = LinkedList("a") */
    /* ll.add_front("b") */
    /* ll.add_front("c") */
    /* ll.add_front("d") */
    /* ll.add_front("e") */
    /* ll.add_front("f") */
    /* ll.add_front("e") */
    /* ll.add_front("d") */
    /* ll.add_front("c") */
    /* ll.add_front("b") */
    /* ll.add_front("a") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("a") */
    /* ll.add_front("b") */
    /* ll.add_front("a") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("a") */
    /* ll.add_front("b") */
    /* ll.add_front("b") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("a") */
    /* ll.add_front("b") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("b") */
    /* ll.add_front("b") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("b") */
    /* ll.add_front("b") */
    /* ll.add_front("a") */
    /* ll.add_front("a") */
    /* ll.add_front("b") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("b") */
    /* ll.add_front("a") */
    /* ll.add_front("a") */
    /* ll.add_front("b") */
    /* ll.add_front("b") */
    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList("b") */
    /* ll.add_front("b") */
    /* ll.add_front("a") */
    /* ll.add_front("b") */

    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList(1) */
    /* ll.add_front(0) */
    /* ll.add_front(1) */
    /* ll.add_front(1) */

    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

    /* print("-"*80) */

    /* ll = LinkedList(1) */
    /* ll.add_front(1) */
    /* ll.add_front(2) */
    /* ll.add_front(1) */
    /* ll.add_front(2) */
    /* ll.add_front(2) */

    /* print(ll) */
    /* result = Solution().isPalindrome(ll.frontNode()) */
    /* print("list is palindrome ",result) */

  return 0;

}
