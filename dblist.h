#ifndef DBLIST_H
#define DBLIST_H
#include <stdio.h>

typedef struct dblist_t {
  int num;
  double *val;
} dblist;

dblist  dbl_create(int n);
dblist  dbl_make(int n, double *vlist);
void    dbl_clean(dblist *db);

int     dbl_print(FILE *fp, const dblist db, char *format);
int     dbl_scan (FILE *fp, dblist *db);
dblist  dbl_zeros(int n);
dblist  dbl_ones (int n);
dblist  dbl_random(int n, double mean, double stddev);
dblist  dbl_range(double start, double end, double delta);
double  dbl_sum(const dblist db);

double  poly_eval_x    (const dblist poly, double x);
dblist  poly_eval_xlist(const dblist poly, const dblist xlist);
dblist  poly_integrate (const dblist poly);
dblist  poly_derive    (const dblist poly);
dblist  poly_add (const dblist a, const dblist b);
dblist  poly_mul (const dblist a, const dblist b);

dblist  dot_prod (const dblist a, const dblist b);

#endif
