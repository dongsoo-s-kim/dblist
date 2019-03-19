/*
  dblist.h
  Copyright (C) 2019 Dongsoo S. Kim
 */
#ifndef DBLIST_H
#define DBLIST_H
#include <stdio.h>
#include <stdbool.h>

typedef struct dblist_t {
  int num;
  double *val;
} dblist;

dblist  dbl_create	(int n);
dblist  dbl_make	(int n, double *vlist); 
void    dbl_clean	(dblist *v);

int     dbl_print	(FILE *fp, const dblist v, char *format);
int     dbl_scan	(FILE *fp, dblist *v);
dblist  dbl_zeros	(int n);
dblist  dbl_ones	(int n);
dblist  dbl_rand_normal (int n, double mean, double stddev);
dblist  dbl_rand_uniform(int n, double min, double max);
dblist  dbl_rand_exp    (int n, double mean); 
dblist  dbl_range	(double start, double end, double delta);
double  dbl_sum		(const dblist v);
double  dbl_mean        (const dblist v);
double  dbl_stddev      (const dblist v);
int     dbl_count       (const dblist v); 

dblist  map      (double (*func)(double, void *), dblist v, void *arg);
double  reduce   (double (*func)(double, double, void *), dblist v, void *arg);
dblist  filter   (bool   (*func)(double, void *), dblist v, void *arg); 
dblist  prod     (const dblist a, const dblist b); 
double  dot_prod (const dblist a, const dblist b);

double  poly_eval_x     (const dblist poly, double x);
dblist  poly_eval_xlist (const dblist poly, const dblist xlist);
dblist  poly_integrate  (const dblist poly);
dblist  poly_derive     (const dblist poly);
dblist  poly_roots	(const dblist poly); 
dblist  poly_poly	(const dblist roots);
dblist  poly_add  (const dblist polya, const dblist polyb);
dblist  poly_mul  (const dblist polya, const dblist polyb);
dblist  poly_div  (const dblist polya, const dblist polyb, dblist *mod);

#endif
