/* Spencer Walls, 0734584 */
/* Monday, September 24th, 2018 */
/* Assignment #1 */

#include <stdio.h>

int carbon_permut();
int ackermann(int m, int n);
double newton_rec(double x, double e, double a);
double newton_nonrec(double x, double e);

int main()
{
	double x, e, newton_rec_solution, newton_nonrec_solution;
	int m, n, ackermann_solution;
	char ch;
	
	/* Question 1 */ 
	printf("Press Enter to activate a function that outputs\n");
	printf("every possible permutation of the string 'carbon'\n");
	ch = getchar();
	carbon_permut();
	printf("\n");

	/* Question 2 */
	printf("Enter input for Ackermann's function,\n");
	printf("whereby both m and n must be >= 0.\n");
	printf("First, enter input for m: ");
	scanf("%d", &m);
	printf("Now, enter input for n: ");
	scanf("%d", &n);
	ackermann_solution = ackermann(m, n);
	if (m >= 0 && n >= 0)
		printf("A(%d,%d) = %d\n\n", m, n, ackermann_solution);

	/* Question 3 */
	printf("Enter the number for which the square root\n");
	printf("is to be computed by Newton's method (recursive): ");
	scanf("%lf", &x);
	printf("Enter the epsilon (accuracy) to be used for the calculation: ");
	scanf("%lf", &e);
	newton_rec_solution = newton_rec(x, e, x / 2); /* initialization of a */
	printf("The square root approximation = %lf\n\n", newton_rec_solution);
	
	/* Question 3 concluded */
	printf("Enter the number for which the square root\n");
	printf("is to be computed by Newton's method (non-recursive):  ");
	scanf("%lf", &x);
	printf("Enter the epsilon (accuracy) to be used for the calculation: ");
	scanf("%lf", &e);
	newton_nonrec_solution = newton_nonrec(x, e);
	printf("The square root approximation = %lf\n\n", newton_nonrec_solution);
	
	/* Final statement */
	printf("To run this program again, please re-enter './a1'\n\n");
	
	return 0;
}

