#include <stdio.h>
#include <string.h>
#include <limits.h>

void print_options(void);
int get_int_input(char *prompt);
void swap_integers(int* number1, int* number2);
int* get_int_array();
void traverse_array();
void array_min_max();

int main(void) {
    
    int choice;
    while(1){
        print_options();
        choice = get_int_input("Enter your choice: ");
        if(choice == 4){
            printf("Thank you!!\n");
            break;
        }

        switch (choice)
        {
        case 1:
            int firstNumber, secondNumber;
            printf("SWAPPING INTEGERS...\n");
            firstNumber = get_int_input("Enter the first number: ");
            secondNumber = get_int_input("Enter the second number: ");
            swap_integers(&firstNumber, &secondNumber);
            printf("AFTER SWAPPING...\n");
            printf("First Number: %d\n", firstNumber);
            printf("Second Number: %d\n", secondNumber);
            break;
        case 2:
            printf("TRAVERSING ARRAY OF INTEGERS...\n");
            traverse_array();
            break;
        case 3:
            printf("FIND THE MIN AND MAX IN AN ARRAY..\n");
            array_min_max();
            break;
        default:
            printf("Enter a valid choice...\n");
            break;
        }
    }
}

int get_int_input(char *prompt) {
    char buffer[10];
    int choice, result;
    
    while(1){
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        result = sscanf(buffer, "%d", &choice);
        if(result==1) break;
    }

    return choice;
}

void print_options(void){
    printf("\n===== POINTER PLAYGROUND =====\n");
    printf("1. Swap Integers\n");
    printf("2. Traverse Array\n");
    printf("3. Find Min Max of array\n");
    printf("4. QUIT\n");
    printf("==============================\n\n");
}

void swap_integers(int* number1, int* number2){
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void traverse_array(){
    int length = get_int_input("Enter the number of elements in the array: ");
    int array[length];

    for(int i = 0; i < length; i++){
        *(array+i) = get_int_input("Enter element: ");
    }
    for(int i = 0; i < length; i++){
        printf("Element %d - %d\n", (i+1), *(array+i));
    }
}

void array_min_max(){
    int length, min = INT_MAX, max = INT_MIN;
    length = get_int_input("Enter the number of elements in the array: ");
    int array[length];

    for(int i = 0; i < length; i++){
        *(array+i) = get_int_input("Enter element: ");
    }

    for(int i = 0; i < length; i++){
        min = *(array + i) < min ? *(array + i) : min;
        max = *(array + i) < max ? max : *(array + i);
    }

    printf("MINIMUM: %d\n", min);
    printf("MAXIMUM: %d\n", max);

}