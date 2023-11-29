#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void displayEmployee(const struct Employee *employee) {
    printf("ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Salary: %.2f\n", employee->salary);
}

int main() {
    FILE *file = fopen("employees.dat", "wb+");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    for (int i = 0; i < numEmployees; ++i) {
        struct Employee employee;
        printf("Enter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employee.id);
        printf("Name: ");
        scanf("%s", employee.name);
        printf("Salary: ");
        scanf("%f", &employee.salary);

        fseek(file, employee.id * sizeof(struct Employee), SEEK_SET);
        fwrite(&employee, sizeof(struct Employee), 1, file);
    }

    int searchId;
    printf("\nEnter the employee ID to search: ");
    scanf("%d", &searchId);

    fseek(file, searchId * sizeof(struct Employee), SEEK_SET);
    struct Employee foundEmployee;
    fread(&foundEmployee, sizeof(struct Employee), 1, file);

    printf("\nDetails of Employee with ID %d:\n", searchId);
    displayEmployee(&foundEmployee);

    fclose(file);

    return 0;
}
