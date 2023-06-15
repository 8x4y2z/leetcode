#include <stdio.h>
#include <stdlib.h>

void myItoa(char *buf,int n)
{
  sprintf(buf, "%d",n);
}

void fizBuz3(char *buf,int i)
{
  sprintf(buf,"%s","Fizz");
}

void fizBuz5(char *buf,int i)
{
  sprintf(buf,"%s","Buzz");
}

void fizBuz15(char *buf,int i)
{
  sprintf(buf,"%s","FizzBuzz");
}

static void (*lookup[15])(char *,int) = {fizBuz15,
  myItoa,
  myItoa,
  fizBuz3,
  myItoa,
  fizBuz5,
  fizBuz3,
  myItoa,
  myItoa,
  fizBuz3,
  fizBuz5,
  myItoa,
  fizBuz3,
  myItoa,
  myItoa
};


char **fizzBuzz(int n,int *size)
{
  int i;
  char **arr, *lookupBufs[n];

  *size = n;

  arr = (char **)malloc(n*sizeof(char *));

  /* Create lookup array */
  for(i=0;i<n;i++ ){
    char *buff = (char *)malloc(15*sizeof(char)); /* assume ind char is 15 width */
    lookupBufs[i] = buff;
  }

  for(;n;arr[n-1] = lookupBufs[n-1],n--)
    lookup[n%15](lookupBufs[n-1],n);
  return arr;


}


void print(char **arr,int n)
{
  while(n--)
    printf("%s---",*arr++);
  printf("\n");
}

int main()
{
  int n, size;

  n = 3;
  /* size = (n*15*sizeof(char)); */
  print(fizzBuzz(n,&size),n);
  printf("-------------------\n");

  n = 5;
  /* size = (n*15*sizeof(char)); */
  print(fizzBuzz(n,&size),n);
  printf("-------------------\n");

  n = 15;
  /* size = (n*15*sizeof(char)); */
  print(fizzBuzz(n,&size),n);
  printf("-------------------\n");

  n = 100;
  /* size = (n*15*sizeof(char)); */
  print(fizzBuzz(n,&size),n);
  printf("-------------------\n");
}
