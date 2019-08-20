/* Spencer Walls, 0734584 */
/* October 15th, 2018 */
/* Assignment #2 */
/* Question #1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This type definition defines the car data type
with fields for license plate number, mileage,
return date, and its successor, represented by
plate, mileage, date, and next, respectively */

typedef struct car{
    char *plate;
    int mileage;
    int date;
    struct car *next;
}car;

/* This function takes a license plate number, mileage,
and return date as arguments, and returns a pointer
to a car whose fields are populated by these attributes */

car *create_car(char *plate, int mileage, int date)
{
    car *new_car;
    new_car = malloc(sizeof(car));
    new_car->plate = malloc(sizeof(strlen(plate + 1)));
    strcpy(new_car->plate, plate);
    new_car->mileage = mileage;
    new_car->date = date;
    new_car->next = NULL;
    return new_car;
}

/* This function takes as arguments a pointer to a linked list of cars
and a pointer to an individual car, denoted by list and new_car, respectively.
The individual car is added to the linked list, and a pointer to the linked
list is returned */

car *add_car(car *list, car *new_car)
{
    if (list == NULL)
    {
        list = new_car;
        return list;
    }
    else
    {
        new_car->next = list;
        list = new_car;
        return list;
    }
}

/* This function takes a pointer to a linked list of cars as an argument
and sorts it with respect to the return dates of the cars. This function
is only used for the 'rented' linked list */

void date_sort(car *list)
{
    car *current = list;
    car *head = list;
    char *temp_plate;
    int temp_mileage;
    int temp_date;
    int n = 0;
    int i, j;

    while (current->next != NULL)
    {
        n++;
        current = current->next;
    }

    for (i = 0; i < n - 1; i++) //bubble sort
    {
        current = head;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (current->date > current->next->date)
            {
                temp_plate = current->plate;
                temp_mileage = current->mileage;
                temp_date = current->date;

                current->plate = current->next->plate;
                current->mileage = current->next->mileage;
                current->date = current->next->date;

                current->next->plate = temp_plate;
                current->next->mileage = temp_mileage;
                current->next->date = temp_date;
            }
                current = current->next;
        }
    }
    return;
}

/* This function takes a pointer to a linked list of cars as an argument
and sorts it with respect to the mileage of the cars. This function
is only used for the 'available' linked list */

void mileage_sort(car *list)
{
    car *current = list;
    car *head = list;
    char *temp_plate;
    int temp_mileage;
    int temp_date;
    int n = 0;
    int i, j;

    while (current->next != NULL)
    {
        n++;
        current = current->next;
    }

    for (i = 0; i < n - 1; i++) //bubble sort
    {
        current = head;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (current->mileage > current->next->mileage)
            {
                temp_plate = current->plate;
                temp_mileage = current->mileage;
                temp_date = current->date;

                current->plate = current->next->plate;
                current->mileage = current->next->mileage;
                current->date = current->next->date;

                current->next->plate = temp_plate;
                current->next->mileage = temp_mileage;
                current->next->date = temp_date;
            }
                current = current->next;
        }
    }
    return;
}

/* This function takes a pointer to a linked list of cars
as an argument and returns a pointer that points to the head,
i.e. the first car in the linked list */

car *get_head(car *list)
{
    car *head = malloc(sizeof(car));
    head = list;
    return head;
}

/* This function takes a pointer to a linked list of cars as an argument
and simply prints the the respective fields for every car */

void print_list(car *list)
{
    if (list != NULL)
    {
        car *head = list;
        while (head->next != NULL)
        {
            printf("Plate number: %s Mileage: %d Return date: %d\n", head->plate, head->mileage, head->date);
            head = head->next;
        }
        printf("\n");
        return;
    }
    else
    {
        printf("Empty list\n");
        return;
    }
}

/* This function takes a pointer to a linked list of cars and
and a pointer to a license plate number as arguments and searches
the list for a car with this license plate number; if found, it
returns the mileage of the car with this license plate number */

int get_mileage(car *list, char *plate)
{
    car *temp = list;

    while (temp->next != NULL)
    {
        if (strcmp(plate, temp->plate) == 0)
        {
            return temp->mileage;
        }
        else
        {
            temp = temp->next;
        }
    }
    return -1;
}

/* This function takes a pointer to a linked list of cars and
and a pointer to a license plate number as arguments and searches
the list for a car with this license plate number; if found, it
removes the car with this license plate number from the linked list */

void remove_car(car *list, char *plate)
{
    car *previous = list;
    car *current = list;

    while (previous->next != NULL)
    {
        current = current->next;

        if (strcmp(plate, previous->plate) == 0)
        {
            previous->plate = current->plate;
            previous->mileage = current->mileage;
            previous->date = current->date;
            previous->next = current->next;
            free(current);
            return;
        }
        previous = previous->next;
    }
    return;
}

/* This function takes a pointer to a linked list of cars as an argument,
and reads car data into this linked list from a text file for every line
that starts with the string 'Available'. Thus, this function is only used
for the 'available-for-rent' linked list */

car *read_available(car *list)
{
    car *new_car = malloc(sizeof(car));
    FILE *file = fopen("data.txt", "r");
    char data[300];
    char *date_char;
    char *mileage_char;
    char *plate;
    char *token;
    int mileage;
    int date;

    while (fgets(data, 300, file) != NULL)
    {
        token = strtok(data, ",");

        if (strcmp(token, "Available") == 0)
        {
            plate = strtok(NULL, ",");
            mileage_char = strtok(NULL, ",");
            date_char = strtok(NULL, ",");

            mileage = atoi(mileage_char);
            date = atoi(date_char);
            new_car = create_car(plate, mileage, date);
            list = add_car(list, new_car);
        }
    }
        fclose(file);
        return list;
}

/* This function takes a pointer to a linked list of cars as an argument,
and reads car data into this linked list from a text file for every line
that starts with the string 'Rented'. Thus, this function is only used
for the 'rented' linked list */

car *read_rented(car *list)
{
    car *new_car = malloc(sizeof(car));
    FILE *file = fopen("data.txt", "r");
    char data[300];
    char *date_char;
    char *mileage_char;
    char *plate;
    char *token;
    int mileage;
    int date;

    while (fgets(data, 300, file) != NULL)
    {
        token = strtok(data, ",");

        if (strcmp(token, "Rented") == 0)
        {
            plate = strtok(NULL, ",");
            mileage_char = strtok(NULL, ",");
            date_char = strtok(NULL, ",");

            mileage = atoi(mileage_char);
            date = atoi(date_char);
            new_car = create_car(plate, mileage, date);
            list = add_car(list, new_car);
        }
    }
        fclose(file);
        return list;
}

/* This function takes a pointer to a linked list of cars as an argument,
and reads car data into this linked list from a text file for every line
that starts with the string 'Repair'. Thus, this function is only used
for the 'repair' linked list */

car *read_repair(car *list)
{
    car *new_car = malloc(sizeof(car));
    FILE *file = fopen("data.txt", "r");
    char data[300];
    char *date_char;
    char *mileage_char;
    char *plate;
    char *token;
    int mileage;
    int date;

    while (fgets(data, 300, file) != NULL)
    {
        token = strtok(data, ",");

        if (strcmp(token, "Repair") == 0)
        {
            plate = strtok(NULL, ",");
            mileage_char = strtok(NULL, ",");
            date_char = strtok(NULL, ",");

            mileage = atoi(mileage_char);
            date = atoi(date_char);
            new_car = create_car(plate, mileage, date);
            list = add_car(list, new_car);
        }
    }
        fclose(file);
        return list;
}

/* This function takes three pointers to three different linked lists
as arguments, for the available-for-rent, rented, and repair lists,
denoted by available, rented, and repair, respectively. The data from
these lists are written to an individual text file that stores the
information of the three lists, including the license plate number,
mileage, and return date for every car. Note: for the available and
repair lists, the return date is always equal to zero since this is
not a relevant field for cars in these two lists */

void write_lists(car *available, car *rented, car *repair)
{
    car *current_available = available;
    car *current_rented = rented;
    car *current_repair = repair;
    FILE *file = fopen("data.txt", "w");

    while (current_available->next != NULL)
    {
        fprintf(file, "Available,%s,%d,%d\n", current_available->plate, current_available->mileage, current_available->date);
        current_available = current_available->next;
    }
    while (current_rented->next != NULL)
    {
        fprintf(file, "Rented,%s,%d,%d\n", current_rented->plate, current_rented->mileage, current_rented->date);
        current_rented = current_rented->next;
    }
    while (current_repair->next != NULL)
    {
        fprintf(file, "Repair,%s,%d,%d\n", current_repair->plate, current_repair->mileage, current_repair->date);
        current_repair = current_repair->next;
    }

    fclose(file);
    return;
}

int main(void)
{
    int user_input = 1;
    int date = 0;
    int plate_length;
    float income = 0;
    float total_income = 0;
    float mileage = 0;
    float mileage_difference = 0;
    float original_mileage = 0;
    char plate[9];

    car *new_car = NULL;
    car *head = NULL;

    car *available = malloc(sizeof(car)); //available-for-rent list
    car *rented = malloc(sizeof(car)); //rented list
    car *repair = malloc(sizeof(car)); //repair list

    available = read_available(available);
    rented = read_rented(rented);
    repair = read_repair(repair);

    while (user_input != 0)
    {
        total_income = total_income + income;
        income = 0; //resets the income to zero for each individual transaction

        printf("\n");
        printf("1. Add a new car to the available-for-rent list\n");
        printf("2. Add a returned car to the available-for-rent list\n");
        printf("3. Add a returned car to the repair list\n");
        printf("4. Transfer a car from the repair list to the available-for-rent list\n");
        printf("5. Rent the first available car\n");
        printf("6. Print all the lists\n");
        printf("7. Quit\n\n");

        scanf("%d", &user_input);
        printf("\n");
        mileage_sort(available); //sorts the available list at the beginning of every session
        date_sort(rented); //sorts the rented list at the beginning of every session

        switch(user_input){
        case 1:
            printf("Add a new car to the available-for-rent list:\n");
            printf("Enter the license plate number: ");
            scanf("%s", plate);
            plate_length = strlen(plate);

            while (plate_length != 7)
            {
                printf("Error: license plate must contain exactly 7 characters\n");
                printf("Please enter a valid license plate number: ");
                scanf("%s", plate);
                plate_length = strlen(plate);
            }

            original_mileage = get_mileage(available, plate); //see if license plate is already in use

            if (original_mileage != -1) //if license plate number is already in use
            {
                printf("\n");
                printf("A car with this license plate already exists\n");
            }
            else
            {
                printf("Enter the mileage of the car: ");
                scanf("%f", &mileage);
                printf("\n");
                new_car = create_car(plate, mileage, 0); //create a new car
                available = add_car(available, new_car); //add this car to the available-for-rent list
                printf("A new car with license plate number %s has been added to the available-for-rent list\n", plate);
            }
            break;
        case 2:
            printf("Add a returned car to the available-for-rent list\n");
            printf("Enter the license plate number: ");
            scanf("%s", plate);
            plate_length = strlen(plate);

            while (plate_length != 7) //license plate number must be exactly 7 characters long
            {
                printf("Error: license plate must contain exactly 7 characters\n");
                printf("Please enter a valid license plate number: ");
                scanf("%s", plate);
                printf("\n");
                plate_length = strlen(plate);
            }

            original_mileage = get_mileage(rented, plate); //see if license plate is already in use

            if (original_mileage == -1) //if license plate number is already in use
            {
                printf("\n");
                printf("A car with this license plate is not in the rented list\n");
            }
            else
            {
                printf("Enter the current mileage of the car: ");
                scanf("%f", &mileage);
                printf("\n");

                while (mileage < original_mileage)
                {
                    printf("The current mileage cannot be less than the original mileage of %.2f\n", original_mileage);
                    printf("Please enter the correct mileage: ");
                    scanf("%f", &mileage);
                    printf("\n");
                }

                remove_car(rented, plate); //remove the car from the rented list
                new_car = create_car(plate, mileage, 0);
                available = add_car(available, new_car); //add the car to the available-for-rent list

                mileage_difference = mileage - original_mileage;

                if (mileage_difference <= 100)
                {
                    income = 40;
                }
                else
                {
                    income = 40 + 0.15*(mileage_difference - 100);
                }

                printf("Transaction summary:\n\n");
                printf("plate number of returned car: %s\n\n", plate);
                printf("intial mileage: %.2f    current mileage: %.2f\n\n", original_mileage, mileage);
                printf("cost: %.2f\n\n", income);
                printf("*This car has been transferred from the rented list to the available-for-rent list*\n");
            }
            break;
        case 3:
            printf("Add a returned car to the repair list\n");
            printf("Enter the license plate number: ");
            scanf("%s", plate);
            plate_length = strlen(plate);

            while (plate_length != 7) //license plate number must be exactly 7 characters long
            {
                printf("Error: license plate must contain exactly 7 characters\n");
                printf("Please enter a valid license plate number: ");
                scanf("%s", plate);
                plate_length = strlen(plate);
            }

            original_mileage = get_mileage(rented, plate); //see if license plate is already in use

            if (original_mileage == -1) //if license plate number is already in use
            {
                printf("\n");
                printf("A car with this license plate is not in the rented list\n");
            }
            else
            {
                printf("Enter the current mileage of the car: ");
                scanf("%f", &mileage);
                printf("\n");

                while (mileage < original_mileage)
                {
                    printf("The current mileage cannot be less than the original mileage\n");
                    printf("Please enter the correct mileage: ");
                    scanf("%f", &mileage);
                }

                remove_car(rented, plate); //remove the car from the rented list
                new_car = create_car(plate, mileage, 0);
                repair = add_car(repair, new_car); //add the car to the repair list

                mileage_difference = mileage - original_mileage;

                if (mileage_difference <= 100)
                {
                    income = 40;
                    //total_income = total_income + income;//may delete
                }
                else
                {
                    income = 40 + 0.15*(mileage_difference - 100);//int cast?
                    //total_income = total_income + income;//may delete
                }

                printf("Transaction summary:\n\n");
                printf("plate number of returned car: %s\n\n", plate);
                printf("intial mileage: %.2f    current mileage: %.2f\n\n", original_mileage, mileage);
                printf("cost: %.2f\n\n", income);
                printf("*This car has been transferred from the rented list to the repair list*\n");
            }
                break;
            case 4:
                printf("Transfer a car from the repair list to the available-for-rent list\n");
                printf("Enter the license plate number: ");
                scanf("%s", plate);
                plate_length = strlen(plate);

                while (plate_length != 7)
                {
                    printf("Error: license plate must contain exactly 7 characters\n");
                    printf("Please enter a valid license plate number: ");
                    scanf("%s", plate);
                    plate_length = strlen(plate);
                }

                original_mileage = get_mileage(repair, plate); //see if license plate is already in use

                if (original_mileage == -1) //if license plate number is already in use
                {
                    printf("\n");
                    printf("A car with this license plate is not in the repair list\n");
                }
                else
                {
                    remove_car(repair, plate); //remove the car from the repair list
                    new_car = create_car(plate, original_mileage, 0);
                    available = add_car(available, new_car); //add the car to the available-for-rent list
                    printf("\n");
                    printf("A car with license plate number %s has been transferred from the repair list to the available-for-rent list\n", plate);
                }
                break;
            case 5:
                printf("Rent the first available car\n");
                printf("Enter the return date (yymmdd): ");
                scanf("%d", &date);
                printf("\n");
                int count = 0;
                int temp_count = 0;
                int temp_date = date;

                while (temp_date != 0) //this finds the number of digits in the entered
                {                      //return date and stores this number in 'count' variable
                    count++;
                    temp_date /= 10;
                }
                while (count != 6) //the return date must contain exactly 6 digits
                {                  //loop will execute until this condition is satisfied
                    temp_count = 0;
                    printf("Please enter a valid return date (yymmdd): ");
                    scanf("%d", &date);
                    temp_date = date;

                    while (temp_date != 0)
                    {
                        temp_count++;
                        temp_date /= 10;
                    }
                    count = temp_count;
                }

                head = get_head(available);
                new_car = create_car(head->plate, head->mileage, date);
                rented = add_car(rented, new_car); //add the car to the rented list
                remove_car(available, head->plate); //remove the car from the available list

                printf("Car with license plate number %s has been transferred from\n", new_car->plate);
                printf("the available-for-rent list to the rented list\n");
                break;
            case 6:
                printf("Print all the lists:\n\n");
                printf("Available-for-rent list\n\n");
                print_list(available);
                printf("Rented list\n\n");
                print_list(rented);
                printf("Repair list\n\n");
                print_list(repair);
                break;
            case 7:
                write_lists(available, rented, repair); //stores the lists in the text file
                printf("Total income: %.2f\n\n", total_income); //displays the total income of the session
                printf("Goodbye\n\n");
                return 0;
                break;
            default:
                printf("Invalid input\n\n");
                break;
        }
    }
}


