/*
  dbl-print.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include "dblist.h"
#include <stdio.h>

int     dbl_print(FILE *fp, const dblist db, char *format)
{
  int cnt = 0; 
  for (int i=0; i<db.num; i++) {
    cnt += fprintf(fp, format, db.val[i]);
    cnt += fprintf(fp, "%s", (i<db.num-1) ? ", " : "\n");
  }
  return cnt; 
}
