#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int number;
  struct Node *left;
  struct Node *right;
  struct Node *equal;
  int index;
} Node;

Node *addtree(Node *p, int num, int index);
Node *getNode(Node *p, int num, int index);
void treeprint(Node *p);

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
  Node *p, *pp;
  int *ret = (int *)malloc(2*sizeof(int)), *nnums = nums, q;
  *returnSize = 2;

  p = NULL;
  for(q = 0;q<numsSize;q++)
    p = addtree(p, *nums++, q);

  /* Reset */
  nums = nnums;


  for(q=0;q<numsSize;q++,nums++)
    if ((pp = getNode(p,target-*nums,q)) != NULL) {
      ret[0] = q, ret[1] = pp->index;
      break;
    }
  return ret;
}

Node *addtree(Node *p, int num, int index)
{
  int cond;
  if (p == NULL){
    p = (Node *)malloc(sizeof(Node));
    p->number = num;
    p->index = index;
    p->left=p->right=p->equal=NULL;
}
  else if ((cond = (num - p->number ))==0)
    p->equal = addtree(p->equal, num, index);
  else if (cond < 0)
    p->left = addtree(p->left, num, index);
  else
    p->right = addtree(p->right, num, index);

  return p;

}

Node *getNode(Node *p, int num, int index)
{
  if (p == NULL)
    return p;
  if(p->number < num)
    return getNode(p->right, num, index);
  else if (p->number>num)
    return getNode(p->left, num, index);
  else {
    while (p !=NULL && p->index == index)
      p = p->equal;
    return p;
  }
}

void treeprint(Node *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %d\n", p->index, p->number);
    treeprint(p->right);
  }
}

void printArr(int *arr, int tar)
{
  while(tar--)
    printf("%d--",*arr++);
  printf("\n");
}

int main()
{
  int *ret, numSize, target, returnSize;

  int nums[] = {2,7,11,15};
  numSize = 4;
  target = 9;
  ret = twoSum(nums, numSize, target, &returnSize);
  printArr(ret,returnSize);

  printf("--------------\n");

  int nums1[] = {3,2,4};
  numSize = 3;
  target = 6;
  ret = twoSum(nums1, numSize, target, &returnSize);
  printArr(ret,returnSize);

  printf("--------------\n");

  int nums2[] = {3,3};
  numSize = 2;
  target = 6;
  ret = twoSum(nums2, numSize, target, &returnSize);
  printArr(ret,returnSize);

  return 0;
}
