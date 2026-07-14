#include<stdio.h>
struct book{
    char author[20];
    char title[20];
    char publisher[20];
    float price;
    float ISBN;
    int pages;
}
int main(){
    struct book b;
    printf("Enter the name of the author: ");
    scanf("%s", &b.author);
    printf("Enter the title of the book: ");
    scanf("%s", &b.title);
    printf("Enter the name of the publisher: ");
    scanf("%s", &b.publisher);
    printf("Enter the price of the book: ");
    scanf("%f", &b.price);
    printf("Enter the ISBN of the book: ");
    scanf("%f", &b.ISBN);
    printf("Enter the no. of pages: ");
    scanf("%d", &b.pages);


    printf("\nBook Details:\n");
    printf("Author: %s\n", b.author);
    printf("Title: %s\n", b.title);
    printf("Publisher: %s\n", b.publisher);
    printf("Price: $%.2f", b.price);
    printf("\nPages: %d\n", b.pages);
return 0;
}