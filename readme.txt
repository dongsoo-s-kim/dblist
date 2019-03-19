dblist  dbl_create(int n);						// lab7
dblist  dbl_make (int n, double *vlist); 				// lab7
void    dbl_clean(dblist *v);						// lab7
int     dbl_print(FILE *fp, const dblist v, char *format);		// startup
int     dbl_scan (FILE *fp, dblist *v);
dblist  dbl_zeros(int n);						// startup
dblist  dbl_ones (int n);						// startup
dblist  dbl_rand_normal (int n, double mean, double stddev);		// startup
dblist  dbl_rand_uniform(int n, double min, double max);
dblist  dbl_rand_exp(int n, double mean); 
dblist  dbl_range   (double start, double end, double delta);		// lab7
double  dbl_sum	    (const dblist v);					// lab7
double  dbl_mean    (const dblist v);
double  dbl_stddev  (const dblist v);
int     dbl_count   (const dblist v); 
dblist  map         (double (*func)(double, void *), dblist v, void *arg);
double  reduce      (double (*func)(double, double, void *), dblist v, void *arg);
dblist  filter      (bool   (*func)(double, void *), dblist v, void *arg); 
dblist  dot_prod    (const dblist a, const dblist b);
double  poly_eval_x     (const dblist poly, double x);			// lab7
dblist  poly_eval_xlist (const dblist poly, const dblist xlist);	// lab7
dblist  poly_integrate  (const dblist poly);				// lab7
dblist  poly_derive     (const dblist poly);
dblist  poly_roots	(const dblist poly); 
dblist  poly_poly	(const dblist roots);
dblist  poly_add  (const dblist polya, const dblist polyb);
dblist  poly_mul  (const dblist polya, const dblist polyb);
dblist  poly_div  (const dblist polya, const dblist polyb, dblist *mod);
