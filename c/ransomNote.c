#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101
void swap(char *word, int a , int b);
void qqsort(char *word, int left, int right)
{
  int i, last;

  if (left >= right) /* do nothing if array contains fewer than 2 elems */
    return;
  swap(word, left, (left + right)/2); /* move partition elems to v0 */
  last = left;
  for (i = left+1;i <= right;++i)
    if (word[i] < word[left])
      swap(word, ++last, i);
  swap(word, left, last);
  qqsort(word, left, last-1);
  qqsort(word, last+1, right);
}

void swap(char *word, int a, int b)
{
  if (a == b)
    return;
  char tmp;
  tmp = word[a];
  word[a] = word[b];
  word[b] = tmp;
}

/* Table lookup routine */

typedef struct nList {
  struct nList *next;
  char val;
  int count;
} Node;


/* hash function */
unsigned hash(char c)
{
  unsigned hashVal = c*31;
  return hashVal % HASHSIZE;
}

/* lookup */
Node *lookup(char c,Node *hashtable[])
{
  Node *np;
  for(np = hashtable[hash(c)];np != NULL; np = np->next)
    if (np->val == c)
      return np;
  return NULL;
}

/* install */
Node *install(char c,Node *hashtable[])
{
  Node* np;
  unsigned hashval;

  if((np = lookup(c,hashtable)) == NULL) { /* Not found */
    np = (Node *)malloc(sizeof(Node));
    hashval = hash(c);
    np->next = hashtable[hashval];
    np->val = c;
    np->count = 1;
    hashtable[hashval] = np;
  }
  else
    /* Already there, so increase count */
    (np->count)++;
  return np;

}

int canConstruct(char *ransomNote, char *magazine)
{
  /* qqsort(ransomNote, 0, strlen(ransomNote)-1); */
  /* qqsort(magazine, 0, strlen(magazine)-1); */
  /* while ((*ransomNote++ == *magazine++) && *ransomNote != '\0') */
  /*   ; */
  /* return *--ransomNote == *--magazine; */

  Node *hashtable[HASHSIZE] = {0};

  char *m = magazine;
  Node *np;

  for(;*magazine;install(*magazine++,hashtable)) /* create table */
    ;

  magazine = m;   /* reset magazine */
  while(*ransomNote && (np = lookup(*ransomNote++, hashtable)) && (np->count)--)
    ;
  return *ransomNote == '\0' && np != NULL && np->count>-1;
}



int main()
{
  char note[100] = "a",zine[100] = "b";
  printf("can construct %s and %s is %d\n",note, zine, canConstruct(note,zine));
  printf("------------------\n");

  char note1[100] = "aa",zine1[100] = "ab";
  printf("can construct %s and %s is %d\n",note1, zine1, canConstruct(note1,zine1));
  printf("------------------\n");

  char note2[100] = "aa",zine2[100] = "aab";
  printf("can construct %s and %s is %d\n",note2, zine2, canConstruct(note2,zine2));
  printf("------------------\n");

  char note3[100] = "bg",zine3[100] = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
  printf("can construct %s and %s is %d\n",note3, zine3, canConstruct(note3,zine3));
  printf("------------------\n");

}
