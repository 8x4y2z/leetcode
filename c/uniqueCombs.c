#include <stdio.h>
#include <stdlib.h>

#define PRINTAA(arr,l,ll)      do {             \
    int m,n=ll,**a=arr,*aa;                   \
    while(n--){                                 \
      aa = *a++;                                \
      m = l;                                    \
      while(m--)                                \
        printf("%d ",*aa++);                    \
      printf("\n");                             \
    }                                           \
  }                                             \
  while(0)

#define PRINTA(arr,l)                do {       \
    int * a=arr,ll=l;                           \
    printf("Array:");                           \
    while(ll--)                                 \
      printf("%d ",*a++);                       \
    printf("\n");                               \
    }                                           \
  while(0)


void makeUnique(int ** ptrs,  int ** r, int n, int c )
{
  int i;
  if (c == n)

  for(i=0;i<n;i++){

}
}


void uniqueC(int * arr, int length)
{
  int i,j,k,l;

  int **ptrs = (int **)malloc((length >> 1) * sizeof(int*));


  i = length, l = 1;
  while(i>1) {
    l *= i - 1;
    i -= 2;
  }

  int ** r = (int **)malloc(l * sizeof(int *));
  for (i=0;i<l;i++)
    r[i] = (int *)malloc(2 * sizeof(int));

  for(i = 0;i<length >> 1;i++)
    ptrs[i] = &arr[i << 1];

  PRINTAA(r, 2, l);

  for (i=0;i<l;i++)
    free(r[i]);
  free(r);
  free(ptrs);
}


int main(int argc, char *argv[])
{
  int n;

  int a1[]={1,2,3,4,5};
  n = 5;
  uniqueC(a1,n);
  return 0;
}
