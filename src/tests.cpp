#include "boolean_expressions.h"
#include <iostream>

int test_1() {
  // const char *method = "-a";
  const char *expression = "0 | 1";
  const char *expression_values = "01";

  return evaluate(expression, expression_values);
}

int test_2() {
  // const char *method = "-a";
  const char *expression = "0 | 1 & 2";
  const char *expression_values = "010";

  return evaluate(expression, expression_values);
}

int test_3() {
  // const char *method = "-a";
  const char *expression = "~(0 | 1) & 2";
  const char *expression_values = "101";

  return evaluate(expression, expression_values);
}

void expect(int expected_value, int value, const char *test_name) {
  if (expected_value == value) {
    std::cout << "The test " << test_name << " passed!" << std::endl;
    return;
  }

  std::cout << "The test " << test_name << " failed!" << std::endl;
}

int main() {
  expect(1, test_1(), "1");
  expect(0, test_2(), "2");
  expect(0, test_3(), "3");

  return 0;
}
