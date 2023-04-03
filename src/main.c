#include "../include/employee_list.h"
#include <stdint.h>
#include <stdio.h>

int main()
{
	employee_list_t *head_employee_list = NULL;
	int amount_employee;
	printf("How many employee: "); scanf("%d",&amount_employee);
	for(int i = 0; i < amount_employee; ++i)
	{
		addEmployee(&head_employee_list);
	}
	showAllEmployee(head_employee_list);
  // removeEmployee(&head_employee_list,"Nguyen Hoang");
 //  showAllEmployee(head_employee_list);
	// freeAllMemory(head_employee_list);
	return 0;
}
