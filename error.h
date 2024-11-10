#include <cstdlib>
#include <iostream>
#pragma once

using namespace std;

enum StackError {
  StackIsEmpty,
  StackIsFull,
};

void raiseStackError(StackError err) {
  cout << "Stack is full.\n";
  exit(1);
}
