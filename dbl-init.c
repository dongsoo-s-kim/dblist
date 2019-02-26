#include "dblist.h"
#include "randomx.h"
#include <stdio.h>


dblist  dbl_zeros(int n)
{
  dblist x;
  x = dbl_create(n);
  for (int i=0; i<n; i++)
    x.val[i] = 0.0;
  return x;
}

dblist  dbl_ones (int n)
{
  dblist x;
  x = dbl_create(n);
  for (int i=0; i<n; i++)
    x.val[i] = 1.0;
  return x;
}

dblist  dbl_rand_normal(int n, double mean, double stddev)
{
  dblist x;
  x = dbl_create(n);
  for (int i=0; i<n; i++)
    x.val[i] = rx_normal(mean, stddev);
  return x;
}

