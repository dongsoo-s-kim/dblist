/*
  generator.c
  Copyright (C) 2019 Dongsoo S. Kim
 */

#include "dblist.h"
#include "randomx.h"

generator init_norm(double mean, double stddev)
{
  generator x;
  x.acnt = 2;
  x.args[0] = mean;
  x.args[1] = stddev;
  x.func = rx_normal;
  return x; 
}

generator init_unif(double min, double max)
{
  generator x;
  x.acnt = 2;
  x.args[0] = min;
  x.args[1] = max;
  x.func = rx_range;
  return x; 
}

generator init_expo(double mean)
{
  generator x;
  x.acnt = 1;
  x.args[0] = mean;
  x.func  = rx_exponential;
  return x; 
}

dblist dbl_random(int n, generator gen)
{
  dblist x;
  x = dbl_create(n);
  switch (gen.acnt) {
  case 0:
    for (int i=0; i<n; i++)
      x.val[i] = gen.func();
    break;
  case 1:
    for (int i=0; i<n; i++)
      x.val[i] = gen.func(gen.args[0]);
    break;
  case 2:
    for (int i=0; i<n; i++)
      x.val[i] = gen.func(gen.args[0], gen.args[1]);
    break;
  default:
    dbl_clean(&x); 
    break;
  }
  return x; 
}

#ifdef __MAIN__

int main()
{
  dblist a, b, c;
  generator gen1, gen2, gen3;
  int n = 5; 

  gen1 = init_norm(0, 1);
  gen2 = init_unif(0, 100);
  gen3 = init_expo(2.0);

  a = dbl_random(n, gen1);
  b = dbl_random(n, gen2);
  c = dbl_random(n, gen3);

  printf("a=");
  dbl_print(stdout, a, "%f");
  printf("\nb=");
  dbl_print(stdout, b, "%f");
  printf("\nc=");
  dbl_print(stdout, c, "%f");
  
}

#endif  
