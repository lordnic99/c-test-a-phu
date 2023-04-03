#ifndef EMPLOYEE_H

#define EMPLOYEE_H

struct employee {
  char name[64];      //employee name
  double salary;      // employee salary
};

typedef struct employee employee_t ;

struct employee_list {
  employee_t employee;
  struct employee_list *Next;
};

typedef struct employee_list employee_list_t;

#endif // !EMPLOYEE_H
