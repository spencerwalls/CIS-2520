/* Spencer Walls, 0734584 */
/* Monday, September 24th, 2018 */
/* Assignment #1 */

#include <math.h>

/* non-recursive version of Newton's method */
/* returns the sqrt of x relative to accuracy e */

double newton_nonrec(double x, double e)
{
	double a = x / 2; /* initialize a */ 
	while (fabs(a*a - x) > e)
	{
		a = (a + x / a) / 2;
	}
	return a;
}

/* recursive version of Newton's method */
/* returns the sqrt of x relative to accuracy e */
/* includes additional argument 'a' to allow for recursion */
/* which is initialized to x / 2 in the main function */

double newton_rec(double x, double e, double a) 
{
	if (fabs(a*a - x) <= e)
	{
		return a;
	}
	else
	{
		return newton_rec(x, e, newton_rec(x, e, (a + x / a) / 2));
	}
}

