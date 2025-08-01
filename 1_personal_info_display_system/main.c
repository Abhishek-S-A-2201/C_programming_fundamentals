#include <stdio.h>
#include <string.h>

int main(void){

    char name[50], profile[50]="", age_str[50], fav_str[50], character[2];
    int age, fav_num;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your favourite number: ");
    scanf("%d", &fav_num);

    sprintf(age_str, "%d", age);
    sprintf(fav_str, "%d", fav_num);

    if (name[0] != '\0') {
        sprintf(character, "%c", name[0]);
        strcat(profile, character);
    }
    
    for(int i=0; name[i] != '\0'; i++){
        if(name[i]==' ' && name[i+1] != '\0'){
            sprintf(character, "%c", name[i+1]);
            strcat(profile, character);
        }
    }
    strcat(profile, "-");
    strcat(profile, age_str);
    strcat(profile, "-");
    strcat(profile, fav_str);

    printf("\n=== PERSONAL PROFILE ===\n");
    printf("Name: %s\n", name);
    printf("Age: %d years old\n", age);
    printf("Favourite Number: %d\n", fav_num);
    printf("Profile ID: %s\n", profile);
    
    return 0;
}
