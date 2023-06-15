/*
* Write a function to find the longest common prefix string amongst an array of strings
* If there is no common prefix, return an empty string ""
* */

#include <stdio.h>
#include <stdlib.h>

#define PRINT(a)                      (printf("Longest Common prefix is %s\n-----------------\n",a))

char * longestCommonPrefix(char ** strs, int strsSize)
{
  char *str = (char *)malloc(256*sizeof(char)), *strr = str;
  char *ptrs[strsSize], c,cc;
  int i, flag=1;

  for (i =0;i<strsSize;i++)
    ptrs[i] = strs[i];

  while((c = cc = *ptrs[0]++)) {
  for (i = 1; i<strsSize; i++)
    if ((cc = *ptrs[i]++) != c || cc == '\0')
      break;
  if (i == strsSize)
    *strr++ = c;
  else
    break;
  }
  *strr = '\0';
  return str;
}

int main()
{
  char *strs[256] = {"flower","flow","flight"};
  PRINT(longestCommonPrefix(strs, 3));

  char *strs1[256] = {"dog","racecar","car"};
  PRINT(longestCommonPrefix(strs1, 3));

  return 0;
}
