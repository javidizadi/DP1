#include "stack.h"
#include <cstdint>

#define STACK_CLASS(X) template <class T, uint64_t SIZE> X Stack<T, SIZE>

STACK_CLASS(void)::push(T item) {
  if (count_elements == SIZE)
    throw(StackError::StackIsFull);

  data[count_elements++] = item;
}

STACK_CLASS(T)::pop() {
  if (count_elements == 0)
    throw(StackError::StackIsEmpty);

  return data[--count_elements];
}

STACK_CLASS(T)::top() {
  if (count_elements == 0)
    throw(StackError::StackIsEmpty);

  return data[count_elements - 1];
}

STACK_CLASS(bool)::isEmpty() { return count_elements == 0; }

STACK_CLASS()::Stack() { count_elements = 0; }
