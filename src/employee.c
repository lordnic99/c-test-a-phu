#include "../include/employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Allocating node */
static employee_list_t *createEmployeeNode() {
  employee_list_t *new_employee = (employee_list_t *)malloc(sizeof(*new_employee));
  return new_employee;
}

void addEmployee(employee_list_t **head_employee_list, const char* name, double salary) {
  employee_list_t *new_employee = createEmployeeNode();
  strcpy(new_employee->name,name);
  new_employee->salary = salary;
  new_employee->next = NULL;

  /* */
  if (!(*head_employee_list)) {
    *head_employee_list = new_employee;
    return;
  }

  /* Push back */
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
    printf("Employee list was empty!\n");
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

bool removeEmployee(employee_list_t **head_employee_list, const char *employee_name) {
  employee_list_t *p = *head_employee_list;
  if(!p) {
    return false;
  }
  /* check head */
  if(strcmp((*head_employee_list)->name, employee_name) == 0) {
    (*head_employee_list) = (*head_employee_list)->next;
    free(p);
    return true;
  }

  /* check middle */
  /* p->next->next use for checking if node have only two nodes, head & last */
  while(p->next && p->next->next) {
    if(strcmp(p->next->name,employee_name) == 0){
      employee_list_t *temp = p->next;
      p->next = temp->next;
      free(temp);
      return true;
    } 
    p=p->next;
  }

  /* Check last */
  /* Maybe list have only head, so I need to make sure */
  if(p->next == NULL) { return false; }
  /* end check */
  if(strcmp(p->next->name, employee_name) == 0) {
    free(p->next);
    p->next = NULL;
    return true;
  } 
  return false;
}

double findEmployee(employee_list_t *head_employee_list, const char *name) {
  employee_list_t *p = head_employee_list;
  while(p) {
    if(strcmp(p->name, name) == 0) {
      return p->salary;
    }
    p = p->next;
  }
  return (int)0;
}

void freeAllMemory(employee_list_t **head_employee_list) {
  employee_list_t *p = *head_employee_list;
  while (*head_employee_list) {
    *head_employee_list = (*head_employee_list)->next;
    free(p);
    p = *head_employee_list;
  }
}
