/*
*Given a string s, return the longest palindromic substring in s.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT(aa, ss)                        (printf("longest palindrome in %s is %s\n-----------\n",aa,ss))
#define MAX(a,b)                             ((a) >= (b) ? (a) : (b))

char * longestPalindromes(char * s)
{
  char *a1=s, *cur = s, *p,*q, *r = s;
  int max=1, i,l = 0,len;
  while(*cur++){
    for(p=a1;p<=cur;p++){

      for(q=p,i=0,l=cur-q, len = 0;i<l;i++,l--){
        if(q[i] == q[l])
          len += 2;
        else{
          len = 0;
          break;
        }
      }
      len = (i==l)? len + 1 : len;
      if(len > max)
        r = q, max = len;

    }

  }

  char *arr = (char *)malloc((max+1) * sizeof(char)), *ss = arr;
  memcpy(arr, r, max);
  /* while(max--) */
  /*   *ss++ = *r++; */
  arr[max] = '\0';
  return arr;

}

char * longestPalindrome(char * s){
    if(!s[0])
        return s;
    int length = strlen(s);
    int max_length =1;
    int max_i =0;
    int k=0;

    while(k<length){
        int i=k;
        int j=k;
        while(j<length-1 && s[j] == s[j+1])
            j++;
        k=j+1;
        while(j<length-1 && i>0 && s[i-1] == s[j+1]){
            j++;
            i--;
        }
        if(j-i+1 >= max_length){
            max_length = j-i+1;
            max_i = i;
        }
    }
    char *p = (char*)malloc((max_length+1)*sizeof(char));
    memcpy(p,&s[max_i],max_length);
    p[max_length]='\0';
    return p;
}

int main()
{
  char *s;

  s = "babad";
  PRINT(s,longestPalindrome(s));

  s = "cbbd";
  PRINT(s,longestPalindrome(s));

  s = "a";
  PRINT(s,longestPalindrome(s));

  s = "ccc";
  PRINT(s,longestPalindrome(s));

  s = "abcba";
  PRINT(s,longestPalindrome(s));

  s = "aacabdkacaa";
  PRINT(s,longestPalindrome(s));

  return 0;
}
