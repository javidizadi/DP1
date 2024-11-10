#include <cstdlib>
#include <iostream>
#pragma once

using namespace std;

enum StackError {
  StackIsEmpty,
  StackIsFull,
};

void raiseStackError(StackError err) {

  string msg;

  switch (err) {
  case StackError::StackIsFull:
    msg = "Stack is full.";
    break;

  case StackError::StackIsEmpty:
    msg = "Stack is empty.";
    break;
  }

  cout << msg << endl;

  exit(1);
}
