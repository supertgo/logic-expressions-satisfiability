#include "binary_tree.h"
#include "boolean_expressions.h"
#include <iostream>

enum ResultType { INTEGER, STRING };

struct TestResult {
  int intResult;
  std::string stringResult;

  TestResult() : intResult(0) {}
  TestResult(int value) : intResult(value) {}
  TestResult(const std::string &value) : stringResult(value) {}
};

struct Test {
  const char *name;
  ResultType resultType;
  TestResult result;
  TestResult expected;
  int (*test_function_int)();
  std::string (*test_function_string)();
};

void displayResult(const Test &test) {
  std::cout << "Test Name: " << test.name << std::endl;
  if (test.resultType == INTEGER) {
    std::cout << "Result (int): " << test.result.intResult << std::endl;
    if (test.result.intResult == test.expected.intResult) {
      std::cout << "Test Passed!" << std::endl;
    } else {
      std::cout << "Test Failed!" << std::endl;
    }
  } else if (test.resultType == STRING) {
    std::cout << "Result (string): " << test.result.stringResult << std::endl;
    if (test.result.stringResult == test.expected.stringResult) {
      std::cout << "Test Passed!" << std::endl;
    } else {
      std::cout << "Test Failed!" << std::endl;
    }
  }
  std::cout << "---------------------------" << std::endl;
};

std::string execute_s_param(std::string exp_values, std::string exp) {
  BinaryTree tree(exp_values, exp);
  int hasQuantificatorFound = 0;
  unsigned long long int lowerbound = 0;

  while (lowerbound < exp_values.length() && exp_values[lowerbound] != 'e' &&
         exp_values[lowerbound] != 'a') {
    hasQuantificatorFound = 1;
    lowerbound++;
  }

  return tree.evaluateTree(hasQuantificatorFound ? lowerbound : 0);
}

int test_1() {
  const char *expression = "0 | 1";
  const char *expression_values = "01";

  return evaluate(expression, expression_values);
}

int test_2() {
  const char *expression = "0 | 1 & 2";
  const char *expression_values = "010";

  return evaluate(expression, expression_values);
}

int test_3() {
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

std::string test_9() {
  std::string exp = "0 | 1 & 2";
  std::string exp_values = "aaa";

  return execute_s_param(exp_values, exp);
}

std::string test_10() {
  std::string exp = "0 | 1 & 2";
  std::string exp_values = "a1a";

  return execute_s_param(exp_values, exp);
}

std::string test_11() {
  std::string exp = "0 | 1 & 2";
  std::string exp_values = "0e0";

  return execute_s_param(exp_values, exp);
}

std::string test_12() {
  std::string exp = "0 | 1 & 2";
  std::string exp_values = "e00";

  return execute_s_param(exp_values, exp);
}

std::string test_13() {
  std::string exp = "0 | 1 & 2";
  std::string exp_values = "e11";

  return execute_s_param(exp_values, exp);
}

std::string test_14() {
  std::string exp = "0 | 1 & 2 | ( 3 | 4 )";
  std::string exp_values = "a11aa";

  return execute_s_param(exp_values, exp);
}

int main() {
  Test tests[] = {
      // {"Test 1", INTEGER, .result = {.intResult = 1},
      //  .expected = {.intResult = 1}, .test_function_int = test_1},
      // {"Test 2", INTEGER, .result = {.intResult = 0},
      //  .expected = {.intResult = 0}, .test_function_int = test_2},
      // {"Test 3", INTEGER, .result = {.intResult = 0},
      //  .expected = {.intResult = 0}, .test_function_int = test_3},
      // {"Test 4", INTEGER, .result = {.intResult = 0},
      //  .expected = {.intResult = 0}, .test_function_int = test_4},
      // {"Test 5", INTEGER, .result = {.intResult = 0},
      //  .expected = {.intResult = 0}, .test_function_int = test_5},
      // {"Test 6", INTEGER, .result = {.intResult = 0},
      //  .expected = {.intResult = 0}, .test_function_int = test_6},
      // {"Test 7", INTEGER, .result = {.intResult = 1},
      //  .expected = {.intResult = 1}, .test_function_int = test_7},
      // {"Test 8", INTEGER, .result = {.intResult = 0},
      //  .expected = {.intResult = 0}, .test_function_int = test_8},
      {"Test 9", STRING,
       .expected = {.stringResult = "0"},
       .test_function_string = test_9},
      {"Test 10", STRING,
       .expected = {.stringResult = "0"},
       .test_function_string = test_10},
      {"Test 11", STRING,
       .expected = {.stringResult = "0"},
       .test_function_string = test_11},
      {"Test 12", STRING,
       .expected = {.stringResult = "1 100"},
       .test_function_string = test_12},
      {"Test 13", STRING,
       .expected = {.stringResult = "1 a11"},
       .test_function_string = test_13},
      {"Test 14", STRING,
       .expected = {.stringResult = "1 a11aa"},
       .test_function_string = test_14},
  };

  int num_tests = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < num_tests; ++i) {
    if (tests[i].resultType == INTEGER) {
      tests[i].result.intResult = tests[i].test_function_int();
    } else if (tests[i].resultType == STRING) {
      // Handle string result here
      tests[i].result.stringResult = tests[i].test_function_string();
    }
    displayResult(tests[i]);
  }

  return 0;
}
