#include "../include/employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static employee_list_t *createEmployeeNode() {
  employee_list_t *new_employee = (employee_list_t *)malloc(sizeof(*new_employee));
  return new_employee;
}

void addEmployee(employee_list_t **head_employee_list, const char* name, double salary) {
  employee_list_t *new_employee = createEmployeeNode();
  strcpy(new_employee->name,name);
  new_employee->salary = salary;
  new_employee->next = NULL;
  if (!(*head_employee_list)) {
    *head_employee_list = new_employee;
    return;
  }
  employee_list_t *p = *head_employee_list;
  while (p && p->next) {
    p = p->next;
  }
  p->next = new_employee;
  return;
}

void showAllEmployee(employee_list_t *head_employee_list) {
  employee_list_t *p = head_employee_list;
  size_t i = 1;
  if (p == NULL) {
    printf("Employee list was empty!");
    return;
  } else {
    printf("NO.\tNAME\t\t\t\tSALARY\n");
    printf("-----------------------------------------------------------\n");
    while (p) {
      printf("%-8lu", i);
      printf("%-32s", p->name);
      printf("%-16f\n", p->salary);
      printf("-----------------------------------------------------------\n");
      ++i;
      p = p->next;
    }
  }
}

void removeEmployee(employee_list_t **head_employee_list, const char *employee_name) {
  employee_list_t *p = *head_employee_list;
  if(!p) {
    printf("Empty!");
    return;
  }
  /* check head */
  if(strcmp((*head_employee_list)->name, employee_name) == 0) {
    (*head_employee_list) = (*head_employee_list)->next;
    free(p);
    return;
  }

  /* check middle */
  while(p->next && p->next->next) {
    if(strcmp(p->name,employee_name) == 0){
    } 
    p=p->next;
  }

  /* Check end */
  if(strcmp(p->next->name, employee_name) == 0) {
    free(p->next);
    p->next = NULL;
    return;
  } 
  printf("Not found! Please try again!");
  return;
}

// void freeEmployeeNode(employee_list_t *employee_node) {
//   free(employee_node->employee);
//   employee_node->employee = NULL;
//   free(employee_node);
//   employee_node = NULL;
// }

void freeAllMemory(employee_list_t **head_employee_list) {
  employee_list_t *p = *head_employee_list;
  while (*head_employee_list) {
    *head_employee_list = (*head_employee_list)->next;
    free(p);
    p = *head_employee_list;
  }
}
