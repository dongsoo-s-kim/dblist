#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "extlib.h"
/*
  compact()
  1. ignore any leading whitespace
  2. ignore any trailing whiatespace inlcue a newline
  3. shrink multiple contiguous space into a single space
*/

char *compact(char *buf) 
{
  char *dest, *cp;
  ltrim(buf);
  rtrim(buf);
  
  dest = cp = buf; 
  while (*cp)	{			// shift all remaining to left
    if (isspace(*cp)) {
      *dest++ = ' ';	// rely on space character
      while (isspace(*cp))	// skip repeating spaces
	cp++; 
    }
    else
      *dest++ = *cp++;
  }
  *dest = '\0';				// string termination
  return buf; 
}

#ifdef __MAIN__
#define MAX 		256
char *data[] = {
  "Now we are engaged in a great civil war, testing whether that",
  "     nation, or any nation so conceived and so dedicated,",
  "  can long endure. We are met on a great battle-field    ", 
  "   of    that    war.     We    have    come to   ",
  "		dedicate a portion of that field, ",
  "   as a final resting place for those who here gave their", 
  "   lives that that nation might live. It is altogether", 
  "  fitting and proper that we should do this.   ",
};
int main()
{
  char buffer[MAX]; 
  for (int i=0; i<sizeof(data)/sizeof(data[0]); i++) {
    strcpy(buffer, data[i]); 
    printf("S0 [%s]\n", buffer);
    compact(buffer); 
    printf("S1 [%s]\n", buffer);
    printf("\n");
    fflush(stdout); 
  }
}
#endif
