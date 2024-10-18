#include <stdio.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
};

int main() {
    struct Book book1, book2, book3;

    printf("Enter the first book's title: ");
    scanf("%s", book1.title);
    printf("Author of the book: ");
    scanf("%s", book1.author);
    printf("Price of the book: ");
    scanf("%f", &book1.price);

    printf("\nEnter the second book's title: ");
    scanf("%s", book2.title);
    printf("Author of the book: ");
    scanf("%s", book2.author);
    printf("Price of the book: ");
    scanf("%f", &book2.price);

    printf("\nEnter the third book's title: ");
    scanf("%s", book3.title);
    printf("Author of the book: ");
    scanf("%s", book3.author);
    printf("Price of the book: ");
    scanf("%f", &book3.price);

    struct Book most_expensive;
        if (book1.price >= book2.price && book1.price > book3.price) {
            most_expensive = book1;
        } else if (book2.price > book1.price && book2.price > book3.price) {
            most_expensive = book2;
        } else {
            most_expensive = book3;
        }

    struct Book Cheapest;
        if (book1.price < book2.price && book1.price < book3.price) {
            Cheapest = book1;
        } else if (book2.price < book1.price && book2.price < book3.price) {
            Cheapest = book2;
        } else {
            Cheapest = book3;
        }

    printf("\nMost expensive book\n");
    printf("Title: %s\n", most_expensive.title);
    printf("Author: %s\n", most_expensive.author);
    printf("Price: %.2f\n", most_expensive.price);

    printf("\nCheapest book\n");
    printf("Title: %s\n", Cheapest.title);
    printf("Author: %s\n", Cheapest.author);
    printf("Price: %.2f\n", Cheapest.price);

    return 0;
}