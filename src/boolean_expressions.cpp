#include "boolean_expressions.h"
#include "stack.h"
#include "string.h"
#include <cctype>
#include <iostream>
#include <string>

#define DISJUNCTION '|'
#define CONJUNCTION '&'
#define NOT '~'

// Retorna a precência de cada operador
unsigned int precedence(char op) {
  if (op == DISJUNCTION)
    return 1;
  if (op == CONJUNCTION)
    return 2;
  if (op == NOT)
    return 3;
  return 0;
}

// Aplica as operações booleanas, (and, or e not)
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
  int length = strlen(expression_values);
  Stack<int> values;
  Stack<char> ops;

  while (expression[i] != '\0') {
    // Pulandos os espacos
    if (expression[i] == ' ') {
      i++;
      continue;
    } else if (expression[i] == '(') {
      ops.push(expression[i]);
    } else if (isdigit(expression[i])) {
      // Cria uma string que representa o dígito, serve para lidar
      // com uma quantidade mairo de váriavéis.
      std::string digit;
      while (isdigit(expression[i])) {
        digit.push_back(expression[i]);
        i++;
      }

      int position = std::stoi(digit);
      int value = 0;

      if (position >= 0 && position < length) {
        value = returnASCIIDigit(expression_values[position]);
      } else {
        throw std::runtime_error(
            "A posição é maior do que o maior index da string: " +
            std::to_string(position));
      }
      values.push(value);
      continue;
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
      // É um operador
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

// Função que retorna próxima quantificador a partir de uma determinada posição.
unsigned int find_next_quantificator_pos_after_index(std::string expression,
                                                     int index) {
  unsigned int pos_insert = index;
  while (pos_insert < expression.length() && expression[pos_insert] != 'e' &&
         expression[pos_insert] != 'a') {
    pos_insert++;
  }

  return pos_insert;
}
