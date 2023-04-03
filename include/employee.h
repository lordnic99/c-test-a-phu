#ifndef EMPLOYEE_H

#define EMPLOYEE_H

struct employee_list {
  char    name[64];
  double  salary;
  struct employee_list *next;
};

typedef struct employee_list employee_list_t;

extern void addEmployee(employee_list_t **head_employee_list, const char* name, double salary);
extern void showAllEmployee(employee_list_t *head_employee_list);
extern void removeEmployee(employee_list_t **head_employee_list, const char *employee_name);

#endif // !EMPLOYEE_H
