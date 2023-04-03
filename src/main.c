#include "../include/employee.h" // employee management header
#include <ctype.h>               // isspace function
#include <stdbool.h>             // boolean header
#include <stdio.h>               // standard input/output header
#include <stdlib.h>              // for allocating
#include <string.h>              // c string header

//-------- DEFINE COLOR FOR STD OUTPUT STREAM -------------//
#define RED                     "\033[31m"
#define GREEN                   "\033[32m"
#define YELLOW                  "\033[33m"
#define BLUE                    "\033[34m"
#define MAGENTA                 "\033[35m"
#define CYAN                    "\033[36m"
#define RESET                   "\033[0m"

//--------DEFINE FUNCTION SELECT --------------------------//
#define GO_TO_MAIN_SCREEN               0
#define GO_TO_ADD_EMPLOYEE              1
#define GO_TO_PRINT_ALL                 2
#define GO_TO_REMOVE_EMPLOYEE           3
#define GO_TO_FIND_EMPLOYEE             4
#define GO_TO_EXIT                      5

/* Input full name */
char *getName() {
  static char name[64];
  printf("%sEnter employee name: %s", YELLOW, RESET);
  getchar(); // stdint buffer clear
  fgets(name, sizeof(name), stdin);
  name[strlen(name) - 1] = '\0';
  return name;
}

/* Input salary */
double getSalary() {
  static double salary;
  printf("%sEnter salary: %s", YELLOW, RESET);
  scanf("%lf", &salary);
  return salary;
}

bool emptyLineCheck(char *line) {
  if (isspace(line[0])) {
    return true;
  }
  return false;
}

bool importFromFile(employee_list_t **head_employee_list, const char *file_name) {
  FILE *file_to_import = fopen(file_name, "r");
  if (!file_to_import) {
    return false;
  }
  char name[64];
  double salary;
  char buffer_read[255];
  while (fgets(buffer_read, sizeof(buffer_read), file_to_import)) {
    if (emptyLineCheck(buffer_read)) {
      continue;
    }
    buffer_read[strlen(buffer_read) - 1] = '\0';
    char *token = strtok(buffer_read, ":");
    strcpy(name, token);
    token = strtok(NULL, ":");
    salary = strtod(token, NULL);
    addEmployee(head_employee_list, name, salary);
  }
  return true;
}

void pressAnyKeyToContinue() {
  printf("%sPress any key to continue!%s", YELLOW, RESET);
  char c = getchar();
  return;
}

/* Get y/n choice */
bool getChoice() {
  char c = getchar();
  c = tolower(c);
  if (c == 'y') {
    return true;
  }
  return false;
}

int getUserFunctionChoice() {
  int choice;
  do {
    printf("%sWhat is your choice: %s", YELLOW, RESET);
    scanf("%d", &choice);
  } while (choice < 0 || choice > 5);
  return choice;
}

void printMainScreen() {
  system("clear");
  printf("\t\t\t%s+--------------------------------------------------+\n",YELLOW);
  printf("\t\t\t|                                                  |\n");
  printf("\t\t\t|                                                  |\n");
  printf("\t\t\t|           EMPLOYEE MANAGEMENT SYSTEM             |\n");
  printf("\t\t\t|                                                  |\n");
  printf("\t\t\t|                                                  |\n");
  printf("\t\t\t+--------------------------------------------------+\n");
  printf("\t\t\t|                                                  |\n");
  printf("\t\t\t|    1. Add Employee                               |\n");
  printf("\t\t\t|    2. Show All Employee                          |\n");
  printf("\t\t\t|    3. Remove Employee                            |\n");
  printf("\t\t\t|    4. Find Employee                              |\n");
  printf("\t\t\t|    5. Exit                                       |\n");
  printf("\t\t\t|                                                  |\n");
  printf("\t\t\t+--------------------------------------------------+%s\n\n\n",RESET);
}

int main(int charc, char *argv[]) {
  employee_list_t *head_employee_list = NULL;
  int amount_employee = 0;
  int user_function_choice = 0;

  /* Check argument for reading form file  */
  if (charc == 2) {
    const char *file_name = argv[1];
    bool is_read_sucess = importFromFile(&head_employee_list, file_name);
    if (is_read_sucess) {
      printf("%s> INFO: File import successfully!\n%s", GREEN, RESET);
      pressAnyKeyToContinue();
    } else {
      printf("%s> WARN: File import failed!%s\n", RED, RESET);
      pressAnyKeyToContinue();
    }
  }
  /* end check here */
  //--------------------------------------//
  /* Now start the main screen */
  while (true) {
    switch (user_function_choice) {
    case GO_TO_MAIN_SCREEN: {
      printMainScreen();
      user_function_choice = getUserFunctionChoice();
      break;
    }
    case GO_TO_ADD_EMPLOYEE: {
      printf("%sHow many employee: %s",YELLOW,RESET);
      scanf("%d", &amount_employee);
      system("clear");
      for (int i = 0; i < amount_employee; ++i) {
        printf("%sEmployee %d Infomation\n", YELLOW, i + 1);
        printf("-------------------------------\n%s", RESET);
        char *name = getName();
        double salary = getSalary();
        addEmployee(&head_employee_list, name, salary);
        system("clear");
      }
      printf("%sAll employees now are getting success!%s\n",BLUE,RESET);
      getchar();
      pressAnyKeyToContinue();
      user_function_choice = GO_TO_MAIN_SCREEN;
      break;
    }
    case GO_TO_PRINT_ALL: {
      system("clear");
      printf("%s", YELLOW);
      showAllEmployee(head_employee_list);
      getchar();
      pressAnyKeyToContinue();
      user_function_choice = GO_TO_MAIN_SCREEN;
      break;
    }
    case GO_TO_REMOVE_EMPLOYEE: {
      system("clear");
      printf("%sRemove Employee\n",YELLOW);
      printf("--------------------------------%s\n",RESET);
      const char *name = getName();
      bool is_remove_success = removeEmployee(&head_employee_list, name);
      if (is_remove_success) {
        printf("%sEmployee was successfully removed!%s\n",YELLOW,RESET);
      } else {
        printf("%sRemove Failed!%s\n",RED,RESET);
      }
      pressAnyKeyToContinue();
      user_function_choice = GO_TO_MAIN_SCREEN;
      break;
    }
    case GO_TO_FIND_EMPLOYEE: {
      system("clear");
      printf("%sFind Employee\n",YELLOW);
      printf("----------------------------------%s\n",RESET);
      const char *name = getName();
      if (findEmployee(head_employee_list, name)) {
        printf("%sGot salary: %lf%s\n",RED,findEmployee(head_employee_list, name),RESET);
      } else {
        printf("%sNot found!%s\n",RED,RESET);
      }
      pressAnyKeyToContinue();
      user_function_choice = GO_TO_MAIN_SCREEN;
      break;
    }
    case GO_TO_EXIT: {
      printf("%sAre you sure you want to exit: (default n) %s",YELLOW,RESET);
        getchar();
      if (getChoice()) {
        exit(0);
        freeAllMemory(&head_employee_list);
      } else {
        user_function_choice = GO_TO_MAIN_SCREEN;
        break;
      }
    }
    }
  }
  return 0;
}
