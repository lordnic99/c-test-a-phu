#ifndef EMPLOYEE_H

#define EMPLOYEE_H

#include <stdbool.h>

struct employee_list {
  char      name[64];
  double    salary;
  struct    employee_list *next;
};

typedef struct employee_list employee_list_t;

extern void addEmployee(employee_list_t **head_employee_list, const char* name, double salary);
extern void showAllEmployee(employee_list_t *head_employee_list);
extern bool removeEmployee(employee_list_t **head_employee_list, const char *employee_name);
extern double findEmployee(employee_list_t *head_employee_list, const char *name);
extern void freeAllMemory(employee_list_t **head_employee_list);

#endif // !EMPLOYEE_H
