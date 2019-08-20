Spencer Walls, 0734584
Assignment #2

Running the programs:

Following compilation using the 'make' command in the terminal, question #1 may be run by simply entering './q1' at the command line. This will prompt the user to select one of the 7 options outlined in the assignment instructions. The user will continue to be prompted to do this until the 7th command, i.e. the option to quit, has been selected, or any type of invalid input is entered (input that does not pertain to integers in the range of 1 to 7). 

Question #2 may be run by entering './q1 [post-fix expression]' in the terminal, for example './q1 55*3+'. Thus, precisely two arguments must be entered in order to successfully run this program; if any other number of arguments are entered, an error message will be printed and the program will terminate. Upon successful execution, the result of the postfix expression will be printed, displaying up to two significant figures. 

Sample output: 

Below contains sample output from compiling and then running each executable. For q1, each list is printed by entering '5', and then the program is exited by entering '7'. For q2, one post-fix expression is successfully executed and the result is printed.

*****************************************************************

swalls@george:~/Desktop/a2$ make
gcc -o q1 -Wall -std=c99 -pedantic q1.c
gcc -o q2 -Wall -std=c99 -pedantic q2.c
swalls@george:~/Desktop/a2$ ./q1

1. Add a new car to the available-for-rent list
2. Add a returned car to the available-for-rent list
3. Add a returned car to the repair list
4. Transfer a car from the repair list to the available-for-rent list
5. Rent the first available car
6. Print all the lists
7. Quit

6

Print all the lists:

Available-for-rent list

Plate number: WXYZ000 Mileage: 150 Return date: 0
Plate number: WXYZ111 Mileage: 500 Return date: 0
Plate number: WXYZ222 Mileage: 700 Return date: 0
Plate number: ABCD222 Mileage: 1500 Return date: 0
Plate number: ABCD777 Mileage: 8000 Return date: 0
Plate number: ABCD888 Mileage: 9500 Return date: 0
Plate number: ABCD999 Mileage: 12000 Return date: 0
Plate number: WXYZ888 Mileage: 90000 Return date: 0

Rented list

Plate number: WXYZ444 Mileage: 3500 Return date: 181025
Plate number: ABCD666 Mileage: 6500 Return date: 181026
Plate number: WXYZ333 Mileage: 7000 Return date: 181027
Plate number: WXYZ666 Mileage: 7000 Return date: 181028
Plate number: WXYZ555 Mileage: 6000 Return date: 181029
Plate number: WXYZ777 Mileage: 800 Return date: 181101

Repair list

Plate number: WXYZ999 Mileage: 650 Return date: 0
Plate number: ABCD555 Mileage: 6000 Return date: 0
Plate number: ABCD111 Mileage: 600 Return date: 0
Plate number: ABCD000 Mileage: 300 Return date: 0
Plate number: ABCD333 Mileage: 2000 Return date: 0
Plate number: ABCD444 Mileage: 2500 Return date: 0


1. Add a new car to the available-for-rent list
2. Add a returned car to the available-for-rent list
3. Add a returned car to the repair list
4. Transfer a car from the repair list to the available-for-rent list
5. Rent the first available car
6. Print all the lists
7. Quit

7

Total income: 0.00

Goodbye

swalls@george:~/Desktop/a2$ ./q2 12+53-*
Result = 6.00
