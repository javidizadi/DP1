#pragma once
#include <cstdint>

enum StackError {
  StackIsEmpty,
  StackIsFull,
};

template <class T, uint64_t SIZE> class Stack {
private:
  T data[SIZE];
  uint64_t count_elements;

public:
  void push(T item);
  T pop();
  T top();
  bool isEmpty();
  Stack();
};

#include "stack.tpp"
