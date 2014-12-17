/*
* Approximates pi by the summation of the first n terms of the Leibniz series.
*/
#include <stdio.h>
double
pi_leibniz (int n)
{
// check for valid input
    if (n < 1)
    {
        printf ("Invalid input\n");
        return -1;
    }
    double num = 1, denom = 1, pi_over4 = 0;
    for (int i = 0; i <= n; i++)
    {
// calculate pi/4
        pi_over4 += num / denom;
// alternate sign of the term
        num = -num;
// increase the denominator by 2
        denom += 2;
    }
// return pi
    return 4 * pi_over4;
}
