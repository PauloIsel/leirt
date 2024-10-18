#include <stdio.h>

#define MAX 100

typedef struct {
    int name[MAX];
    int age;
    float marks;
} student_t;

float average_marks(student_t *s1, student_t *s2) {
    return (s1->marks + s2->marks) / 2;
}    

int main() {
    student_t student_1, student_2;

    printf("Enter student 1 details.\n");

    printf("Name: ");
    scanf("%s", student_1.name);

    printf("Age: ");
    scanf("%d", &student_1.age);
    
    printf("Marks: ");
    scanf("%f", &student_1.marks);

    printf("Enter student 2 details.\n");

    printf("Name: ");
    scanf("%s", student_2.name);

    printf("Age: ");
    scanf("%d", &student_2.age);
    
    printf("Marks: ");
    scanf("%f", &student_2.marks);


    printf("\nStudent 1: %s\n", student_1.name);
    printf("Age: %d\n", student_1.age);
    printf("Marks: %.2f\n", student_1.marks);
    
    printf("\nStudent 2: %s\n", student_2.name);
    printf("Age: %d\n", student_2.age);
    printf("Marks: %.2f\n", student_2.marks);

    printf("\nAverage marks: %.2f\n", average_marks(&student_1, &student_2));

    return 0;
}
