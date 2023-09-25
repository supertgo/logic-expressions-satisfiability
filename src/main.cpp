#include "boolean_expressions.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "string.h"


int main(int argc, char *argv[]) {
  try {
    if (argc != 4) {
      throw std::runtime_error("argc must be 3");
    }

    // char *method = argv[1];
    char *expression = argv[2];
    char *expression_values = argv[3];

    if (1 == 0) {
      std::cout << "result: " << evaluate(expression, expression_values);
    } else if (1 == 1) {
      char *combinations[1000];
      unsigned long long int inputLength = string_size(expression_values);
      int hasE = 0;
      int eCount = 0;

      for (unsigned long long int i = 0; i < inputLength; ++i) {
        if (expression_values[i] == 'e') {
          hasE = 1;
          eCount++;
        }
      }

      int numCombinations = 1 << eCount; // 2 ^ numero de e's

      for (int i = 0; i < numCombinations; ++i) {
        int eIndex = 0;
        char *currentCombination = new char[inputLength + 1];

        for (unsigned long long int j = 0; j < inputLength; ++j) {
          if (expression_values[j] == 'e') {
            currentCombination[j] = ((i >> eIndex) & 1) ? '1' : '0';
            eIndex++;
          } else {
            currentCombination[j] = expression_values[j];
          }
        }

        currentCombination[inputLength] = '\0';
        combinations[i] = currentCombination;
      }

    int satisfiabilityCount = 0;
    std::vector<std::string> satisfyingCombinations;

    for (int i = 0; i < numCombinations; ++i) {
        std::cout << "Combination " << i + 1 << ": " << combinations[i] << std::endl;

        if (evaluate(expression, combinations[i]) == 1) {
            satisfiabilityCount++;
            satisfyingCombinations.push_back(combinations[i]);
        }
    }



      for (int i = 0; i < eCount; ++i) {
        delete[] combinations[i];
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
