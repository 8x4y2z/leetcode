/*
* Given an integer array nums, return all the triplets
* [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
* */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTA(a,b)              do {                     \
      int i;                                              \
      printf("[");                                        \
      for (i =0; i<b-1; i++)                            \
        printf("%d,",a[i]);                          \
      printf("%d]",a[i]);                                \
      break;}                                     \
  while(0)


#define PRINT(a,b,c)                     do {                  \
    printf("[");                                             \
    int j;                                                        \
    for(j = 0; j<b-1;j++){                                       \
      PRINTA(a[j], c[j]);                                       \
      printf(",");                                             \
      }                                                         \
    PRINTA(a[j], c[j]);                                         \
    printf("]");                                             \
    break;                                                \
  } while(0)

#define SIZE                         1500
#define ABS(a)                          (a) < 0 ? (-a) : (a)
#define HASH(a)                      ((ABS(a)) % SIZE)

typedef struct Node {
  int num;
  int index;
  struct Node *next;
} Node;

typedef struct iNode {
  int num1;
  int num2;
  int num3;
  struct iNode *next;
} iNode;

int *getTwos(int *, int, int, int,Node *[] ,iNode *[], int *);
Node *getEntry(Node **, int);
void addEntry(Node **, int, int, int *);
int Hash1(int *arr);
int numcmp(int *, int *);
iNode *getIGN(int a, int b, int,iNode *[]);
void addIGN(int a, int b, int c, iNode *[]);

int** threeSumS(int* nums, int numsSize, int* returnSize, int **returnColumnSizes)

{

  int *a, aa, *twos, n,count=0, *threes, newSize = SIZE;
  int **final = (int **)malloc(SIZE*sizeof(int *));
  int *columnSizes = (int *)malloc(SIZE*sizeof(int));
  iNode *toIGN[SIZE] = {0};
  Node *hashtab[SIZE] = {0};
  int zeroCount = 3, uC = 0, uC1=0, uC2=0;

  for(aa=0;aa<numsSize;aa++)
    addEntry(hashtab, nums[aa],aa, &uC);

  for(aa=0;aa<numsSize;aa++){
    if (uC == 3 && uC1 == 0 && nums[aa] != 0){
      uC1 = nums[aa];
      break;
    }
  }
  for(aa=0;aa<numsSize;aa++){
    if (uC == 3 && uC1 != 0 && nums[aa] != 0 && nums[aa] != uC1){
      uC2 = nums[aa];
      break;
    }
  }

  for(a=nums,aa=0; aa < numsSize;a++,aa++) {
      if (nums[aa] == 0)
        if((zeroCount-- <= 0))
            continue;
      if (uC == 3) {
        if (uC1 != 0 && uC2 != 0 && uC1+uC2 == 0)
          if(nums[aa] == uC1 || nums[aa] == uC2)
            continue;
      }
    if ((twos = getTwos(nums, numsSize, -(*a), aa,hashtab,toIGN, &n)) != NULL){
      int *twosp = twos;
      for(;n>0;n-=2){
        threes = (int *)malloc(3*sizeof(int));
        *threes = *a;
        threes[1] = *twosp++;
        threes[2] = *twosp++;
        if (count >= newSize){
          newSize = newSize+1000*count;
          final = (int **)realloc(final,newSize*sizeof(int *));
          columnSizes = (int *)realloc(columnSizes, newSize * sizeof(int));
        }
        final[count++] = threes;
      }
      free(twos);
    }
  }
  *returnSize = count;
  aa = 0;
  while (count--)
    columnSizes[aa++] = 3;
  *returnColumnSizes = columnSizes;
  return final;
}

int *getTwos(int *orgAr, int size, int sum, int i, Node *hashtab[],iNode *toIGN[], int *n)
{
  int aa, *res = NULL;
  Node *p;
  /* Node *p; */
  *n = 0;
  /* memset(hashtab, 0, SIZE*sizeof(Node*)); */
  for(aa=0;aa<size;aa++){
    /* if (aa == i) */
    /*   continue; */
    /* printf("Sum is %d--1st is %d --aa is %d -- i is %i\n",sum,orgAr[aa], aa, i); */
    if((p=getEntry(hashtab, sum - orgAr[aa])) != NULL){
      /* printf("Sum is %d--1st is %d\n-------------------\n",sum,orgAr[aa]); */
      if(i == aa)
        continue;
      if(p->next == NULL && (i == p->index || aa == p->index))
        continue;
      for(;p != NULL && i != p->index && aa != p->index && p->num == (sum - orgAr[aa]);p=p->next){
        if ((getIGN(orgAr[i], orgAr[aa], p->num,toIGN) != NULL))
          continue;
        *n += 2;
        res = (int *)realloc(res,*n*sizeof(int));
        res[*n+0-2] = orgAr[aa];
        res[*n+1-2] = p->num;
        addIGN(orgAr[i], orgAr[aa], p->num,toIGN);
      }
    }
  }
  return res;

}

Node *getEntry(Node **hashtab, int sum)
{
  Node *p;
  if ((p = hashtab[HASH(sum)]) != NULL)
    while(p->next != NULL && p->num != sum)
      p = p->next;
  return p !=NULL && p->num == sum ? p : NULL;
}

void addEntry(Node **hashtab, int num, int ind, int *u)
{
  Node *p,*q;
  p = (Node *)malloc(sizeof(Node));
  int key = HASH(num);

  p->num = num;
  p->index = ind;
  p->next = NULL;

  /* if ((q = hashtab[key]) != NULL) */
  if ((q = hashtab[key]) != NULL){
      if (q->num == 0 && p->num == 0)
          if (q->next != NULL && q->next->num == 0)
            if (q->next->next != NULL && q->next->next->num == 0)
              return;
      if (p->num != q->num)
        *u += 1;
      p->next = q;
  }
  else
    *u += 1;
  hashtab[key] = p;
}

int Hash1(int *arr)
{
  qsort((void *)arr,3,sizeof(int), (int (*)(const void *, const void *))numcmp);
  /* PRINTA(arr,3); */
  /* printf("-------\n"); */
  return (ABS((arr[0]))*31 + ABS((arr[1]))*32 + ABS((arr[2]))*33)%SIZE;
}

int numcmp(int *aa, int *bb)
{
  return *aa > *bb ? 1 : -1;
}

iNode *getIGN(int a, int b, int c,iNode *toIGN[])
{
  iNode *q;
  int arr[3] = {a,b,c};
  int hash = Hash1(arr);
  if ((q = toIGN[hash]) != NULL)
    while((q->next != NULL) && ((q->num1 != arr[0]) || (q->num2 != arr[1]) || (q->num3 != arr[2])))
      q = q->next;
  return ((q !=NULL) && (q->num1 == arr[0]) && (q->num2 == arr[1]) && (q->num3 == arr[2])) ? q : NULL;
}

void addIGN(int a, int b, int c, iNode *toIGN[])
{
  int arr[3] = {a,b,c};
  int hash = Hash1(arr);
  iNode *p,*q;

  if ((q = toIGN[hash]) == NULL){
    p = (iNode *)malloc(sizeof(iNode));
    p->num1 = arr[0];
    p->num2 = arr[1];
    p->num3 = arr[2];
    p->next = NULL;
    toIGN[hash] = p;
  }
  else{
    if (q->num1 == arr[0] && q->num2 == arr[1] && p->num3 == arr[2] )
      return;
    p = (iNode *)malloc(sizeof(iNode));
    p->num1 = arr[0];
    p->num2 = arr[1];
    p->num3 = arr[2];
    p->next = q;
    toIGN[hash] = p;
    /* hashtab[key] = q; */
  }

}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ans_size = 32;
    int **ans = (int**)calloc(ans_size, sizeof(int*));
    *returnColumnSizes = (int*)calloc(ans_size, sizeof(int));
    *returnSize = 0;

    // sorting for using two pointer easily.
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int k = 0; k < numsSize; k++) {
        // since nums is sorted already, if nums[k] > 0, the target will always be negative.
        // Since i is always start from k + 1 and j is always start from numsSize - 1
        // which means the sume of nums[i] and nums[j] will always be positive. We will
        // never found new triplets. Therefore, we break the loop.
        if (nums[k] > 0) break;
        // skip duplicated number
        if (k > 0 && nums[k - 1] == nums[k]) continue;
        int target = 0 - nums[k];
        int i = k + 1;
        int j = numsSize - 1;
        while (i < j) {
            int sum_ij = nums[i] + nums[j];
            if (sum_ij == target) {
                if (*returnSize >= ans_size) {
                    ans_size *= 2;
                    ans = realloc(ans, sizeof(int*) * ans_size);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * ans_size);
                }
                int idx = (*returnSize)++;
                (*returnColumnSizes)[idx] = 3;
                ans[idx] = (int*)calloc(3, sizeof(int));
                ans[idx][0] = nums[i]; ans[idx][1] = nums[j]; ans[idx][2] = nums[k];

                // skip duplicated number
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;

                // when leaving from the while loops, i and j don't be moved
                // they are just compared and found they don't have the same value as next idx.
                i++;
                j--;
            } else if (sum_ij < target) {
                i++;
            } else {
                j--;
            }
        }
    }

    return ans;
}

int main()
{
  int **retArr, returnSize, *returnColSize;

  /* int nums[] = {-1,0,1,2,-1,-4}; */
  /* retArr = threeSum(nums, 6, &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  /* int nums1[] = {0,0,0,0}; */
  /* retArr = threeSum(nums1, 4, &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  /* int nums2[] = {-2,0,1,1,2}; */
  /* retArr = threeSum(nums2, 5, &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  /* int nums3[] = {-1,0,1,2,-1,-4,-2,-3,3,0,4}; */
  /* retArr = threeSum(nums3, sizeof(nums3)/sizeof(nums3[0]), &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  /* int nums4[] = {34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49}; */
  /* retArr = threeSum(nums4, sizeof(nums4)/sizeof(nums4[0]), &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  /* int nums5[] = {-1,-4,-5,2,-2,-1,-6,-10,-10,-9,2,3,2,2,-1,4,-9,-1,-4,6,3,-2,-8,-4,5,-3,-9}; */
  /* retArr = threeSum(nums5, sizeof(nums5)/sizeof(nums5[0]), &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  /* int nums6[] = {1,0,-4,3,-3,2,4,-2,2,2,3,-4,-3,-1,-5,-1,1}; */
  /* retArr = threeSum(nums6, sizeof(nums6)/sizeof(nums6[0]), &returnSize, &returnColSize); */
  /* PRINT(retArr,returnSize, returnColSize); */

  int nums7[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  retArr = threeSum(nums7, sizeof(nums7)/sizeof(nums7[0]), &returnSize, &returnColSize);
  PRINT(retArr,returnSize, returnColSize);

  return 0;

}
