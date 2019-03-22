dblist  dbl_create(int n);                                      // lab7 [dbl-alloc.c]
dblist  dbl_make (int n, double *vlist);                        // lab7 [dbl-alloc.c]
void    dbl_clean(dblist *v);                                   // lab7 [dbl-alloc.c]
int     dbl_print(FILE *fp, const dblist v, char *format);      // startup [dbl-print.c]
int     dbl_scan (FILE *fp, dblist *v);                         // lab9(honor)
dblist  dbl_zeros(int n);                                       // startup [dbl-init.c]
dblist  dbl_ones (int n);                                       // startup [dbl-init.c]
dblist  dbl_rand_normal (int n, double mean, double stddev);    // startup [dbl-init.c]
dblist  dbl_rand_uniform(int n, double min, double max);        // deprecated
dblist  dbl_rand_exp(int n, double mean);             		// deprecated
dblist  dbl_range   (double start, double end, double delta);   // lab7
double  dbl_sum      (const dblist v);                          // lab7, lab9
double  dbl_mean    (const dblist v);                           // lab9
double  dbl_stddev  (const dblist v);                           // lab9
int     dbl_count   (const dblist v);				// [dbl-alloc.c] 

/* flexible random generator */
generator init_norm(double mean, double stddev);                // [generator.c]
generator init_unif(double min, double max);                    // [generator.c]
generator init_expo(double mean);                               // [generator.c]
dblist dbl_random(int n, generator gen);                        // [generator.c]

dblist  map         (double (*func)(double, void *), dblist v, void *arg);          // lab9
double  reduce      (double (*func)(double, double, void *), dblist v, void *arg);  // lab9
dblist  filter      (bool   (*func)(double, void *), dblist v, void *arg); 
double  prod        (const dblist a, const dblist b);           // lab9
dblist  dot_prod    (const dblist a, const dblist b);           // lab9
double  poly_eval_x     (const dblist poly, double x);          // lab7
dblist  poly_eval_xlist (const dblist poly, const dblist xlist);// lab7
dblist  poly_integrate  (const dblist poly);                    // lab7
dblist  poly_derive     (const dblist poly);
dblist  poly_roots  (const dblist poly); 
dblist  poly_poly  (const dblist roots);
dblist  poly_add  (const dblist polya, const dblist polyb);
dblist  poly_mul  (const dblist polya, const dblist polyb);
dblist  poly_div  (const dblist polya, const dblist polyb, dblist *mod);
