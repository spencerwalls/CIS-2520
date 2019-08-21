Spencer Walls, 0734584
Assignment #1

Running the program:

Following compilation using the 'make' command in the terminal, the program may be run by entering './a1' at the command line. 

The user will be prompted to press 'Enter', which will then initiate a function that outputs all permutations of the characters 'c', 'a', 'r', 'b', 'o', and 'n', whereby each character appears precisely once in each permutation. 

Following this output, the user will be prompted to enter input for Ackermann's function, beginning with the input of parameter m, followed by parameter n. The solution to Ackermann's function with respect to the input data, i.e. A(m, n), will subsequently be printed. 

The user will then be prompted to input a number for which the square root will be computed via Newton's method and then printed. This function invokes a recursive implementation of the algorithm. Subsequently, the user will be prompted to input another number, of which the square root will again be computed, however this time by a non-recursive version of the algorithm. The resultant square root will once again be printed. 

If the user wishes to run the program a second time, simply enter './a1' at the command line again. 

Range limitations for Ackermann's function:

Following rigorous testing of Ackermann's function, it was determined that m may range from 0 to 3, and n may range from 0 to 12. Any input outside of these ranges yields a segmentation error. Thus, the maximum combination of parameters possible is A(3,12) which yields a result of 32765. It should be noted however that the default integer data type was selected; had the 'unsigned' integer data type been declared instead, the program would resultantly allow for integers of roughly twice this size. This approach might also be employed since Ackermann's function doesn't deal with negative numbers. 
