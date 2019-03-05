#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extlib.h"

char *join_r(char **wv, char *buffer, char *delimiter)
{
  int i; 
  *buffer = '\0'; 
  if (delimiter == NULL)
    delimiter = " "; 
    
  if (*wv)
    strcat(buffer, *wv++);
    
  while (*wv) {
    strcat(buffer, delimiter);
    strcat(buffer, *wv++);
  }
  return buffer; 
}

char *join(char **wv, char *delimiter)
{
  int len = 0;
  int cnt = 0; 
  char **w;
  char *buffer; 
  foreach_slist(w, wv) {
    len += strlen(*w);
    cnt++;
  }
  printf("len = %d\n", len);
  printf("cnt = %d\n", cnt);
  len += (cnt-1) * strlen(delimiter) + 1;
  buffer = (char *) malloc(len);
  return join_r(wv, buffer, delimiter);
}

#ifdef __MAIN__
int main()
{
  char *words[] = {"red", "blue", "green", "black", "white", NULL};
  char buffer[100];
  char *line1, *line2; 
  
  line1 = join_r(words, buffer, ",");
  printf("%d:%s\n\n", strlen(line1), line1);
  line2 = join(words, ","); 
  printf("%d:%s\n\n", strlen(line2), line2);
}
#endif 
