/*
 * Maximize Score After N Operations
 * You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
 *In the ith operation (1-indexed), you will:
 *Choose two elements, x and y.
 *Receive a score of i * gcd(x, y).
 *Remove x and y from nums.
 *Return the maximum score you can receive after performing n operations.
 *The function gcd(x, y) is the greatest common divisor of x and y.
 */

/* Example 1:
 *Input: nums = [1,2]
 *Output: 1
 *Explanation: The optimal choice of operations is:
 *(1 * gcd(1, 2)) = 1

 *Example 2:
 *Input: nums = [3,4,6,8]
 *Output: 11
 *Explanation: The optimal choice of operations is:
 *(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

 *Example 3:

 *Input: nums = [1,2,3,4,5,6]
 *Output: 14
 *Explanation: The optimal choice of operations is:
 *(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 */

#include <stdio.h>
#include <stdlib.h>

#define _HASHSIZE    5000
#define _HASHA       0x811c9dc5UL
#define _HASHB       0x01000193UL

static int HASHARRAY[_HASHSIZE];

#define HASH(arr,l,s)                do {       \
    int ll = l, * a = arr;                      \
    *s = _HASHA;                                \
    while(ll--)                                 \
      *s = ( *s ^ *a++ ) * _HASHB;              \
    *s = *s % _HASHSIZE;                        \
  }                                             \
  while(0)

#define PRINTA(arr,r,l)             do {        \
    int ** i = arr,ll = l,  * j, rr;            \
    while(ll--){                                \
      rr = r;                                   \
      j = *i;                                   \
      while(rr--)                               \
        printf("%d ",*j++);                     \
      printf("\n");                             \
      i++;                                      \
    }                                           \
  }                                             \
  while(0)

#define PRINTAA(arr,l)                do {      \
    int * aaa=arr,ll=l;                         \
    printf("Array:");                           \
    while(ll--)                                 \
      printf("%d ",*aaa++);                     \
    printf("\n");                               \
  }                                             \
  while(0)


int gcd(int a, int b)
{
  int a1, b1;

  if (a <= b)
    a1 = a,b1 = b;
  else
    a1 = b, b1 = a;

  if (b1 % a1 == 0)
    return a1;

  int i = 1;
  while(i > 0){
    i = b1 % a1;
    b1 = a1;
    a1 = i;
  }
  return b1;
}

int ** combinations(int * input, int inLength, int r, int * n)
{
  int i,j,k, * indices;
  int ii,** jj;

  *n = 1, i = r, j = inLength, k = 1;
  while(i--){
    *n *= j--;
    *n /= k++;
  }

  /* Array to keep all combinations */
  int ** output = (int **)malloc( *n * sizeof(int *) );
  jj = output;


  for(i=0;i<*n;i++)
    output[i] = (int *)malloc(r * sizeof(int));

  /* indices capture combnation indices */
  indices = (int *)malloc(r * sizeof(int));

  for (i=0;i<r;i++)
    indices[i] = i;

  for (i=0;i<r;i++)
    (*jj)[i] = input[i];
  jj++;

  for(;;) {
    for(i=r-1;i>-1;i--) {
      if (indices[i] != i + inLength - r)
        break;
    }
    if (i < 0)
      return output;

    indices[i]++;
    for(j=i+1;j<r;j++)
      indices[j] = indices[j-1] + 1;

    for (ii=0;ii<r;ii++){
      (*jj)[ii] = input[indices[ii]];
    }
    jj++;
  }


  free(indices);
  indices = NULL;

}

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
      indices = NULL;
      cycles = NULL;
      return;
    }

  }

}

int **  permutations(int * arr,int length, int *l)
{
  int i,k,o;

  k = length,o=1;
  while(k)
    o *= k--;

  *l = o;

  int ** r = (int **)malloc(o * sizeof(int *));
  for (i=0;i<o;i++)
    r[i] = (int *)malloc(length * sizeof(int));

  permute(arr,r,length);

  return r;

}
/* interchange v[i] and v[j] but with 2 elements */
void swap(int v[], int i, int j)
{
  int temp1, temp2;

temp1 = v[i];
temp2 = v[i+1];

v[i] = v[j];
v[i+1] = v[j+1];

v[j] = temp1;
v[j+1] = temp2;

}

/* Our version of qsort to move two elements at once */

void qqsort(int v[], int left, int right)
{
  int i, last;
  if (left >= right )
    return; /* Do nothing if array  contains fewer than 2 elements */
  if (((left + right) / 2) % 2)
    swap(v, left, ((left+right) / 2) - 1 );
  else
    swap(v, left, ((left+right) / 2) );

  last = left;
  for(i = left + 2; i <= right; i+=2)
    if (v[i] < v[left])
    {
      last += 2;
      swap(v,last,i);
    }
  swap(v,left,last);
  qqsort(v, left, last-2);
  qqsort(v, last+2, right);
}

void uniquePairs(int ** comb1, int *nums, int l, int ll, int * memo, int n, int m)
{
  int mask,i,j,isVal,hash, * tup;
  if (l == 1) {
    mask = 0xFFFF;
    memo[ll-2] = comb[m][ll-2] > comb[m][ll-1] ? comb[m][ll-2] : comb[m][ll-1];
    memo[ll-1] = comb[m][ll-2] > comb[m][ll-1] ? comb[m][ll-1] : comb[m][ll-2];

    for (i=0;i<ll;i++) {
      if (mask & (1 << memo[i]))
        mask ^= (1<<memo[i]);
      else{
        isVal = 0;
        break;
      }
      if (isVal){
        /* sort the built array according to even places */
        qqsort(memo,0,ll-2);
        HASH(memo,ll,&hash);
        if (!(HASHARRAY[hash])) {
          HASHARRAY[hash] = 1;
          for (j=0;j<ll;j++)
            comb1[n][j] = memo[j];
          n++;

        }

}

}
}
  else {
    int ** comb;
    int * rem, * aa;
    comb = combinations(nums, ll, 2, &m);

    for (i=0;i<m;i++) {
      tup = comb[i];
      rem = (int *)malloc((l-2)*sizeof(int));
      aa = rem;
      for (j=0;j<2*l;j++)
        if (nums[j] != tup[0] || nums[j] != tup[1])
          *aa++ = nums[j];
      if (l == ll) {
        memo[0] = tup[0];
        memo[1] = tup[1];
        uniquePairs(comb1, rem, l - 1, ll, memo, n, m);
}
      else {


}
}

}
}



int maxScore(int * nums, int numSize)
{
  int i,j,k,max,iL;
  int ii, ** comb2A;
  int m,n,o;
  int * a, *aa;
  int l = ((numSize * (numSize - 1)) / 2);
  unsigned int hash, tmpHash;



  for(i=0;i<l;i++)
    comb[i] = (int *)malloc(2 * sizeof(int));

  /* Array to store valid the double combinations */
  i = numSize, m =1;
  while(i>1) {
    m *= i - 1;
    i -= 2;
  }

  int ** comb1 = (int **)malloc(m * sizeof(int *));
  for(i=0;i<n;i++)
    comb1[i] = (int *)malloc(numSize * sizeof(int));



  /* Fill doubles array */
  for (i=0,k=0;i<numSize;i++){
    for (j=i+1;j<numSize;j++){
      comb[k][0] = i;
      comb[k][1] = j;
      k++;
    }
  }

  /* Fill unique Pairs */
  uniquePairs(comb,comb1,numSize << 1, numSize << 1,memo)
  /* /\* Fill combinations of double array *\/ */
  /* combinations(comb, comb1, l,2,numSize); */

  /* /\* Keep valid indices only *\/ */
  /* unsigned int boolA; */
  /* unsigned char isValid; */
  /* a = comb2; */
  /* j = 0; */
  /* for (i=0;i<n;i++){ */
  /*   boolA = 0xFFFF; */
  /*   isValid = 1; */
  /*   aa = comb1[i]; */

  /*   for(j=0;j<numSize;j++) */
  /*     /\* chek if bit is on *\/ */
  /*     if (boolA & (1 << aa[j])) */
  /*       /\* turn it off *\/ */
  /*       boolA ^= (1<<aa[j]); */
  /*     else */
  /*       isValid = 0; */
  /*   if (isValid) */
  /*     *a++ =i; */
  /*   } */

  /* Calculate max GCD */
  max = 0;

  /* Keep track of all permutations of indices */
  int * indices = (int *)malloc((numSize >> 1) * sizeof(int));
  for (i=0;i<numSize>>1;i++)
    indices[i] = i;
  int ** allIndices = permutations(indices, numSize >> 1, &iL);


  for (i = 0;i<m;i++) {
    a = comb1[comb2[i]];
    for (ii=0;ii<iL;ii++) {
      k = 0;
      /* PRINTAA(allIndices[ii],numSize >> 1); */
      /* PRINTAA(a,numSize); */
      for (j=0;j<numSize >> 1;j++) {
        k += (allIndices[ii][j] + 1) * gcd(nums[a[j*2+0]],nums[a[j*2+1]]);
      }
      /* printf("k is %d\n",k); */
      max = (max > k) ? max:k;

    }

  }


  /* PRINTA(comb, 2, l); */
  /* printf("----------------------\n"); */
  /* PRINTA(comb1,numSize,n); */

  free(comb2);
  for(i=0;i<n;i++)
    free(comb1[i]);
  free(comb1);

  for(i=0;i<l;i++)
    free(comb[i]);
  free(comb);

  for (i=0;i<iL;i++)
    free(allIndices[i]);
  free(allIndices);
  free(indices);

  comb = NULL;
  comb1 = NULL;
  comb2 = NULL;
  allIndices = NULL;
  indices = NULL;

  return max;

}

int main(int argc, char *argv[])
{
  int a,b;

  /* a = 1,b=2; */
  /* printf("GCD of %d and %d is %d\n",a,b,gcd(a,b)); */
  /* printf("==========================\n"); */

  /* a = 3,b=6; */
  /* printf("GCD of %d and %d is %d\n",a,b,gcd(a,b)); */
  /* printf("==========================\n"); */

  /* a = 3,b=7; */
  /* printf("GCD of %d and %d is %d\n",a,b,gcd(a,b)); */
  /* printf("==========================\n"); */

  /* a = 15,b=20; */
  /* printf("GCD of %d and %d is %d\n",a,b,gcd(a,b)); */
  /* printf("==========================\n"); */


  int nums1[]={3,4,6,8};
  printf("Max is %d\n",maxScore(nums1, 4));
  printf("==========================\n");

  int nums2[]={1,2,3,4,5,6};
  printf("Max is %d\n",maxScore(nums2, 6));
  printf("==========================\n");

  int nums3[]={1,2};
  printf("Max is %d\n",maxScore(nums3, 2));
  printf("==========================\n");

  int nums4[]={171651,546244,880754,412358};
  printf("Max is %d\n",maxScore(nums4, 4));
  printf("==========================\n");

  int nums5[]={370435,481435,953948,282360,691237,574616,638525,764832};
  printf("Max is %d\n",maxScore(nums5, 8));
  printf("==========================\n");

  int nums6[]={995853,58850,504472,912272,382454,597688,581332,209547};
  printf("Max is %d\n",maxScore(nums6, 8));
  printf("==========================\n");

  int nums7[]={679690,746157,308799,476790,736757,337644,520612,496785,119738,24783};
  printf("Max is %d\n",maxScore(nums7, 10));
  printf("==========================\n");

  return 0;
}
