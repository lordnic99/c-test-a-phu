#include "../include/employee.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char *getName() {
  static char name[64];
  printf("Enter employee name: ");
  getchar(); // stdint buffer clear
  fgets(name, sizeof(name), stdin);
  name[strlen(name) - 1] = '\0';
  return name;
}

double getSalary() {
  static double salary;
  printf("Enter salary: ");
  scanf("%lf", &salary);
  return salary;
}

int main() {
  employee_list_t *head_employee_list = NULL;
  int amount_employee;
  printf("How many employee: ");
  scanf("%d", &amount_employee);
  for (int i = 0; i < amount_employee; ++i) {
    char *name = getName();
    double salary = getSalary();
    addEmployee(&head_employee_list, name, salary);
  }
  showAllEmployee(head_employee_list);
  removeEmployee(&head_employee_list, "hoang");
  showAllEmployee(head_employee_list);
  return 0;
}
