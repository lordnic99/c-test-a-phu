#include "../include/employee.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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

bool emptyLineCheck(char *line) {
  if (isspace(line[0])) {
    return true;
  }
  return false;
}

void importFromFile(employee_list_t **head_employee_list,
                    const char *file_name) {
  FILE *file_to_import = fopen(file_name, "r");
  if (!file_to_import) {
    printf("File open failed!");
    return;
  }
  char name[64];
  double salary;
  char buffer_read[255];
  while (fgets(buffer_read, sizeof(buffer_read), file_to_import)) {
    printf("%s",buffer_read);
    if (emptyLineCheck(buffer_read)) {
      continue;
    }
    printf("%s",buffer_read);
    // addEmployee(head_employee_list, name, salary);
  }
}
int main(int charc, char *argv[]) {
  employee_list_t *head_employee_list = NULL;
  int amount_employee;
  if (charc == 2) {
    const char *file_name = argv[1];
    importFromFile(&head_employee_list, file_name);
  } else {
    printf("How many employee: ");
    scanf("%d", &amount_employee);
  }
  // for (int i = 0; i < amount_employee; ++i) {
  //   char *name = getName();
  //   double salary = getSalary();
  //   addEmployee(&head_employee_list, name, salary);
  // }
  // showAllEmployee(head_employee_list);
  // removeEmployee(&head_employee_list, "hoang");
  showAllEmployee(head_employee_list);
  return 0;
}
