#include "../include/employee_list.h"
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CLEAR_STDIN_BUFFER() {
  int c;
  while ((c = getc(stdin)) != '\n' && c != EOF)
    ;
}

bool isDigitOnly(const char *buffer) {
  int i = 0;
  while (buffer[i] != '\0') {
    if (!isdigit(buffer[i])) {
      printf("Incorrect salary!\n");
      return false;
    }
    ++i;
  }
  return true;
}

employee_list_t *createEmployeeNode() {
  employee_list_t *new_employee_node =
      (employee_list_t *)malloc(sizeof(*new_employee_node));
  new_employee_node->Next = NULL;
  new_employee_node->employee =
      (employee_t *)malloc(sizeof(*(new_employee_node->employee)));
  strcpy(new_employee_node->employee->name, getEmployeeName());
  new_employee_node->employee->salary = getEmployeeSalary();
  return new_employee_node;
}

char *getEmployeeName() {
  char *name = (char *)malloc(64);
  printf("Enter employee name: ");
  CLEAR_STDIN_BUFFER();
  fgets(name, 64, stdin);
  name[strlen(name) - 1] = '\0';
  return name;
}

double getEmployeeSalary() {
  char *salary_str = (char *)malloc(1024);
  do {
    printf("Enter employee salary: ");
    fgets(salary_str, 1024, stdin);
    salary_str[strlen(salary_str) - 1] = '\0';
  } while (!isDigitOnly(salary_str));
  double salary = strtod(salary_str, NULL);
  free(salary_str);
  return salary;
}

void addEmployee(employee_list_t **head_employee_list) {
  employee_list_t *new_employee = createEmployeeNode();
  new_employee->Next = *head_employee_list;
  *head_employee_list = new_employee;
  return;
}

void showAllEmployee(employee_list_t *head_employee_list) {
  employee_list_t *pHead = head_employee_list;
  size_t i = 1;
  if (pHead == NULL) {
    printf("Employee list was empty!");
    return;
  } else {
    printf("NO.\tNAME\t\t\t\tSALARY\n");
    printf("-----------------------------------------------------------\n");
    while (pHead) {
      printf("%-8lu", i);
      printf("%-32s", pHead->employee->name);
      printf("%-16f\n", pHead->employee->salary);
      printf("-----------------------------------------------------------\n");
      ++i;
      pHead = pHead->Next;
    }
  }
}

void removeEmployee(employee_list_t **head_employee_list, const char *employee_name) {
  employee_list_t *p = *head_employee_list;
  while(p) {
    if(strcmp(p->Next->employee->name, employee_name) == 0){
      break;
    }
    p = p->Next;
  }
  if(p == NULL){
    printf("Employee name incorrect!\n");
    return;
  }
  employee_list_t *employee_to_remove = p->Next;
  free(employee_to_remove);
  p->Next = p->Next->Next;
  return;
}

void freeEmployeeNode(employee_list_t *employee_node) {
  free(employee_node->employee);
  employee_node->employee = NULL;
  free(employee_node);
  employee_node = NULL;
}

void freeAllMemory(employee_list_t *head_employee_list) {
  employee_list_t *p = head_employee_list;
  while (head_employee_list) {
    head_employee_list = head_employee_list->Next;
    freeEmployeeNode(p);
    p = head_employee_list;
  }
}
