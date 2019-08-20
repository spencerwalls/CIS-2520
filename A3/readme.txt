Spencer Walls, 0734584
Assignment #3

Running the programs:

Following compilation using the 'make' command in the terminal, question #1 may be run by simply entering './q1 [infix expression]' in the terminal, for example './q1 (5.00+2.00)/(x2+x3)'. Thus, precisely two arguments must be entered in order to successfully run this program; if any other number of arguments are entered, for example if there are spaces placed between the values of the infix expression, an error message will be printed and the program will terminate. If two arguments are passed, the user will be prompted to select one of the 7 options outlined in the assignment instructions. The user will continue to be prompted to do this until the 7th command, i.e. the option to exit, has been selected, or any type of invalid input is entered (input that does not pertain to integers in the range of 1 to 7). 

Question #2 may be run by simply entering './q2' at the command line, after which the 2D array representation of a heap will be neatly displayed. 

Please note: Every required aspect of this assignment has been completed except for the visualization of a tree that is requested of option '1. Display' in question #1. It may be seen in the q1.c source file that a tree representation was started but not finished. Besides this one small part that was left out, everything else is indeed fully completed. 

Sample output: 

Below contains sample output from compiling and then running each executable. For q1, one infix expression is successfully passed, and the option '4. Postorder' is selected which prints the inputted infix expression as a postfix expression. The program is then exited by entering '7'. 

For q2, 'q2' is simply entered at the command line and the program is successfully executed. 

note: this sample output was generated in a Windows' terminal.

*****************************************************************

C:\Users\Spencer\Desktop>gcc -o q1 -Wall -pedantic -std=c99 q1.c

C:\Users\Spencer\Desktop>q1 (4.00-2.00)*(4.00+x4+x5)

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

4
Postorder:

4.00 2.00 - 4.00 x4 + x5 + *

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

7
Goodbye

C:\Users\Spencer\Desktop>gcc -o q2 -Wall -pedantic -std=c99 q2.c

C:\Users\Spencer\Desktop>q2
Key: 54  Data: 82 52 53 5 3 68 64
Key: 57  Data: 99 29 99 79 45 59 19
Key: 77  Data: 88 15 39 88 69 31 49
Key: 65  Data: 44 59 87 32 36 36 46
Key: 80  Data: 68 49 68 74 32 9 30
Key: 90  Data: 59 4 84 10 42 43 2
Key: 139  Data: 23 14 81 82 0 38 4
Key: 137  Data: 53 36 54 69 68 38 43
Key: 114  Data: 90 74 56 64 75 67 55
Key: 110  Data: 32 33 54 60 33 51 87
Key: 186  Data: 93 57 6 29 91 92 39
Key: 137  Data: 21 9 69 5 30 20 91
Key: 260  Data: 0 63 24 54 20 20 24
Key: 139  Data: 96 70 98 85 13 25 47
Key: 208  Data: 11 21 4 8 97 93 14
Key: 178  Data: 86 42 44 48 64 41 1
Key: 203  Data: 88 39 30 44 59 49 72
Key: 185  Data: 46 69 42 74 68 79 28
Key: 176  Data: 40 29 84 24 61 87 20
Key: 127  Data: 65 40 39 44 49 32 60