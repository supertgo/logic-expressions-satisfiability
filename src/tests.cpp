#include "boolean_expressions.h"
#include <iostream>

struct Test {
  const char *name;
  int expected_value;
  int (*test_function)();
};

void expect(int expected_value, int value, const char *test_name) {
  if (expected_value == value) {
    std::cout << "The test " << test_name << " passed!" << std::endl;
    return;
  }

  std::cout << "The test " << test_name << " failed!" << std::endl;
}

void run_tests(Test *tests, int num_tests) {
  for (int i = 0; i < num_tests; ++i) {
    int result = tests[i].test_function();
    expect(tests[i].expected_value, result, tests[i].name);
  }
}

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

int test_4() {
  const char *expression = "1 & 0";
  const char *expression_values = "10";

  return evaluate(expression, expression_values);
}

int test_5() {
  const char *expression = "0 & 1 | 2";
  const char *expression_values = "100";

  return evaluate(expression, expression_values);
}

int test_6() {
  const char *expression = "0 & 1 | 2 & 3";
  const char *expression_values = "0010";

  return evaluate(expression, expression_values);
}

int test_7() {
  const char *expression = "~ 0 & 1 | 2";
  const char *expression_values = "101";

  return evaluate(expression, expression_values);
}

int test_8() {
  const char *expression = "0 | ~ ( 1 & 1 )";
  const char *expression_values = "01";

  return evaluate(expression, expression_values);
}

int main() {
  Test tests[] = {{"Test 1", 1, test_1}, {"Test 2", 0, test_2},
                  {"Test 3", 0, test_3}, {"Test 4", 0, test_4},
                  {"Test 5", 0, test_5}, {"Test 6", 0, test_6},
                  {"Test 7", 1, test_7}, {"Test 8", 0, test_8}};

  int num_tests = sizeof(tests) / sizeof(tests[0]);

  run_tests(tests, num_tests);

  return 0;
}
