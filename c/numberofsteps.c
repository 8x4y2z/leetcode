#include <stdio.h>

int numberOfSteps(int num)
{
  int steps=0;
  while(num){
    ++steps;
    if(num%2)
      --num;
    else
      num /= 2;
  }
  return steps;
}


int main()
{
  int n;

  n=14;
  printf("Nsteps = %d\n",numberOfSteps(n));
  printf("------------\n");

  n=8;
  printf("Nsteps = %d\n",numberOfSteps(n));
  printf("------------\n");

  n=123;
  printf("Nsteps = %d\n",numberOfSteps(n));
  printf("------------\n");
  return 0;
}
