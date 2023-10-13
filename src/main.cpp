#include "binary_tree.h"
#include "boolean_expressions.h"
#include <iostream>

int main(int argc, char *argv[]) {
  try {
    if (argc != 4) {
      throw std::runtime_error(
          "Argumentos inválidos: São necessários 3 além do programa.");
    }

    char *method = argv[1];
    char *expression = argv[2];
    char *expression_values = argv[3];

    switch (method[1]) {
    case 'a': {
      std::cout << evaluate(expression, expression_values) << std::endl;
      break;
    }
    case 's': {
      std::string exp_values = expression_values;
      std::string exp = expression;
      BinaryTree tree(exp_values, exp);
      unsigned int lowerbound =
          find_next_quantificator_pos_after_index(exp_values, 0);

      std::cout << tree.evaluateTree(lowerbound) << std::endl;
      break;
    }
    default:
      throw std::runtime_error("Apenas -s ou -a.");
      break;
    }
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
