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
double  dbl_sum(dblist db);

double  poly_eval_x    (dblist poly, double x);
dblist  poly_eval_xlist(dblist poly, dblist xlist);
dblist  poly_integrate (dblist poly);
dblist  poly_derive(dblist poly);

dblist  dot_product(dblist a, dblist b);
dblist  convolution(dblist a, dblist b); 

#endif
