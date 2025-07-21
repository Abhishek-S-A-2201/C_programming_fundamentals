#include <stdio.h>
#include <math.h>

int main(void)
{

    int age, fav_no, height;
    float weight, bmi;
    char name[50];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your age (in years): ");
    scanf("%d", &age);

    printf("Enter your height (in cm): ");
    scanf("%d", &height);

    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter your favourite number (1-100): ");
    scanf("%d", &fav_no);

    bmi = weight / pow((height / 100.0), 2);

    printf("----------------------------------\n");

    printf("Hello %d year/s old, %s\n", age, name);
    printf("Looks like your favouriter number is %d\n", fav_no);
    printf("Your BMI comes up to %.2f\n", bmi);
    printf("Thank you!\n");

    return 0;
}