/* Spencer Walls, 0734584 */
/* Monday, September 24th, 2018 */
/* Assignment #1 */

#include <stdio.h>

/* recursive Ackermann's function */
/* returns a solution respective to */
/* the three specified conditions */

int ackermann(int m, int n)
{
	if (m < 0 || n < 0)
	{
		return printf("error: negative argument(s)\n\n");
	}
	if (!m)
	{
		return n + 1;
	}
	else if (!n)
	{
		return ackermann(m - 1, 1);
	}
	else
	{
		return ackermann(m - 1, ackermann(m, n - 1));
	}
}
