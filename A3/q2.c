/* Spencer Walls, 0734584 */
/* November 5th, 2018 */
/* Assignment #3 */
/* Question #2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *file = fopen("f.dat", "r");
	int matrix[20][10] = {0}; //heap is represented by a 2D array, i.e. a matrix
	int temp_matrix[10] = {0};
	int sum_1, sum_2;
	int child, parent;
	int key = 0;
	int m = 0;
	int n = 0;
	int i = 0;

	for (m = 0; m < 20; m++) //scans every row 'm' of the matrix
	{
		for (n = 0; n < 10; n++) //scans every column 'n' of row 'm'
		{
			fscanf(file, "%d", &matrix[m][n]); //2D array is an 'm x n' matrix
		}
			child = m; //object == row == child
			parent = (int) child * 0.5; //determines the index of the parent
										//which is half of its child's index

			sum_1 = matrix[parent][0] + matrix[parent][1] + matrix[parent][2]; 
			sum_2 = matrix[child][0] + matrix[child][1] + matrix[child][2]; 

			while (sum_1 > sum_2) //while the parent is greater than the added element,
			{					  //exchange the parent for the current node
				for (i = 0; i < 10; i++) 
				{
					temp_matrix[i] = matrix[parent][i];
					matrix[parent][i] = matrix[child][i];
					matrix[child][i] = temp_matrix[i];
				}

				child = parent;
				parent = (int) child * 0.5; //determine the index of the parent
										    //which is half of its child's index

				sum_1 = matrix[parent][0] + matrix[parent][1] + matrix[parent][2];
				sum_2 = matrix[child][0] + matrix[child][1] + matrix[child][2];
			}
	}

	for (m = 0; m < 20; m++)
	{
		for (n = 0; n < 10; n++)
		{
			if (n < 2)
			{
				key += matrix[m][n];
			}
			else if (n == 2)
			{
				key += matrix[m][n];
				printf("Key: %d  Data: ", key); 
			}
			else
			{
				printf("%d ", matrix[m][n]); 
			}
		}
		printf("\n");
		key = 0;
	}
	
	fclose(file);
	return 0;
}
