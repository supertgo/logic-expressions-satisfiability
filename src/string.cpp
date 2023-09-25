#include "string.h"

unsigned long long int string_size(const char* string) {
  unsigned long long int size = 0;

  while(string[size] != '\0') {
    size++;
  }

  return size;
}
