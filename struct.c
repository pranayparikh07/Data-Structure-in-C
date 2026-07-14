#include<stdio.h>
struct cricketer{
    char name[20];
    int age;
    float strikerate;
    int matches;}c;

int main(){
    printf("Enter the name of the cricketer: ");
    scanf("%s", &c.name);
    printf("Enter the age of the cricketer: ");
    scanf("%d", &c.age);
    printf("Enter the strike rate of the cricketer: ");
    scanf("%f", &c.strikerate);
    printf("Enter the number of matches played by the cricketer: ");
    scanf("%d", &c.matches);

    printf("\nCricketer Details:\n");
    printf("Name: %s\n", c.name);
    printf("Age: %d\n", c.age);
    printf("Strike Rate: %.2f\n", c.strikerate);
    printf("Matches Played: %d\n", c.matches);

    return 0;
}