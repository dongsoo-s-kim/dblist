#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extlib.h"

char *join_r(char **wv, char *buffer, char *delimiter)
{
  int i;
  char **w;
  
  if (delimiter == NULL)	/* recover user's mistake or a default delimiter */
    delimiter = " "; 
    
  *buffer = '\0'; 		/* make buffer a zero-length string for next string functions */
  foreach_slist(w, wv) {
    if (w != wv) 		/* if not the first word */
      strcat(buffer, delimiter); /* add the delimiter */
    strcat(buffer, *w);
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
    len += strlen(*w);		/* total length of word list */
    cnt++;			/* count of word list */
  }
  len += (cnt-1) * strlen(delimiter) + 1; /* add length for delimiters and terminating null character */
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
