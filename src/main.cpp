#include <cctype>
#include <iostream>
#include <stack>
#include <typeinfo>

int precedence(char op) {
  if (op == '|')
    return 1;
  if (op == '&')
    return 2;
  if (op == '~')
    return 3;
  return 0;
}

int applyOp(int a, int b, char op) {
  switch (op) {
  case '|':
    return a || b;
  case '&':
    return a && b;
  case '~':
    return !a;
  default:
    return -1;
  }
}

unsigned long long int string_size(const char *string) {
  unsigned long long int size = 0;

  while (string[size] != '\0') {
    size++;
  }

  return size;
}

int returnTheASCIIDigit(char c) { return c - '0'; }

int evaluate(char *expression) {
  int i = 0;

  std::stack<int> values;
  std::stack<char> ops;

  while (expression[i] != '\0') {
    if (expression[i] == ' ') {
      i++;
      continue;
    } else if (expression[i] == '(') {
      ops.push(expression[i]);
    } else if (isdigit(expression[i])) {
      values.push(returnTheASCIIDigit(expression[i]));
    } else if (expression[i] == ')') {
      while (!ops.empty() && ops.top() != '(') {
        char op = ops.top();
        ops.pop();
        if (op == '~') {
          int val = values.top();
          values.pop();
          values.push(applyOp(val, 0, op));
        } else {
          int val2 = values.top();
          values.pop();

          int val1 = values.top();
          values.pop();

          char op = ops.top();
          ops.pop();

          values.push(applyOp(val1, val2, op));
        }
      }

      if (!ops.empty())
        ops.pop();
    } else {
      while (!ops.empty() &&
             precedence(ops.top()) >= precedence(expression[i])) {

        char op = ops.top();
        ops.pop();

        if (op == '~') {
          int val = values.top();
          values.pop();
          values.push(applyOp(val, 0, op));
        } else {
          int val2 = values.top();
          values.pop();

          int val1 = values.top();
          values.pop();

          char op = ops.top();
          ops.pop();

          values.push(applyOp(val1, val2, op));
        }
      }

      ops.push(expression[i]);
    }

    i++;
  }

  while (!ops.empty()) {
    int val2 = values.top();
    values.pop();

    int val1 = values.top();
    values.pop();

    char op = ops.top();
    ops.pop();

    values.push(applyOp(val1, val2, op));
  }

  return values.top();
}

int main(int argc, char *argv[]) {
  // argc must be size 3

  // fn to check if the first param is -s or -a,
  // neither i must return a asssert with trycatch
  std::cout << argv[1] << std::endl;
  char *expression = argv[2];
  // std::cout << string_size(expression) << std::endl;
  // std::cout << argv[3] << std::endl;
  std::cout << evaluate(expression) << std::endl;

  return 0;
}
