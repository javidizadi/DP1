#pragma once
#include "error.h"
#include <cstdint>

template <class T, uint64_t SIZE> class Stack {
private:
  T data[SIZE];
  uint64_t count_elements;

public:
  void push(T item) {
    if (count_elements == SIZE)
      raiseStackError(StackError::StackIsFull);

    data[count_elements++] = item;
  }

  T pop() {
    if (count_elements == 0)
      raiseStackError(StackError::StackIsEmpty);

    return data[count_elements--];
  }

  T top() {
    if (count_elements == 0)
      raiseStackError(StackError::StackIsEmpty);

    return data[count_elements - 1];
  }

  Stack() : count_elements(0) {}
};
