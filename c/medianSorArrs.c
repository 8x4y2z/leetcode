/*
* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
* The overall run time complexity should be O(log (m+n)).
*/

#include <stdio.h>


#define PRINT(a)         (printf("Median is %f\n----------------------------------\n",a))

void printa(int *, int);

double findMedianSortedArraysS(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int i=0,combined[nums1Size+nums2Size],cl = (nums1Size+nums2Size), mp = cl/2, *tmp = combined;
  while(nums1Size > 0 && nums2Size > 0 && i++ <= mp)
    if(*nums1 <= *nums2)
      *tmp++ = *nums1++,nums1Size--;
    else
      *tmp++ = *nums2++,nums2Size--;

  while(nums1Size-- && i++ <= mp)
    *tmp++ = *nums1++;

  while (nums2Size-- && i++ <= mp)
    *tmp++ = *nums2++;

  printa(combined, cl);
  return cl%2 ? combined[mp] : ((double)(combined[mp -1] + combined[mp])) / 2;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int i=0,*p = nums1, *q = nums1, cl = (nums1Size+nums2Size), mp = cl/2;
  while(nums1Size > 0 && nums2Size > 0 && i++ <= mp)
    if(*nums1 <= *nums2)
      q=p,p = nums1++,nums1Size--;
    else
      q=p,p = nums2++,nums2Size--;

  while(nums1Size-- && i++ <= mp)
    q=p, p = nums1++;

  while (nums2Size-- && i++ <= mp)
    q=p, p = nums2++;

  return cl%2 ? *p : ((double)(*p + *q)) / 2;
}


void printa(int * a, int l)
{
  while(l--)
    printf("%d--",*a++);
  printf("\n");
}


int main()
{
  int nums1[] = {1,3};
  int nums2[] = {2};
  PRINT(findMedianSortedArrays(nums1, 2, nums2, 1));

  int numsa[] = {1,2};
  int numsb[] = {3,4};
  PRINT(findMedianSortedArrays(numsa, 2, numsb, 2));

  return 0;
}

