#pragma once

enum StackError {
  StackIsEmpty,
  StackIsFull,
};

void raiseStackError(StackError err);
