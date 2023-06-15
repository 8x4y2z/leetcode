/*
*You are given an integer array height of length n.
*There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
*Find two lines that together with the x-axis form a container, such that the container contains the most water.
*Return the maximum amount of water a container can store.
*/

#include <stdio.h>


#define PRINT(a)           (printf("Max water is %d\n----------------\n",a))
#define MAX(a,b)       ((a) > (b) ? (a) : (b))
#define MIN(a,b)       ((a) > (b) ? (b) : (a))

int maxAreaS(int *height, int heightsize)
{
  int *a=height,*b, n,ar,max=0;
  for(;heightsize-- > 1;a++){
    for(b = a+1, n = heightsize;n--;b++){
      ar = MIN(*a, *b);
      max = MAX(max,(ar*(b-a)));
    }
  }
  return max;
}

int maxArea(int *height, int heightsize)
{
  int *a = height, *b = height+heightsize-1, ar, max=0;
  while (a < b) {
    if (*a < *b){
      ar = *a;
      max = MAX(max,(ar*(b-a)));
      a++;
    }
    else{
      ar = *b;
      max = MAX(max,(ar*(b-a)));
      b--;
    }
  }
  return max;
}

int main()
{
  int a0[] = {1,8,6,2,5,4,8,3,7};
  PRINT(maxArea(a0,sizeof(a0)/sizeof(a0[0])));

  int a1[] = {1,1};
  PRINT(maxArea(a1,sizeof(a1)/sizeof(a1[0])));
  return 0;
}
