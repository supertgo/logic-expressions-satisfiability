#include "binary_tree.h"
#include "boolean_expressions.h"
#include <iostream>
#include <sys/resource.h>
#include <sys/time.h>
#include "timeed.h"

int main(int argc, char *argv[]) {
  try {
    if (argc != 4) {
      throw std::runtime_error("argc must be 3");
    }

    char *method = argv[1];
    char *expression = argv[2];
    char *expression_values = argv[3];
    struct timespec clockStart, clockEnd;
    clock_gettime(CLOCK_REALTIME, &clockStart);

    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);

    switch (method[1]) {
    case 'a':
      std::cout << evaluate(expression, expression_values) << std::endl;
      break;
    case 's':
      std::string exp_values = expression_values;
      std::string exp = expression;
      BinaryTree tree(exp_values, exp);
      unsigned int lowerbound =
          find_next_quantificator_pos_after_index(exp_values, 0);

      std::cout << tree.evaluateTree(lowerbound) << std::endl;

      break;
    }
    getrusage(RUSAGE_SELF, &end);
    clock_gettime(CLOCK_REALTIME, &clockEnd);
    std::cout << "Tempo de relógio: " << clock_time(&clockStart, &clockEnd)
              << " segundos" << std::endl;
    std::cout << "Tempo de usuário: " << user_time(&start, &end) << " segundos"
              << std::endl;
    std::cout << "Tempo de sistema: " << system_time(&start, &end) << " segundos"
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
