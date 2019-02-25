#include "dblist.h"
#include <stdio.h>

int     dbl_print(const dblist db, char *format)
{
  int cnt = 0; 
  for (int i=0; i<db.num; i++) {
    cnt += printf(format, db.val[i]);
    cnt += printf("%s", (i<db.num-1) ? ", " : "\n");
  }
  return cnt; 
}
