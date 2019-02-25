#include "dblist.h"
#include <stdio.h>

#define DBL_PRT(x)    do { printf("%s =\n", #x); dbl_print(x, "%f"); } while (0)

int main()
{
  dblist a = dbl_zeros(10);
  dblist b = dbl_ones(10);
  dblist c = dbl_random(10, 0, 1.0);
  dblist d = dbl_range(0.0, 1.0, 0.1);
  dblist e = dbl_make(5, (double []){1.1, 1.2, 1.3, 1.4, 1.5});

  DBL_PRT(a);
  DBL_PRT(b);
  DBL_PRT(c);
  DBL_PRT(d);
  DBL_PRT(e); 

  dbl_clean(&a);
  dbl_clean(&b);
  dbl_clean(&c);
  dbl_clean(&d);
  dbl_clean(&e); 
}
