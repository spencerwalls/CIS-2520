/* Spencer Walls, 0734584 */
/* October 15th, 2018 */
/* Assignment #2 */
/* Question #2 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float stack[100];
int top = -1;

/* This function takes an integer as an argument; if the stack is
full, an error message is printed; otherwise, the integer is pushed
onto the stack */

void push(int digit)
{
    if (top == 50)
    {
        printf("Error: full stack\n");
        exit(0);
    }
    else
    {
        ++top;
        stack[top] = digit;
    }
}

/* This function takes no arguments; if the stack is empty, an error
message is printed; otherwise, it pops and returns the top element
of the stack */

float pop()
{
    if (top == -1)
    {
        printf("Error: empty stack\n");
        exit(0);
    }
    else
    {
        --top;
        return stack[top + 1];
    }
}

int main(int argc, char const *argv[])
{
    char element;
    char post_fix_exp[100];
    float operand_1;
    float operand_2;
    int i = 0;

    if (argc != 2) //exactly two arguments must be passed including
    {              //the executable and the post-fix expression
        printf("Error: invalid number of arguments\n");
        printf("Exactly 2 arguments must be entered\n");
        return -1;
    }

    strcpy(post_fix_exp, argv[1]);

    while ((element = post_fix_exp[i++]) != '\0')
    {
        if (isdigit(element)) //if the element is a digit
        {                     //it is pushed onto the stack
            push(element - '0');
        }
        else
        {
            operand_2 = pop(); //if the element is an operator
            operand_1 = pop(); //the top two integers are popped
                               //from the stack and are used as
            switch(element)    //operands for the respective operation
            {
                case '+':
                    push(operand_1 + operand_2);
                    break;
                case '-':
                    push(operand_1 - operand_2);
                    break;
                case '*':
                    push(operand_1 * operand_2);
                    break;
                case '/':
                    push(operand_1 / operand_2);
                    break;
                default:
                    printf("Error: illegal operator\n");
                    printf("Only the following operators are permitted: +, -, *, /\n");
                    return -1; //only four operations are permitted
                    break;
            }
        }
    }
    printf("Result = %.2f\n", stack[top]); //stack[top] contains the final result
    return 0;                              //of the post-fix expression
}



