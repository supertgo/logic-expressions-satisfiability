#include "boolean_expressions.h"
#include <iostream>
#include <stdlib.h>

unsigned long long int string_size(const char *string) {
  unsigned long long int size = 0;

  while (string[size] != '\0') {
    size++;
  }

  return size;
}

int main(int argc, char *argv[]) {
  // argc must be size 3

  // fn to check if the first param is -s or -a,
  // neither i must return a asssert with trycatch
  // char *method = argv[1];
  char *expression = argv[2];
  char *expression_values = argv[3];
  // std::cout << string_size(expression) << std::endl;
  // std::cout << argv[3] << std::endl;
  std::cout << "result: " << evaluate(expression, expression_values)
            << std::endl;

  return 0;
}
