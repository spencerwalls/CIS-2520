/* Spencer Walls, 0734584 */
/* November 5th, 2018 */
/* Assignment #3 */
/* Question #1 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX]; //regular stack
float stack_operands[MAX]; //stack strictly for floats, i.e. operands
int top = -1;

/* This function takes a char as an argument; if the stack is
full, an error message is printed; otherwise, the char is pushed
onto the stack */

void push(char element) 
{
	if (top == MAX - 1)
    {
        printf("Error: full stack\n");
        exit(0);
    }
    else
    {
        top++;
        stack[top] = element;
    }
}

/* This function takes no arguments; if the stack is empty, an error
message is printed; otherwise, it pops and returns the top element
of the stack */

char pop()
{
    if (top == -1)
    {
        printf("Error: empty stack\n");
        exit(0);
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}

/* This function takes a float as an argument; if the stack is
full, an error message is printed; otherwise, the float is pushed
onto the stack */

void push_digit(float digit)
{
    if (top == 100)
    {
        printf("Error: full stack\n");
        exit(0);
    }
    else
    {
        ++top;
        stack_operands[top] = digit;
    }
}

/* This function takes no arguments; if the stack is empty, an error
message is printed; otherwise, it pops and returns the top element
of the stack */

float pop_digit()
{
    if (top == -1)
    {
        printf("Error: empty stack\n");
        exit(0);
    }
    else
    {
        --top;
        return stack_operands[top + 1];
    }
}

/* This function takes an operator as an argument, and executes
 different push() and pop() operations on a stack with respect
 to the operator that is passed */ 

void operate(char operator)
{
	float temp_1, temp_2;
	switch(operator)
  {
	case '+':
		temp_1 = pop_digit();
		temp_2 = pop_digit();
		push_digit((temp_2 + temp_1));
		break;
	case '-':
		temp_1 = pop_digit();
		temp_2 = pop_digit();
		push_digit((temp_2 - temp_1));
		break;
	case '/':
		temp_1 = pop_digit();
		temp_2 = pop_digit();
		push_digit((temp_2 / temp_1));
		break;
	case '*':
		temp_1 = pop_digit();
		temp_2 = pop_digit();
		push_digit((temp_2 * temp_1));
		break;
	}
}

/* This function takes an operator as an argument,
and simply returns the operator's precedence with
respect to the mathematical order of operations*/

int precedence(char operator)
{
	if (operator == '*' || operator == '/')
	{
		return(2);
	}
	else if (operator == '+' || operator == '-')
	{
		return(1);
	}
	else 
	{
		return(0);
	}
}

/* This function takes a string as input, and simply
returns the string in precisely reversed order */

char *string_reverse(char *string)
{
      char *ptr_1, *ptr_2;

      if (string == NULL)
      {
            return 0;
      }
      for (ptr_1 = string, ptr_2 = string + strlen(string) - 1; ptr_1 < ptr_2; ptr_1++, ptr_2--)
      {
            *ptr_1 ^= *ptr_2;
            *ptr_2 ^= *ptr_1;
            *ptr_1 ^= *ptr_2;
      }
      return string;
}

/* Below is one struct type definition and four different functions
that I coded for the tree representation; however, none of these are
actually operational since I did not include the printing of a tree */ 

typedef struct node {
	char *element;
	struct node *left;
	struct node *right;
	struct node *next;
} node;

node *head = NULL;

node *new_node(char *element)
{
	node *temp;
	temp = malloc(sizeof(struct node));
	strcpy(temp->element, element);
	temp->left = temp->right = NULL;
	return temp;
}

void push_node(node *head, node *newNode)
{
	node *temp = malloc(sizeof(struct node));
	strcpy(temp->element, newNode->element);
	temp->next = head;
	head = temp;
}

node *pop_node()
{
	node *temp = head;
	node *node_new = malloc(sizeof(struct node));
	strcpy(node_new->element, head->element);
	node_new->right = head->right;
	node_new->left = head->left;
	head = head->next;
	free(temp);
	return node_new;
}

/* Main function begins here */

int main(int argc, char *argv[])
{
	char expression[50];
	char expression_final[50];
	char reversed_expression[50];
	char reversed_postfix[50];
	char element;
	char operator;

	char var_name_1[4] = " ";
	char var_name_2[4] = " ";
	char var_name_3[4] = " ";
	char var_name_4[4] = " ";

	char var_value_1[6] = " ";
	char var_value_2[6] = " ";
	char var_value_3[6] = " ";
	char var_value_4[6] = " ";

	char variable_name[2];
	char variable_value[4];
	char name_temp[4];
	char value_temp[6];

	int expression_length;
	int expression_final_length;
	int user_input = 1;
	int i = 0;
	int j = 0;
	int m = 0;

	if (argc != 2) //exactly two arguments must be passed including
	{              //the executable and the expression
        printf("Error: invalid number of arguments\n");
        printf("Exactly 2 arguments must be entered\n");
        return -1;
 	}

	strcpy(expression, argv[1]);
	strcpy(expression_final, expression);

 	while (user_input != 7)
 	{

 		printf("\n");
 		printf("1. Display\n");
 		printf("2. Preorder\n");
 		printf("3. Inorder\n");
 		printf("4. Postorder\n");
 		printf("5. Update\n");
 		printf("6. Calculate\n");
 		printf("7. Exit\n\n");
 		scanf("%d", &user_input);

 		expression_length = strlen(expression);
 		expression_final_length = strlen(expression_final);

	 	switch(user_input)
	 	{	
	 		case 1:
	 			printf("Display\n\n"); //the below 'if statements' simply print
	 								   //the current variables and their values 
		 		if (isalpha(var_name_1[0]))
		 		{
		 			printf("%s: %s\n", var_name_1, var_value_1);
		 		}
		 		if (isalpha(var_name_2[0]))
		 		{
		 			printf("%s: %s\n", var_name_2, var_value_2);
		 		}
		 		if (isalpha(var_name_3[0]))
		 		{
		 			printf("%s: %s\n", var_name_3, var_value_3);
		 		}
		 		if (isalpha(var_name_4[0]))
		 		{
		 			printf("%s: %s\n", var_name_4, var_value_4);
		 		}
	 			 break;
	 		case 2:
	 			printf("Preorder:\n\n");

	 			strcpy(reversed_expression, expression);
	 			strcpy(reversed_expression, string_reverse(reversed_expression));

	 			char postfix_expression_2[50];
				char infix_expression_2[50];
				char postfix_final_2[50];
				int postfix_length_2;

				j = 0;

	    		for (i = 0; i < expression_length; i++)
			    {
			    	element = reversed_expression[i];

			    	if (element == '\\') //this simply parses the string and
			    	{				     //discards any backward slashes 
			    		;
			    	}
			    	else
			    	{
			    		infix_expression_2[j] = element;
			    		j++;
			    	}
	    		}

	    		infix_expression_2[j] = '\0'; 

	    		push(')');

	    		strcat(infix_expression_2, "(");

	    		i = 0;
	    		j = 0;
	    		
	    		element = infix_expression_2[i];

	    		while (element != '\0') //this 'while loop' converts the infix expression
	    		{						//to a postfix expression
	    			if (element == ')')
	    			{
	    				push(element);
	    			}
	    			else if (isdigit(element) || isalpha(element))
	    			{
	    				postfix_expression_2[j++] = element;
	    			}
	    			else if (element == '.')
	    			{
	    				postfix_expression_2[j++] = element;
	    			}
	    			else if (element == '*' || element == '/' || element == '+' || element == '-')
	    			{
	    				operator = pop();

	    				while ((operator == '*' || operator == '/' || operator == '+' || operator == '-')
	    					&& (precedence(operator) >= precedence(element)))
	    				{
	    						postfix_expression_2[j++] = operator;
	    						operator = pop();	    				
	    				}
	    				push(operator);
	    				push(element);
	    			}
	    			else if (element == '(')
	    			{
	    				operator = pop();

	    				while (operator != ')')
	    				{
	    					postfix_expression_2[j++] = operator;
	    					operator = pop();
	    				}
	    			}
	    			else
	    			{
	    				printf("Invalid infix expression\n");
	    				exit(1);
	    			}
	    			i++;
	    			element = infix_expression_2[i];
	    		}
	    		postfix_expression_2[j] = '\0';

	    		strcpy(reversed_postfix, string_reverse(postfix_expression_2));
	    		postfix_length_2 = strlen(postfix_expression_2); //reverse the postfix expression

	    		m = 0;

	    		for (i = 0; i < postfix_length_2;) //this 'for loop' adds spaces
	    		{								   //to improve readability
	    			if (isdigit(reversed_postfix[i]))
	    			{
		    			postfix_final_2[m] = reversed_postfix[i];
		    			postfix_final_2[m + 1] = reversed_postfix[i + 1];
		    			postfix_final_2[m + 2] = reversed_postfix[i + 2];
		    			postfix_final_2[m + 3] = reversed_postfix[i + 3];
		    			m += 4;
		    			postfix_final_2[m] = ' ';
		    			m++;
		    			i += 4;
		    		} 
		    		else if (isalpha(reversed_postfix[i]))
		    		{
		    			postfix_final_2[m] = reversed_postfix[i];
		    			postfix_final_2[m + 1] = reversed_postfix[i + 1];
		    			postfix_final_2[m + 2] = ' ';
		    			i += 2;
		    			m += 3;
		    		}
		    		else 
		    		{
		    			postfix_final_2[m] = reversed_postfix[i];
		    			postfix_final_2[m + 1] = ' ';
		    			m += 2;
		    			i += 1;
		    		}
		    	}

	    		postfix_final_2[m] = '\0';

	    		printf("%s\n", postfix_final_2);
	 			break;
	 		case 3:
	 			printf("Inorder:\n\n");

			    for (i = 0; i < expression_length; i++)
			    {
			    	element = expression[i];

			    	if (element == '\\') //this simply parses the string to
			    	{				     //discard any backward slashes 
			    		;
			    	}
			    	else
			    	{
			    		printf("%c", expression[i]);
			    	}
	    		}
	    		printf("\n");
	    		break; 
	    	case 4:
	    		printf("Postorder:\n\n");

    			char postfix_expression[50];
				char infix_expression[50];
				char postfix_final[50];
				int postfix_length;

				j = 0;

	    		for (i = 0; i < expression_length; i++) 
			    {
			    	element = expression[i];

			    	if (element == '\\')
			    	{
			    		;
			    	}
			    	else
			    	{
			    		infix_expression[j] = element;
			    		j++;
			    	}
	    		}

	    		infix_expression[j] = '\0'; 

	    		push('(');

	    		strcat(infix_expression, ")");

	    		i = 0;
	    		j = 0;

	    		element = infix_expression[i];

	    		while (element != '\0')  //this 'while loop' converts the infix expression
	    		{                        //to a postfix expression
	    			if (element == '(')
	    			{
	    				push(element);
	    			}
	    			else if (isdigit(element) || isalpha(element))
	    			{
	    				postfix_expression[j++] = element;
	    			}
	    			else if (element == '.')
	    			{
	    				postfix_expression[j++] = element;
	    			}
	    			else if (element == '*' || element == '/' || element == '+' || element == '-')
	    			{
	    				operator = pop();

	    				while ((operator == '*' || operator == '/' || operator == '+' || operator == '-')
	    					&& (precedence(operator) >= precedence(element)))
	    				{
	    						postfix_expression[j++] = operator;
	    						operator = pop();	    				
	    				}
	    				push(operator);
	    				push(element);
	    			}
	    			else if (element == ')')
	    			{
	    				operator = pop();

	    				while (operator != '(')
	    				{
	    					postfix_expression[j++] = operator;
	    					operator = pop();
	    				}
	    			}
	    			else
	    			{
	    				printf("Invalid infix expression\n");
	    				exit(1);
	    			}
	    			i++;
	    			element = infix_expression[i];
	    		}
	    		postfix_expression[j] = '\0'; 
	  
	    		postfix_length = strlen(postfix_expression);

	    		m = 0;

	    		for (i = 0; i < postfix_length;) //adds spaces for readability
	    		{
	    			if (isdigit(postfix_expression[i]))
	    			{
		    			postfix_final[m] = postfix_expression[i];
		    			postfix_final[m + 1] = postfix_expression[i + 1];
		    			postfix_final[m + 2] = postfix_expression[i + 2];
		    			postfix_final[m + 3] = postfix_expression[i + 3];
		    			m += 4;
		    			postfix_final[m] = ' ';
		    			m++;
		    			i += 4;
		    		}
		    		else if (isalpha(postfix_expression[i]))
		    		{
		    			postfix_final[m] = postfix_expression[i];
		    			postfix_final[m + 1] = postfix_expression[i + 1];
		    			m += 2;
		    			postfix_final[m] = ' ';
		    			m++;
		    			i += 2;
		    		}
		    		else 
		    		{
		    			postfix_final[m] = postfix_expression[i];
		    			postfix_final[m + 1] = ' ';
		    			m += 2;
		    			i += 1;
		    		}
		    	}

	    		postfix_final[m] = '\0';

	    		printf("%s\n", postfix_final);
	    		break;
	    	case 5: 
	    		printf("Variable name: "); 
	    		scanf("%s", variable_name); 
				strcpy(name_temp, variable_name);

	    		printf("Variable value: ");
		    	scanf("%s", variable_value);
				strcpy(value_temp, variable_value);

		    	char temp_expression[50];

		    	m = 0;
		    	j = 0;

		    	for (i = 0; i < expression_final_length; i++)
			    {
			    	element = expression_final[i];

			    	if (element == '\\')
			    	{
			    		;
			    	}
			    	else
			    	{
			    		temp_expression[j] = element;
			    		j++;
			    	}
	    		}

	    		temp_expression[j] = '\0';

	    		m = 0;

	    		//this 'for loop' parses the expression string and replaces the variables with their values
		    	for (i = 0; i < expression_final_length;) 
	    		{
	    			if ((temp_expression[i] == name_temp[0]) && (temp_expression[i + 1] == name_temp[1]))
	    			{
		    			expression_final[m] = variable_value[0];
		    			expression_final[m + 1] = variable_value[1];
		    			expression_final[m + 2] = variable_value[2];
		    			expression_final[m + 3] = variable_value[3];
		    			m += 4;
		    			i += 2;
		    		}
		    		else 
		    		{
		    			expression_final[m] = temp_expression[i];
		    			m++;
		    			i++;
		    		}
		    	}
	    		expression_final[m] = '\0';

	    		if ((isalpha(var_name_1[0]) == 0)) //these 'if statements' save the inputted 
		    	{								   //variable names to their respective strings
		    		strcpy(var_name_1, name_temp);
		    	}
		    	else if ((isalpha(var_name_2[0]) == 0))
		    	{
		    		strcpy(var_name_2, name_temp);
		    	}
		    	else if ((isalpha(var_name_3[0]) == 0))
		    	{
		    		strcpy(var_name_3, name_temp);
		    	}
		    	else if ((isalpha(var_name_4[0]) == 0))
		    	{
		    		strcpy(var_name_4, name_temp);
		    	}

	    		if ((isdigit(var_value_1[0]) == 0)) //these 'if statements' save the inputted 
		    	{									//variable values to their respective strings
		    		strcpy(var_value_1, value_temp);
		    	}
		    	else if ((isdigit(var_value_2[0]) == 0))
		    	{
		    		strcpy(var_value_2, value_temp);
		    	}
		    	else if ((isdigit(var_value_3[0]) == 0))
		    	{
		    		strcpy(var_value_3, value_temp);
		    	}
		    	else if ((isdigit(var_value_4[0]) == 0))
		    	{
		    		strcpy(var_value_4, value_temp);
		    	}
    			
	    		printf("The value of %s is now %s\n", name_temp, value_temp);
				break;
	    	case 6:
    			printf("Calculate:\n\n");

    		 	char postfix_expression_1[50];
				char infix_expression_1[50];
				char postfix_final_1[50];
				char *array[50];
				char *str_ptr;
				char *token; 
				int postfix_length_1;

				j = 0;

	    		for (i = 0; i < expression_final_length; i++)
			    {
			    	element = expression_final[i];

			    	if (element == '\\')
			    	{
			    		;
			    	}
			    	else
			    	{
			    		infix_expression_1[j] = element;
			    		j++;
			    	}
	    		}

	    		infix_expression_1[j] = '\0'; //null terminate your string!

	    		push('(');

	    		strcat(infix_expression_1, ")");

	    		i = 0;
	    		j = 0;

	    		element = infix_expression_1[i];

	    		while (element != '\0') //convert infix to postfix to calculate
	    		{
	    			if (element == '(')
	    			{
	    				push(element);
	    			}
	    			else if (isdigit(element) || isalpha(element))
	    			{
	    				postfix_expression_1[j++] = element;
	    			}
	    			else if (element == '.')
	    			{
	    				postfix_expression_1[j++] = element;
	    			}
	    			else if (element == '*' || element == '/' || element == '+' || element == '-')
	    			{
	    				operator = pop();

	    				while ((operator == '*' || operator == '/' || operator == '+' || operator == '-')
	    					&& (precedence(operator) >= precedence(element)))
	    				{
	    						postfix_expression_1[j++] = operator;
	    						operator = pop();	    				
	    				}
	    				push(operator);
	    				push(element);
	    			}
	    			else if (element == ')')
	    			{
	    				operator = pop();

	    				while (operator != '(')
	    				{
	    					postfix_expression_1[j++] = operator;
	    					operator = pop();
	    				}
	    			}
	    			else 
	    			{
	    				printf("Invalid infix expression\n");
	    				exit(1);
	    			}
	    			i++;
	    			element = infix_expression_1[i];
	    		}
	    		postfix_expression_1[j] = '\0'; 
	   
	    		postfix_length_1 = strlen(postfix_expression_1);
	    		
	    		m = 0;

	    		for (i = 0; i < postfix_length_1;) //add spaces for readability
	    		{
	    			if (isdigit(postfix_expression_1[i]))
	    			{
		    			postfix_final_1[m] = postfix_expression_1[i];
		    			postfix_final_1[m + 1] = postfix_expression_1[i + 1];
		    			postfix_final_1[m + 2] = postfix_expression_1[i + 2];
		    			postfix_final_1[m + 3] = postfix_expression_1[i + 3];
		    			m += 4;
		    			postfix_final_1[m] = ' ';
		    			m++;
		    			i += 4;
		    		} 
		    		else if (isalpha(postfix_expression_1[i]))
		    		{
		    			printf("Warning: variable %c%c does not have a value\n", postfix_expression_1[i], postfix_expression_1[i + 1]);
		    			i++;
		    		}
		    		else 
		    		{
		    			postfix_final_1[m] = postfix_expression_1[i];
		    			m++;
		    			postfix_final_1[m] = ' ';
		    			m++;
		    			i += 1;
		    		}
		    	}
	    		postfix_final_1[m] = '\0';

				str_ptr = postfix_final_1;
				token = strtok(str_ptr, " ");

				i = 0;

				do { //this 'do-while loop' separates floats, variables, and operators
					array[i] = token; //into distinct tokens 
					token = strtok(NULL, " ");
					i++;
				} while(token != NULL);
					
				for (j = 0; j < i; j++) //this 'for loop' invokes the evaluation of the expression
				{						//by using a stack 
					if (isdigit(*array[j]))
					{
						push_digit(atof(array[j]));																									 
					}
					else
					{
						operate(*array[j]);
					}
				}

    			for (i = 0; i < expression_length; i++)
			    {
			    	element = expression[i];

			    	if (element == '\\') //remove backward slashes
			    	{
			    		;
			    	}
			    	else
			    	{
			    		printf("%c", expression[i]);
			    	}
	    		}				
	    		printf("\n\n");
				printf("Result = %.2f\n", stack_operands[0]);
				break;
			case 7:
				printf("Goodbye\n");
				exit(0);
				break;
			default:
				printf("Invalid selection\n");
				break;
		}
	}
}