Spencer Walls, 0734584
Assignment #4

Running the program:

Following compilation using the 'make' command in the terminal, the program may be run by simply entering './avltree' at the command line. No command line arguments are required. Upon successful execution, a menu will be displayed with seven different options. Before any of the other options are selected, the first option, i.e. "1. Initialization", must be selected, otherwise an error message will be displayed. The user will continue to be prompted by the menu until the 7th command, i.e. the option to quit the program, has been selected, or any type of invalid input is entered (input that does not pertain to integers). 

note: the tree developed in this program does not include empty leaf nodes.

Sample output: 

Below contains sample output from compiling and then running the program. 'avltree' is simply entered at the command line and the program is executed. Every transaction code, i.e. 1 - 7, is selected and successfully implemented in this sample output. 

note: this sample output was generated in a Windows terminal.

*****************************************************************

C:\Users\Spencer\Desktop\temp>avltree

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 1

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 2
find key: wrn163
key: wrn163, frequency: 2

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 3
insert key: wrn163
key: wrn163, frequency: 3

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 4
remove key: wrn163
key: wrn163, frequency: 2

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 5
height: 12, size: 1488, total count: 174204

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 6
frequency: 3000
key: flr117, frequency: 7458
key: flr1453, frequency: 3085
key: flr1857, frequency: 3072
key: flr2910, frequency: 9790
key: flr2255, frequency: 3645
key: flr549, frequency: 5590

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height, Size, and Total Count
6. Find All (above a given frequency)
7. Exit
Enter a code (1 - 7) and hit Return
avl/> 7
Goodbye