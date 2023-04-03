#ifndef EMPLOYEE_LIST_H

#define EMPLOYEE_LIST_H

#include "employee.h"
#include <stdbool.h>

struct employee_linked_list {
  employee_t *employee;      // employee object
  struct employee_linked_list *Next;     // next employee
};

typedef struct employee_linked_list employee_list_t ;

static bool isDigitOnly(const char *buffer);
static void CLEAR_STDIN_BUFFER();
static employee_list_t *createEmployeeNode();
static char *getEmployeeName();
static double getEmployeeSalary();
static void freeEmployeeNode(employee_list_t *employee_node);
extern void addEmployee(employee_list_t **head_employee_list);
extern void removeEmployee(employee_list_t **head_employee_list, const char *employee_name);
extern const char *findEmployee(const employee_list_t *head_employee_list, const char *employee_name);
extern void showAllEmployee(employee_list_t *head_employee_list);
extern void freeAllMemory(employee_list_t* head_employee_list);

#endif // !EMPLOYEE_LIST_H
