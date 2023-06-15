/* Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * Return the answer in any order.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINT(a,b)                 do {                            \
    if(a==NULL) printf("[]\n-------------------\n");              \
    else{                                                         \
    int i;                                                         \
    printf("[");                                                   \
    for(i=0;i<b-1;i++)                                          \
      printf("%s,",a[i]);                                            \
    printf("%s]\n-----------------\n",a[i]); }}                      \
  while(0)

static char *NUMMAP[] = {
  "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void innerComb(char **, int, int *, int l, int *, int *,char *[]);

char ** letterCombinations(char * digits, int *returnSize)
{
  char *p=digits, *q, **res;
  int prd = 1,n=0,i,points=0;

  int l = strlen(digits), *lens = (int *)malloc(l*sizeof(int)) , *pos = (int *)malloc(l*sizeof(int));
  if(l ==0) {
    *returnSize = 0;
    return NULL;
}
  char **locs = (char **)malloc(l*sizeof(char*));

  for(q = p, i = 0; *q;q++,i++ ) {
    lens[i] = strlen(NUMMAP[*q -'0']);
    prd *= lens[i];
    pos[i] = 0;
    locs[i] = strdup(NUMMAP[*q - '0']);
    /* locs[i] = NUMMAP[*q - '0']; */
  }

  res = (char **)malloc(prd*sizeof(char*));
  *returnSize = prd;

  for(i=0;i<prd;i++)
    res[i] = (char *)malloc((l+1)*sizeof(char));

  innerComb(res,n, lens, l, pos, &points, locs);
  return res;

}

void innerComb(char ** res, int n, int *lens, int l, int *pos, int *points, char *LOC[])
{
  int i,ii, l1, l2;
  char *q;
  n++;
  for(i=0;i<lens[ n - 1];i++) {
    if (n % l == 0){
      pos[n - 1] = i;
      l1 = *points / 3;
      l2 = *points % 3;
      q = res[3*l1+l2];
      for (ii=0;ii<l;*q++ = LOC[ii][pos[ii]],ii++);
      *q = '\0';
      *points += 1;

    }
    else {
      pos[n -1] = i;
      innerComb(res, n, lens, l, pos, points,LOC);
    }

  }

}

#if 0
char map[10][5] = {
					{},
					{},
					{'a','b','c'},
					{'d','e','f'},
					{'g','h','i'},
					{'j','k','l'},
					{'m','n','o'},
					{'p','q','r','s'},
					{'t','u','v'},
					{'w','x','y','z'}
				  };

int result_index;
char **result;

void helper(int index, char *tempstr, char *digits) {
    if(digits[index] == '\0') {
        tempstr[index] = '\0';
        result[result_index] = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
        strcpy(result[result_index], tempstr);
        result_index++;
    }else {
        for(int i = 0 ; i < strlen(map[(digits[index] - '0')]) ; i++) {
            tempstr[index] = map[(digits[index] - '0')][i];
            helper(index + 1, tempstr, digits);
        }
    }
}
char **letterCombinations(char *digits, int *returnSize) {
    result_index = 0;

    if(strlen(digits) != 0) {
        (*returnSize) = 1;
        for(int i = 0 ; i < strlen(digits) ; i++ )
            (*returnSize) = (*returnSize) * strlen(map[(digits[i] - '0')]);
    }
    else
		(*returnSize) = 0;

    result = (char**)malloc(sizeof(char*) * (*returnSize));

    char tempstr[5] = {0};
    if((*returnSize) > 0)
        helper(0, tempstr, digits);

    return result;
}
#endif

int main()
{
  char **ret;
  int retSize;

  char *digits = "23";
  ret = letterCombinations(digits,&retSize);
  PRINT(ret,retSize);

  char *digits1 = "27";
  ret = letterCombinations(digits1,&retSize);
  PRINT(ret,retSize);

  char *digits2 = "2";
  ret = letterCombinations(digits2,&retSize);
  PRINT(ret,retSize);

  char *digits4 = "";
  ret = letterCombinations(digits4,&retSize);
  PRINT(ret,retSize);

  char *digits3 = "2476";
  ret = letterCombinations(digits3,&retSize);
  PRINT(ret,retSize);

  return 0;
}
