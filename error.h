#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

enum StackError {
  StackIsEmpty,
  StackIsFull,
};

void raiseStackError(StackError err);
