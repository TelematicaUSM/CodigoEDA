#include <stdio.h>

int
main ()
{
  int n_assignments;
  float v[6];
  FILE *f = fopen ("planilla.csv", "r");

  while (1)
    {
      n_assignments = fscanf (f, "%f;%f;%f;%f;%f;%f", &v[0], &v[1], &v[2],
                              &v[3], &v[4], &v[5]);
      if (n_assignments != EOF)
        printf ("%f; %f; %f; %f; %f; %f\n", v[0], v[1], v[2], v[3], v[4],
                v[5]);
      else
        break;
    }

  fclose (f);
}
