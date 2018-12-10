

#include <stdio.h>
#include <time.h>

int main (void)
{
  clock_t start, end;

  start = clock ();
  {
    /* Portion de code a chronometrer */
  }
  end = clock ();
  printf ("Temps en secondes : %f\n", (end - start) / (double)CLOCKS_PER_SEC);
  return 0;
}
