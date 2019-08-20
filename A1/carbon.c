/* Spencer Walls, 0734584 */
/* Monday, September 24th, 2018 */
/* Assignment #1 */

#include <stdio.h>

/* function that outputs all possible */
/* strings comprised of the characters */
/* 'c', 'a', 'r', 'b', 'o', and 'n' exactly once */

int carbon_permut()
{
	int c, a, r, b, o, n;
    char permutation[6] = " ";
    int i, total = 0;
    
    for (c = 1; c <= 6; c++)
    {
        for (a = 1; a <= 6; a++)
        {
            for (r = 1; r <= 6; r++)
                {
                    for (b = 1; b <= 6; b++)
                    {
                        for (o = 1; o <= 6; o++)
                        {
                            for (n = 1; n <= 6; n++)
                            {
                                if (c != a && c != r && c != b && c != o && c != n &&
                                a != c && a != r && a != b && a != o && a != n &&
                                r != c && r != a && r != b && r != o && r != n &&
                                b != c && b != a && b != r && b != o && b != n &&
                                o != c && o != a && o != r && o != b && o != n &&
                                n != c && n != a && n != r && n != b && n != o)
                                {
                                    for (i = 1; i <= 6; i++)
                                    {
                                        if (c == i)
                                        {
                                            permutation[i] = 'c';
                                        }
                                        if (a == i)
                                        {
                                            permutation[i] = 'a';
                                        }
                                        if (r == i)
                                        {
                                            permutation[i] = 'r';
                                        }
                                        if (b == i)
                                        {
                                            permutation[i] = 'b';
                                        }
                                        if (o == i)
                                        {
                                            permutation[i] = 'o';
                                        }
                                        if (n == i)
                                        {
                                            permutation[i] = 'n';
                                        }
                                    }
                                    printf("%s\n", permutation);
                                    ++total;
                                }
                            }
                        }
                    }
                }
        }
    }
    return 0;
}

