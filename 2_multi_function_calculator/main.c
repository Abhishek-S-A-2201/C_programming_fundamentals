#include <stdio.h>
#include <math.h>

int main(void){

    float num1, num2;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("\n======== RESULTS ========\n");
    printf("%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
    printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
    printf("%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
    if(num2 > 0){
        printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
        printf("%d %% %d = %d\n", (int)num1, (int)num2, (int)num1 % (int)num2);
    }

    return 0;
}