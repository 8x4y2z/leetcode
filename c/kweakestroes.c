#include <stdio.h>
#include <stdlib.h>

typedef struct Elem{
  int index;
  int *col;
  int colsize;
  unsigned long addr;
} Elem;

int compareCol(int *, int *, int);
int compare(Elem **, Elem **);



int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
  int *res,q;
  *returnSize = k;

  res = (int *)malloc(matSize*sizeof(int));
  Elem **elemA = (Elem **)malloc(matSize*sizeof(Elem *));

  for(q = 0; q<matSize;q++)
  {
    Elem *elem = (Elem *)malloc(sizeof(Elem));
    elem->index = q;
    elem->col = mat[q];
    elem->addr = (unsigned long)mat[q];
    elem->colsize = *matColSize;
    elemA[q] = elem;
  }
  qsort(elemA, matSize, sizeof(Elem *), (int (*)(const void *, const void *))compare);

  for(q=0;q<matSize;res[q]=elemA[q]->index,q++);
  return res;
}

int compare(Elem **a, Elem **b)
{
  int foo,bar;
  int res = compareCol((*a)->col, (*b)->col, (*a)->colsize);
  if (res == 0)
    return (*a)->addr - (*b)->addr;
  return res;
}

int compareCol(int *a, int *b, int colSize)
{
  int foo,bar;
  while(colSize-- && (*a++ == *b++))
    ;
  /* if (colSize != -1) */
  --a,--b;
  if(*a==1 && *b == 0)
    return 1;
  else if (*a==0 && *b == 1)
    return -1;
  else
    return 0;
}


void printArr(int *arr, int k)
{
  while(k-- )
    printf("%d--",*arr++);
  printf("\n");
}

int main()
{
  int *rarr, returnSize,k,matSize, i;

  int matColSize[] = {5,5,5,5,5};
  matSize = 5;
  int mat[][5] = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
  int *ma[matSize];
  for(i=0;i<matSize;++i)
    ma[i] = mat[i];
  k = 3;
  rarr = kWeakestRows(ma, matSize, matColSize, k, &returnSize);
  printArr(rarr, matSize);
  printf("---------------------\n");

  int matColSize1[] = {4,4,4,4};
  matSize = 4;
  int mat1[][4] = {{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}};
  int *ma1[matSize];
  for(i=0;i<matSize;++i)
    ma1[i] = mat1[i];
  k = 2;
  rarr = kWeakestRows(ma1, matSize, matColSize1, k, &returnSize);
  printArr(rarr, matSize);
  printf("---------------------\n");
  return 0;
}
