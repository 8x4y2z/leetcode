#include <stdio.h>

int minMax(int *,int,int);

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
  int accountsSum[accountsSize], i, j, sum;
  for(i=0;i<accountsSize;i++){
    sum = 0;
    for(j=0;j<*accountsColSize;sum += accounts[i][j++])
      ;
    accountsSum[i] = sum;
}
  return minMax(accountsSum,0,accountsSize-1);
}

int minMax(int *arr,int start,int end)
{
  if (start == end)
    return arr[start];
  else if (start+1 == end)
  {
    if(arr[start]<arr[end])
      return arr[end];
    else
      return arr[start];
  }
  else {
    int mid = start + (end-start)/2;
    int left = minMax(arr,start,mid);
    int right = minMax(arr, mid + 1, end);
    if (left > right)
      return left;
    else
      return right;
  }


}

int main()
{
  int accountsSize,accountsColSize, **accounts,q,res;

  accountsSize = 2;
  accountsColSize = 3;
  int accountsArray[][3] = {{1,2,3},{3,2,1}};
  int *accounts_p[accountsSize];
  for(q=0;q<accountsSize;q++)
    accounts_p[q] = accountsArray[q];
  accounts = accounts_p;
  res = maximumWealth(accounts_p, accountsSize,&accountsColSize);
  printf("Max value is %d\n",res);


  accountsSize = 3;
  accountsColSize = 2;
  int accountsArray1[][2] = {{1,5},{7,3},{3,5}};
  int *accounts_p1[accountsSize];
  for(q=0;q<accountsSize;q++)
    accounts_p1[q] = accountsArray1[q];
  accounts = accounts_p1;
  res = maximumWealth(accounts, accountsSize,&accountsColSize);
  printf("Max value is %d\n",res);



  return 0;
}
