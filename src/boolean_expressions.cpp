#include "boolean_expressions.h"
#include "stack.h"
#include <cctype>
#include <iostream>
#include <string>

#define DISJUNCTION '|'
#define CONJUNCTION '&'
#define NOT '~'

unsigned int precedence(char op) {
  if (op == DISJUNCTION)
    return 1;
  if (op == CONJUNCTION)
    return 2;
  if (op == NOT)
    return 3;
  return 0;
}

int applyOp(int a, int b, char op) {
  switch (op) {
  case DISJUNCTION:
    return a || b;
  case CONJUNCTION:
    return a && b;
  case NOT:
    return !a;
  default:
    return -1;
  }
}

int returnASCIIDigit(const char c) { return c - '0'; }

int evaluate(const char *expression, const char *expression_values) {
  int i = 0;

  Stack<int> values;
  Stack<char> ops;

  while (expression[i] != '\0') {
    if (expression[i] == ' ') {
      i++;
      continue;
    } else if (expression[i] == '(') {
      ops.push(expression[i]);
    } else if (isdigit(expression[i])) {
      int expression_digit = returnASCIIDigit(expression[i]);
      // exception if the index is out of bound
      unsigned int digit =
          returnASCIIDigit(expression_values[expression_digit]);
      values.push(digit);
    } else if (expression[i] == ')') {
      while (!ops.empty() && ops.top() != '(') {
        char op = ops.top();
        ops.pop();
        if (op == NOT) {
          int val = values.top();
          values.pop();
          values.push(applyOp(val, 0, op));
        } else {
          int val2 = values.top();
          values.pop();

          int val1 = values.top();
          values.pop();

          values.push(applyOp(val1, val2, op));
        }
      }

      if (!ops.empty())
        ops.pop();
    } else {
      while (!ops.empty() && !values.empty() &&
             precedence(ops.top()) > precedence(expression[i])) {
        char op = ops.top();
        ops.pop();

        if (op == NOT) {
          int val = values.top();
          values.pop();
          values.push(applyOp(val, 0, op));
        } else {
          int val2 = values.top();
          values.pop();

          int val1 = values.top();
          values.pop();

          values.push(applyOp(val1, val2, op));
        }
      }

      ops.push(expression[i]);
    }

    i++;
  }

  while (!ops.empty()) {
    char op = ops.top();
    ops.pop();

    if (op == NOT) {
      int val = values.top();
      values.pop();
      values.push(applyOp(val, 0, op));
    } else {
      int val2 = values.top();
      values.pop();

      int val1 = values.top();
      values.pop();

      values.push(applyOp(val1, val2, op));
    }
  }

  return values.top();
}

unsigned long long int
find_next_quantificator_pos_after_index(std::string expression, int index) {
  unsigned long long int pos_insert = index;
  while (pos_insert < expression.length() && expression[pos_insert] != 'e' &&
         expression[pos_insert] != 'a') {
    pos_insert++;
  }

  return pos_insert;
}
