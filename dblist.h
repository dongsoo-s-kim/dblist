#ifndef DBLIST_H
#define DBLIST_H

typedef struct dblist_t {
  int num;
  double *val;
} dblist;

dblist  dbl_create(int n);
dblist  dbl_make(int n, double *vlist); 
void    dbl_clean(dblist *db);

int     dbl_print(const dblist db, char *format);
int     dbl_scan (dblist *db);
dblist  dbl_zeros(int n);
dblist  dbl_ones (int n);
dblist  dbl_random(int n, double mean, double stddev); 
dblist  dbl_range(double start, double end, double delta);
double  dbl_sum(dblist db);

double  poly_eval_x    (dblist poly, double x);
dblist  poly_eval_xlist(dblist poly, dblist xlist);
dblist  poly_integrate (dblist poly);
#endif
