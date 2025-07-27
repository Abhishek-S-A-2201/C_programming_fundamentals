#include <stdio.h>
#include <stdlib.h>
#define INIT_CAP 4

void print_options();
int get_int_value(char *prompt);
void resize_array(int *ptr, int *len, int *cap);
void add_to_array(int *ptr, int *len, int *cap);
void pop_from_array(int *ptr, int *len, int *cap);
void print_array(int *ptr, int len);

int main(void)
{
    int choice, len = 0, cap = INIT_CAP;
    int *array = (int *)malloc(sizeof(int));

    while (1)
    {
        print_options();
        choice = get_int_value("Enter your choice: ");
        if (choice == 4)
        {
            printf("Thank you...\n");
            break;
        }

        switch (choice)
        {
        case 1:
            printf("\nAdding to the array\n");
            add_to_array(array, &len, &cap);
            break;

        case 2:
            printf("\nSubtracting from the array\n");
            pop_from_array(array, &len, &cap);
            break;

        case 3:
            printf("\nPrinting the array\n");
            print_array(array, len);
            break;

        default:
            printf("\nInvalid choice try again...\n");
            break;
        }
    }

    return 0;
}

int get_int_value(char *prompt)
{
    char buffer[10];
    int number;

    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    number = atoi(buffer);
    return number;
}

void print_options()
{
    printf("\n***************************\n");
    printf("1. Add to the array\n");
    printf("2. Pop from the array\n");
    printf("3. Print the array\n");
    printf("4. To Quit\n");
    printf("***************************\n");
}

void resize_array(int *ptr, int *len, int *cap)
{

    if (*len < *cap && *len >= *cap / 2)
    {
        printf("Current length of the array: %d\n", *len);
        printf("Current capacity of the array: %d\n", *cap);
        return;
    }

    if (*len < (*cap / 2))
    {
        *cap /= 2;
    }
    else
    {
        *cap *= 2;
    }

    int *new_array = (int *)malloc(*cap * sizeof(int));

    for (int i = 0; i < *len; i++)
    {
        *(new_array + i) = *(ptr + i);
    }
    print_array(new_array, *len);

    int *temp = ptr;
    ptr = new_array;

    // free(temp);
    temp = NULL;

    printf("Resizing Array...\n");
    printf("Updated capacity of the array: %d\n", *cap);
}

void add_to_array(int *ptr, int *len, int *cap)
{
    int ele = get_int_value("Enter the element you want to add: ");
    *(ptr + *len) = ele;
    *len += 1;
    resize_array(ptr, len, cap);
}

void pop_from_array(int *ptr, int *len, int *cap)
{
    if (*len == 0)
    {
        printf("The array is empty.\n");
        return;
    }
    *len -= 1;
    resize_array(ptr, len, cap);
}

void print_array(int *ptr, int len)
{
    if (len == 0)
    {
        printf("The array is empty.\n");
        return;
    }

    printf("The elements in the array are: \n");
    for (int i = 0; i < len; i++)
    {
        printf("Element %d - %d\n", (i + 1), *(ptr + i));
    }
}