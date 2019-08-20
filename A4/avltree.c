/* Spencer Walls, 0734584 */
/* November 26th, 2018 */
/* Assignment #4 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This type definition defines the node 
data type for the nodes that populate the 
avl tree; it includes fields for a node's
key, frequency, height, and left and right
child */
typedef struct node 
{
	char key[20];
	int frequency;
	int height;
	struct node *left;
	struct node *right;
} node; 

node *inserted_key = NULL;
int frequency_count = 0; 
int size_count = 0;

/* This function takes two integers as
arguments and returns the larger of the two */
int max(int left, int right)
{
	if (right > left)
	{
		return right;
	}
	else
	{
		return left;
	}
}

/* This function takes a pointer to a node as an
argument and returns the height of this node */
int height(node *element)
{
	if (element != NULL)
	{
		return element->height;
	}
	else 
	{
		return -1; 
	}
}

/* This function takes a pointer to a node that is
the root of a subtree as an argument; it performs a
single right rotation and returns the new root of
the subtree */
 node *single_right(node *element)
 {
 	node *temp = element->left;
 	element->left = temp->right;
 	temp->right = element;
 	element->height = max(height(element->left), height(element->right)) + 1;
 	temp->height = max(height(temp->left), height(temp->right)) + 1;
 	return temp;
 }

/* This function takes a pointer to a node that is
the root of a subtree as an argument; it performs a
single left rotation and returns the new root of
the subtree */
node *single_left(node *element)
{
	node *temp = element->right;
	element->right = temp->left;
	temp->left = element;
	element->height = max(height(element->left), height(element->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

/* This function takes a pointer to a node that is
the root of a subtree as an argument; it performs a
double left-right rotation and returns the new
root of the subtree */
node *double_left_right(node *element)
{
	element->left = single_left(element->left);
	return single_right(element);
}

/* This function takes a pointer to a node that is
the root of a subtree as an argument; it performs a
double right-left rotation and returns the new
root of the subtree */
node *double_right_left(node *element)
{
	element->right = single_right(element->right);
	return single_left(element);
}

/* This function takes a pointer to a key and a pointer
to a node (the root of a tree) as arguments; it searches
the tree for a node with this key. If the key is found,
a pointer to this node is returned; otherwise, a NULL
pointer is returned */
node *find_key(char *key, node *ptr) 
{
	if (ptr == NULL)
	{
		return NULL;
	}
	if (strcmp(key, ptr->key) < 0) //if key < ptr->key
	{
		return find_key(key, ptr->left);
	}
	else if (strcmp(key, ptr->key) > 0) //if key > ptr->key
	{
		return find_key(key, ptr->right);
	}
	else //if key == ptr->key
	{
		return ptr;
	}
}

/* This function takes a pointer to a key as an argument;
it creates a node that has this key, sets the frequency
to one, the height to zero, and the pointers to the left 
and right child to NULL, and then returns a pointer to 
this new node */
node *new_node(char *key)
{
	node *temp = malloc(sizeof(node));
	strcpy(temp->key, key);
	temp->frequency = 1;
	temp->height = 0;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* This function takes a pointer to a node as an argument;
if the pointer does not point to NULL, the balance factor 
of this node is returned; otherwise, zero is returned */
int get_balance(node *node) 
{
	if (node != NULL)
	{
		return height(node->left) - height(node->right);
	}
	else 
	{
		return 0;
	}
}

/* This function takes a pointer to a key and a pointer to
a node (root of a tree) as arguments; if a node with this
key already exists, the frequency of this node is simply 
increased; otherwise, a new node is created and inserted
into the tree, and the necessary rebalancing of its 
ancestors is implemented before returning a pointer 
to this node */
node *insert(char *key, node *ptr) 
{
	if (ptr == NULL)
	{
		ptr = new_node(key);
		inserted_key = ptr;
		return ptr;
	}
	if (strcmp(key, ptr->key) < 0) //if key < ptr->key
	{
		ptr->left = insert(key, ptr->left); 
	}
	else if (strcmp(key, ptr->key) > 0) //if key > ptr->key
	{
		ptr->right = insert(key, ptr->right); 
	}
	else if (strcmp(key, ptr->key) == 0) //if key == ptr->key
	{
		ptr->frequency++; 
		inserted_key = ptr;
		return ptr; 
	}

	ptr->height = max(height(ptr->left), height(ptr->right)) + 1;

	int balance = get_balance(ptr); 

	if (balance < -1 && strcmp(key, ptr->right->key) < 0) 
	{
		return double_right_left(ptr);
	}
	if (balance < -1 && strcmp(key, ptr->right->key) > 0)
	{
		return single_left(ptr);
	}
	if (balance > 1 && strcmp(key, ptr->left->key) < 0) 
	{
		return single_right(ptr);
	}
	if (balance > 1 && strcmp(key, ptr->left->key) > 0) 
	{
		return double_left_right(ptr);
	}

	return ptr;
}

/* This function takes a char pointer (which contains a file
name) as an argument; it reads the data from the file into a
tree data structure and returns the root of the tree */
node *read_file(char *list_name)
{
	char array[255];
	char *token = NULL;
	node *found = NULL; 
	node *tree = NULL;
	FILE *file = fopen(list_name, "r");

	if (file == NULL)
	{
		printf("Could not open file\n");
		return NULL;
	}

	while (fgets(array, 255, file) != NULL) 
	{
		token = strtok(array, " \n"); 
		while (token != NULL)	   
		{ 		
			found = find_key(token, tree);

			if (found == NULL)
			{
				tree = insert(token, tree);
			}
			else 
			{
				found->frequency++;
			}
			token = strtok(NULL, " \n"); 
		}
	}

	fclose(file);
	return tree;
}

/* This function takes a node pointer as an argument, 
and simply returns a pointer to the node that is found
to have the smallest key after searching the entire left
and right subtrees of the node passed as an argument */
node *minimum(node *ptr) 
{
	if (ptr == NULL)
	{
		return NULL;
	}
	else if (ptr->left == NULL)
	{
		return ptr;
	}
	else 
	{
		return minimum(ptr->left);
	}
}

/* This function takes an integer and a node pointer (the root)
as arguments; it simply traverses the tree and prints every node
that's frequency is greater than or equal to the integer passed */
void print_frequency(int frequency, node *ptr) 
{																			
	if (ptr == NULL)
	{
		return;
	}
	else if (ptr->frequency >= frequency)
	{
		printf("key: %s, frequency: %d\n", ptr->key, ptr->frequency);
	}
	print_frequency(frequency, ptr->left); 
	print_frequency(frequency, ptr->right);
	return; 
}

/* This function takes a pointer to a node (the root) as
an argument; it traverses the tree whilst maintaining a
count that is the sum of the frequencies of all the nodes
in the tree; it returns this frequency count */
int frequency(node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		frequency_count = frequency_count + ptr->frequency;
		frequency(ptr->left); 
		frequency(ptr->right);
		return frequency_count;
	}
}

/* This function takes a pointer to a node (the root) as
an argument; it traverses the tree whilst maintaining a
count that is the sum all the nodes in the tree (its size);
it returns this size count */
int size(node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		size_count++;
		size(ptr->left); 
		size(ptr->right);
		return size_count;
	}
}

/* This function takes a pointer to a key and a pointer to
a node as arguments; it searches the tree for a node that 
has this key; if found, this node is deleted and the required
rebalancing operations are implemented; a pointer to the
root node of the tree is returned */
node *delete(char *key, node *ptr) 
{
	if (ptr == NULL)
	{
		return ptr;
	}
	if (strcmp(key, ptr->key) < 0) 
	{
		ptr->left = delete(key, ptr->left);
	}
	else if (strcmp(key, ptr->key) > 0)
	{
		ptr->right = delete(key, ptr->right);
	}
	else //node with this key has been found
	{
		if ((ptr->left == NULL) || (ptr->right == NULL)) //has one or no children
		{
			node *temp = ptr->left ? ptr->left : ptr->right;

			if (temp == NULL) //has no children
			{
				temp = ptr;
				ptr = NULL;
			}
			else //has one child
			{
				*ptr = *temp; 
			}

			free(temp);
		}
		else //has two children
		{
			node *temp = minimum(ptr->right); //next node in an inorder traversal 
			strcpy(ptr->key, temp->key);
			ptr->frequency = temp->frequency;
			ptr->right = delete(temp->key, ptr->right);
		}
	}

	if (ptr == NULL) 
	{
		return ptr;
	}

	ptr->height = max(height(ptr->left), height(ptr->right)) + 1;

	int balance = get_balance(ptr);

	if ((balance > 1) && (get_balance(ptr->left) >= 0))
	{
		return single_right(ptr);
	}
	if ((balance > 1) && (get_balance(ptr->left) < 0))
	{
		return double_left_right(ptr);
	}
	if ((balance < -1) && (get_balance(ptr->right) > 0))
	{
		return double_right_left(ptr);
	}
	if ((balance < -1) && (get_balance(ptr->right) <= 0))
	{
		return single_left(ptr);
	}

	return ptr;
}

int main(void)
{
	node *tree = NULL;
	node *found = NULL;
	int tree_size = 0;
	int tree_height = 0;
	int tree_count = 0;
	int trans_code = 0;
	int frequency_input = 0;
	char file_name[16] = "A4_data_f18.txt";
	char key[20];

	while (trans_code != 7)
	{
		printf("\n");
		printf("1. Initialization\n");
		printf("2. Find\n");
		printf("3. Insert\n");
		printf("4. Remove\n");
		printf("5. Check Height, Size, and Total Count\n");
		printf("6. Find All (above a given frequency)\n");
		printf("7. Exit\n");
		printf("Enter a code (1 - 7) and hit Return\n");
		printf("avl/> ");

		scanf("%d", &trans_code);

		size_count = 0;
		frequency_count = 0; 

		switch(trans_code)
		{
			case 1:
				tree = read_file(file_name);
				break;
			case 2:
				if (tree == NULL)
				{
					printf("Error: must select transaction code 1 to initialize the tree\n");
					break;
				}
				printf("find key: ");
				scanf("%s", key);
				found = find_key(key, tree);
				if (found != NULL)
				{
					printf("key: %s, frequency: %d\n", found->key, found->frequency);
				}
				else
				{
					printf("no_such_key\n");
				}
				break;
			case 3:
				if (tree == NULL)
				{
					printf("Error: must select transaction code 1 to initialize the tree\n");
					break;
				}
				printf("insert key: ");	
				scanf("%s", key);
				tree = insert(key, tree);
				if (inserted_key != NULL)
				{
					printf("key: %s, frequency: %d\n", inserted_key->key, inserted_key->frequency);
				}
				break;
			case 4: 
				if (tree == NULL)
				{
					printf("Error: must select transaction code 1 to initialize the tree\n");
					break;
				}
				printf("remove key: ");	
				scanf("%s", key);
				found = find_key(key, tree);
				if (found != NULL && found->frequency > 1)
				{
					found->frequency--;
					printf("key: %s, frequency: %d\n", found->key, found->frequency);
				}
				else if (found != NULL && found->frequency <= 1)
				{
					tree = delete(key, tree);
					printf("key: %s, frequency: 0\n", key);
				}
				else
				{
					printf("no_such_key\n");
				}
				break;
			case 5:
				if (tree == NULL)
				{
					printf("Error: must select transaction code 1 to initialize the tree\n");
					break;
				}
				tree_height = max(height(tree->left), height(tree->right)) + 1;
				tree_size = size(tree);
				tree_count = frequency(tree);
				printf("height: %d, size: %d, total count: %d\n", tree_height, tree_size, tree_count);
				break;
			case 6:
				if (tree == NULL)
				{
					printf("Error: must select transaction code 1 to initialize the tree\n");
					break;
				}
				printf("frequency: ");
				scanf("%d", &frequency_input);
				print_frequency(frequency_input, tree);
				break;
			case 7:
				printf("Goodbye\n");
				exit(0);	
			default:
				printf("Invalid transaction code\n");
				break;	
		}
	}
}