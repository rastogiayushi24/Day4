#include <stdio.h>
#include <string.h>

struct Employee_t {
    int id;
    char name[20];
    float salary;
    char department[30];
};

typedef struct Employee_t Employee;

void readEmployee(Employee emp[], int n);
void displayEmployee(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter number of employees: ");
    scanf("%d", &employeeCount);
    Employee employee[100];
    readEmployee(employee, employeeCount);
    displayEmployee(employee, employeeCount);
    
    Employee highestSalariedEmployee = findHighestSalary(employee, employeeCount);
    printf("Employee with highest salary: %s, %.2f (%s)\n", highestSalariedEmployee.name, highestSalariedEmployee.salary, highestSalariedEmployee.department);

    return 0;
}

void readEmployee(Employee emp[], int n) {
    printf("Enter details (ID, Name, Salary, Department):\n");
    for (int i = 0; i < n; i++) {
       
        scanf("%d %19s %f %29s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
}

void displayEmployee(Employee emp[], int n) {
    printf("Employees:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s - %.2f - %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

Employee findHighestSalary(Employee emp[], int n) {
    Employee highestSalaried = emp[0];
    for (int i = 1; i < n; i++) { 
        if (emp[i].salary > highestSalaried.salary) {
            highestSalaried = emp[i];
        }
    }
    return highestSalaried;
}
