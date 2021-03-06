/*
* This program approximates pi by summing a finite number of terms in the Leibniz series
* and in the Bailey-Borwein-Plouffe series. The number of terms is determined by the
* error between the approximation and the provided constant. When the absolute error is
* less than 10^(-6), the program terminates.
*
* The program also keeps track of the amount of time each approximation takes to reach
* the desired error. The approximation functions are called multiple times so that the total
* running time for each approximation is about 6 seconds.
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "pi_funs.h"
int
main (void)
{
// initialize clocks
    clock_t lti, ltf, bti, btf;
// initialize run times
    double t1, t2;              // t1: time to approximate by leibniz, t2: time to approximate by bbp
// determine the number of terms of the leibniz series required to approximate pi with absolute error less than 10^(-6)
// and print the number of terms of the series that have been summed and the absolute error in each iteration.
    printf ("\nApproximation of pi by Leibniz series:\n");
    double pi;
    double error;
    int i1 = 0;
// calculate the error in the Leibniz approximation of pi with inputs increasing by 100000 in each loop
    do
    {
// record start time for Leibniz
        lti = clock ();
        i1 += 100000;
// repeat the function call to get a better time/call estimate
        for (int j = 0; j < 275; j++)
            pi = pi_leibniz (i1);
        error = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i1, pi, error);
    }
    while (error > .000001);
// record end time for Leibniz
    ltf = clock ();
// determine the number of terms of the leibniz series required to approximate pi with absolute error less than 10^(-6)
// and print the number of terms of the series that have been summed and the absolute error in each iteration.
    printf ("\nApproximation of pi by Bailey-Borwein-Plouffe series:\n");
    int i2 = 0;
// calculate the error in the Leibniz approximation of pi with inputs increasing by 1 in each loop
    do
    {
// record start time for bbp
        bti = clock ();
        i2 += 1;
// repeat the function call to get a better time/call estimate
        for (int j = 0; j < 30000000; j++)
            pi = pi_bbp (i2);
        error = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i2, pi, error);
    }
    while (error > .000001);
// record end time for bbp
    btf = clock ();
// calculate times per function call
    t1 = (double) (ltf - lti) / CLOCKS_PER_SEC / 275;
    t2 = (double) (btf - bti) / CLOCKS_PER_SEC / 30000000;
    double speedup = t1 / t2;
    printf ("\n");
    printf ("t1, t2, speedup:\n %.10f %.10f %.10f\n\n", t1, t2, speedup);
    return 0;
}
