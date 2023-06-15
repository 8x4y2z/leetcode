#include <stdio.h>

enum romanNumeral {
  M=1000,
  CM=900,
  D=500,
  CD=400,
  C=100,
  XC=90,
  L=50,
  XL=40,
  X=10,
  IX=9,
  V=5,
  IV=4,
  I=1,
  UNKNOWN=0
};

char *getRomanNumeral(char *s, int *pi) {
  char c = *s, n = *++s;
  int r;
  switch (c) {
    case 'M':
      r =  M;
      break;
    case 'D':
      r =  D;
      break;
    case 'V':
      r =  V;
      break;
    case 'L':
      r =  L;
      break;
    case 'I':
      switch (n) {
        case 'X':
          r =  IX;
          ++s;
          break;
        case 'V':
          r =  IV;
          ++s;
          break;
        default:
          r =  I;
          break;
      }
      break;
    case 'X':
      switch (n) {
        case 'C':
          r =  XC;
          ++s;
          break;
        case 'L':
          r =  XL;
          ++s;
          break;
        default:
          r =  X;
          break;
      }
      break;
    case 'C':
      switch (n) {
        case 'M':
          r =  CM;
          ++s;
          break;
        case 'D':
          r =  CD;
          ++s;
          break;
        default:
          r =  C;
          break;
      }
      break;
    default:
      r =  UNKNOWN;
  }
  *pi += r;
  return s;
}

int romanToInt(char *s)
{
  int r = 0;
  while(*(s=getRomanNumeral(s, &r)))
    ;
  return r;
}

int main(){
  char *t1 = "III";
  char *t2 = "LVIII";
  char *t3 = "MCMXCIV";
  printf("testing t1, %s == %d\n",t1,romanToInt(t1) );
  printf("testing t2, %s == %d\n",t2,romanToInt(t2) );
  printf("testing t3, %s == %d\n",t3,romanToInt(t3) );
  return 0;
}
