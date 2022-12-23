#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 5

// Define a struct to represent an employee
typedef struct {
    char name[100];
    int age;
    float salary;
} Employee;

int main(void) {
    // Create an array to hold the employee records
    Employee employees[MAX_EMPLOYEES] = { 0 }; // Initialize the array to all zeros to ensure it is properly initialized

    // Loop until the user enters "quit"
    char input[100] = { 0 }; // Initialize the input string to all zeros to ensure it is zero-terminated
    int num_employees = 0;
    while (num_employees < MAX_EMPLOYEES) {
        printf("Enter the name of employee %d (or 'quit' to exit): ", num_employees + 1);
        if (scanf_s("%99s", input, sizeof(input)) != 1) { // Use scanf_s to read the input string and check the return value to ensure that it was successful
            printf("Error reading input\n");
            return 1;
        }

        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Store the employee's name
        strcpy_s(employees[num_employees].name, sizeof(employees[num_employees].name), input); // Use strcpy_s to copy the input string to the employees array

        // Prompt for and store the employee's age
        printf("Enter the age of employee %d: ", num_employees + 1);
        if (scanf_s("%d", &employees[num_employees].age) != 1) { // Use scanf_s to read the age and check the return value to ensure that it was successful
            printf("Error reading input\n");
            continue; // If the age input was invalid, skip the rest of the current iteration and move on to the next one
        }

        // Prompt for and store the employee's salary
        printf("Enter the salary of employee %d: ", num_employees + 1);
        if (scanf_s("%f", &employees[num_employees].salary) != 1) { // Use scanf_s to read the salary and check the return value to ensure that it was successful
            printf("Error reading input\n");
            continue; // If the salary input was invalid, skip the rest of the current iteration and move on to the next one
        }

        num_employees++;
    }

    // Print the employee records
    printf("\nEmployee records:\n");

    for (int i = 0; i < num_employees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    return 0;
}
