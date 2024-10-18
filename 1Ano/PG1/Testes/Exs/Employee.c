#include <stdio.h>

typedef struct{
    char ID[50];
    char Name[50];
    float salary;
} Employee_t;

void highest_salary(Employee_t *employee1, Employee_t *employee2, Employee_t *employee3 , Employee_t *Employer) {
    if (employee1->salary > employee2->salary) {
        Employer->salary = employee1->salary;
        for (int i = 0; i < 50; i++) {
            Employer->ID[i] = employee1->ID[i];
            Employer->Name[i] = employee1->Name[i];
        }
    } else {
    Employer->salary = employee2->salary;
    for (int i = 0; i < 50; i++) {
        Employer->ID[i] = employee2->ID[i];
        Employer->Name[i] = employee2->Name[i];
    }
    }
    if (employee1->salary > employee3->salary) {
        Employer->salary = employee1->salary;
        for (int i = 0; i < 50; i++) {
            Employer->ID[i] = employee1->ID[i];
            Employer->Name[i] = employee1->Name[i];
        }
    } else {
        Employer->salary = employee3->salary;
        for (int i = 0; i < 50; i++) {
            Employer->ID[i] = employee3->ID[i];
            Employer->Name[i] = employee3->Name[i];
        }
    }

    if (employee2->salary > employee3->salary) {
        Employer->salary = employee2->salary;
        for (int i = 0; i < 50; i++) {
            Employer->ID[i] = employee2->ID[i];
            Employer->Name[i] = employee2->Name[i];
        }
    } else {
        Employer->salary = employee3->salary;
        for (int i = 0; i < 50; i++) {
            Employer->ID[i] = employee3->ID[i];
            Employer->Name[i] = employee3->Name[i];
        }
    }
}

int main() {
    Employee_t employee1, employee2, employee3, Employer;

    printf("Enter Employee 1 ID: ");
    scanf("%s", employee1.ID);
    printf("Enter Employee 1 Name: ");
    scanf("%s", employee1.Name);
    printf("Enter Employee 1 Salary: ");
    scanf("%f", &employee1.salary);

    printf("\nEnter Employee 2 ID: ");
    scanf("%s", employee2.ID);
    printf("Enter Employee 2 Name: ");
    scanf("%s", employee2.Name);
    printf("Enter Employee 2 Salary: ");
    scanf("%f", &employee2.salary);

    printf("\nEnter Employee 3 ID: ");
    scanf("%s", employee3.ID);
    printf("Enter Employee 3 Name: ");
    scanf("%s", employee3.Name);
    printf("Enter Employee 3 Salary: ");
    scanf("%f", &employee3.salary);
    
    highest_salary(&employee1, &employee2, &employee3, &Employer);

    printf("Highest Salary: %.2f\n", Employer.salary);
    printf("Employee ID: %s\n", Employer.ID);
    printf("Employee Name: %s\n", Employer.Name);
}