/*
 * simple_calculator.c
 *
 * A simple calculator program.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int check_quit(char *input) {
  char *quit_01 = "\n";
  char *quit_02 = "quit\n";
  char *quit_03 = "exit\n";
  if (!strcmp(input, quit_01) ||
      !strcmp(input, quit_02) ||
      !strcmp(input, quit_03))
  {
    return 1;
  }

  return 0;
}

void calculate(char *input) {
  char *token = strtok(input, " ");
  while(token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
}

int check_operator(char *input) {
  char *op_01 = "+\n";
  char *op_02 = "-\n";
  char *op_03 = "*\n";
  char *op_04 = "/\n";
  if (!strcmp(input, op_01) || !strcmp(input, op_02) ||
      !strcmp(input, op_03) || !strcmp(input, op_04))
  {
    return 1;
  }

  return 0;
}


int main(int argc, char *argv[]) {
  char buffer[MAX];
  char *quit_01 = "\n";
  char *quit_02 = "quit\n";
  char *quit_03 = "exit\n";

  printf("calculator.c\n");
  printf("------------\n\n");

  // main calculator loop
  int isQuit = 0;
  while(!isQuit) {
    char operator;
    float num_01, num_02, result;
    
    // get first number
    printf("Enter the first number: \n");
    fgets(buffer, MAX, stdin);

    // check input for quit commands
    isQuit = check_quit(buffer);
    if(isQuit) {
      continue;
    }

    char *ptr;
    num_01 = strtof(buffer, &ptr);

    // get operator
    int is_op_valid = 0;
    while(!is_op_valid) {
      // get input
      printf("Select an operator from (+, -, *, /):\n");
      fgets(buffer, MAX, stdin);

      // check input for quit commands
      isQuit = check_quit(buffer);
      if(isQuit) {
        break;
      }
      
      // validate input
      if (check_operator(buffer)) {
        operator = buffer[0];
        is_op_valid = 1;
      } else {
        printf("Invalid input. Try again.");
      }
    }

    // check for quit commands from operator input
    if(isQuit) {
      continue;
    }

    // get second number
    printf("Enter the second number: \n");
    fgets(buffer, MAX, stdin);

    // check input for quit commands
    isQuit = check_quit(buffer);
    if(isQuit) {
      continue;
    }

    num_02 = strtof(buffer, &ptr);

    switch(operator) {
      case '+':
        result = num_01 + num_02;
        break;
      case '-':
        result = num_01 - num_02;
        break;
      case '*':
        result = num_01 * num_02;
        break;
      case '/':
        result = num_01 / num_02;
        break;
    }

    printf("%f %c %f = %f\n\n", num_01, operator, num_02, result);
  }

  return 0;
}
