#include "utils.h"
#include <cstddef>
#include <string>

using namespace std;

int validateInfix(string) { return -1; }

size_t fact(size_t x) {

  size_t fact = 1;
  for (size_t i = 2; i < x; i++)
    fact *= i;

  return fact;
}
