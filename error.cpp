#include "error.h"
#include <iostream>
using namespace std;

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

  throw err;
}
