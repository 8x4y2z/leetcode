#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101

typedef struct Node {
  int num;
  int index;
  struct Node *next;
} Node;

void  addEntry(Node *[],int, int);
Node* getEntry(Node *[], int);
int hash(int);

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
  *returnSize = 2;
  int q, *res = (int *)malloc(2*sizeof(int));
  Node *hashTab[HASHSIZE] = {0};
  Node *p;
  for(q=0;q<numsSize;q++,nums++){
    if((p = getEntry(hashTab, target - *nums)) != NULL){
      res[0] = q;res[1] = p->index;
      break;
    }
    addEntry(hashTab, *nums,q);
}
  return res;
}

void  addEntry(Node *hashTable[],int number, int index)
{
  Node *node_p = (Node *)malloc(sizeof(Node));
  node_p->index = index;
  node_p->num = number;
  node_p->next = NULL;

  int key = hash(number);
  if(!hashTable[key])
    hashTable[key] = node_p;
  else
    hashTable[key]->next = node_p;

}

Node* getEntry(Node *hashTab[], int number)
{
  int key = hash(number);
  Node *node_p = hashTab[key];
  while(node_p && node_p->next){
    if (node_p->num == number)
      break;
    node_p = node_p->next;
  }
  if(node_p != NULL && node_p->num != number)
    return NULL;
  return node_p;

}

int hash(int number){
  return abs(number)%HASHSIZE;
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

  /* int nums[] = {2,7,11,15}; */
  /* numSize = 4; */
  /* target = 9; */
  /* ret = twoSum(nums, numSize, target, &returnSize); */
  /* printArr(ret,returnSize); */

  /* printf("--------------\n"); */

  /* int nums1[] = {3,2,4}; */
  /* numSize = 3; */
  /* target = 6; */
  /* ret = twoSum(nums1, numSize, target, &returnSize); */
  /* printArr(ret,returnSize); */

  /* printf("--------------\n"); */

  /* int nums2[] = {3,3}; */
  /* numSize = 2; */
  /* target = 6; */
  /* ret = twoSum(nums2, numSize, target, &returnSize); */
  /* printArr(ret,returnSize); */

  /* printf("--------------\n"); */

  /* int nums3[] = {0,4,3,0}; */
  /* numSize = 4; */
  /* target = 0; */
  /* ret = twoSum(nums3, numSize, target, &returnSize); */
  /* printArr(ret,returnSize); */

  /* printf("--------------\n"); */

  /* int nums4[] = {-3,4,3,90}; */
  /* numSize = 4; */
  /* target = 0; */
  /* ret = twoSum(nums4, numSize, target, &returnSize); */
  /* printArr(ret,returnSize); */

  /* printf("--------------\n"); */

  int nums5[] = {3,2,95,4,-3};
  numSize = 5;
  target = 92;
  ret = twoSum(nums5, numSize, target, &returnSize);
  printArr(ret,returnSize);

  return 0;
}
