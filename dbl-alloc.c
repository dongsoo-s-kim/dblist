/*
  dbl-alloc.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include "dblist.h"
#include <stdlib.h>

inline dblist dbl_create(int n)
{
  dblist x;
  x.num = n;
  x.val = (double *) malloc(sizeof(double) * x.num);
  return x;
}

dblist dbl_make(int n, double *vlist)
{
  dblist x = dbl_create(n);
  for (int i=0; i<x.num; i++)
    x.val[i] = vlist[i];
  return x;
}

inline void dbl_clean(dblist *db)
{
  free(db->val);
  db->val = NULL;
  db->num = 0;
}

inline int dbl_count(const dblist v)
{
  return v.num;
}
