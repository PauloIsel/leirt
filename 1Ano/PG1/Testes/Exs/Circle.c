#include <stdio.h>

#define pi 3.141592653589793238

typedef struct {
    double radius;
    double area;
    double perimeter;
} circle_t;

double circle_area(circle_t *circle) {
    double radius_squared = circle->radius * circle->radius;
    circle->area = pi * radius_squared;

    return circle->area;
}

double circle_perimeter(circle_t *circle) {
    circle->perimeter = 2 * pi * circle->radius;

    return circle->perimeter;
}

int main() {
    circle_t circle1, circle2;

    printf("Enter the radius of the first circle: ");
    scanf("%lf", &circle1.radius);

    printf("Enter the radius of the second circle: ");
    scanf("%lf", &circle2.radius);

    printf("\nThe area of the first circle is: %.2lf\n", circle_area(&circle1));
    printf("The perimeter of the first circle is: %.2lf\n", circle_perimeter(&circle1));

    printf("\nThe area of the second circle is: %.2lf\n", circle_area(&circle2));
    printf("The perimeter of the second circle is: %.2lf\n", circle_perimeter(&circle2));

    return 0;
}