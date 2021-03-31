#include "euclidean.h"

int extendedEuclidean( int a, int b, int *x, int *y )
{
    int gcd;
    int x1 = 0, y1 = 0; /* Store the result of the recursive x and y */

    /* Base Case: a = 0 when gcd was found (gcd = b) */
    if ( a != 0 )
    {
        /* x1 and y1 will be updated in the recursive case */
        gcd = extendedEuclidean( b%a, a, &x1, &y1 );
        *x = y1 - ((b/a) * x1);
        *y = x1;
    }
    else
    {   /** According to ax + by = gcd(a,b) **/
        /** When gcd = b, a must be 0 */ 

        /* According to the equation above ... */
        *x = 0; /* x must be 0 for a = 0 */
        *y = 1; /* y must be 1 for b = gcd, because (b*y) */
        gcd = b;
    }

    return gcd;
}
