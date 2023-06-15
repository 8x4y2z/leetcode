#include <stdlib.h>
#include <stdio.h>

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


void permute(int *arr, int ** store,int n)
{
  int i,j,k;
  int ** myA = store;
  int * indices = (int *) malloc(n * sizeof(int));
  int * cycles = (int *) malloc(n *sizeof(int));
  /* int c = 0; */
  for (i=0;i<n;i++)
    indices[i] = i;

  for (i=n;i>0;i--)
    cycles[n-i] = i;

  for (i=0;i<n;i++)
    (*myA)[i] = arr[indices[i]];
  myA++;
  /* c++; */

  while(n) {
    for (i=n-1;i>-1;i--){
      cycles[i]--;
      if (!cycles[i]){
        k = indices[i];
        for (j=i;j<n-1;j++)
          indices[j] = indices[j+1];
        indices[n-1] = k;
        cycles[i] = n - i;
        /* PRINTA(indices, n); */
      } else {
        j = cycles[i];
        k = indices[i];
        indices[i] = indices[n-j];
        indices[n-j] = k;

        /* printf("-----\n"); */
        /* PRINTA(indices, n); */
        /* printf("------------------------\n"); */
        for(k=0;k<n;k++)
          (*myA)[k] = arr[indices[k]];
        myA++;
        /* c++; */
        /* printf("c==%d\n",c); */
        break;
      }
    }
    if (i < 0) {
      free(indices);
      free(cycles);
      return;
    }

  }

}

void permutation(int * arr,int length)
{
  int i,j,k,o;

  k = length,o=1;
  while(k)
    o *= k--;

  int ** r = (int **)malloc(o * sizeof(int *));
  for (i=0;i<o;i++)
    r[i] = (int *)malloc(length * sizeof(int));

  permute(arr,r,length);

  PRINTAA(r,length,o);

  for (i=0;i<o;i++)
    free(r[i]);
  free(r);
}

int main(int argc, char *argv[])
{
  int n;

  int a1[]={1,2,3,4,5};
  n = 5;
  permutation(a1,n);
  return 0;
}
