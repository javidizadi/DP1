#include "calculator.h"
#include "stack.h"

using namespace std;

bool prcd(char, char);
void mapTrigonometricFunctions(string &);

const char COS_MAPPED_CHAR = '@';
const char SIN_MAPPED_CHAR = '#';

void mapTrigonometricFunctions(string &input) {

  int pos;
  while ((pos = input.find("sin")) != string::npos)
    input.replace(pos, 3, 1, SIN_MAPPED_CHAR);

  while ((pos = input.find("cos")) != string::npos)
    input.replace(pos, 3, 1, COS_MAPPED_CHAR);
}

void fixSingleOperand(string &input) {

  for (int i = 0; i < input.length(); i++) {

    if (input[i] == '-' &&
        (i == 0 || (input[i - 1] != ')' && isOperator(input[i - 1])))) {

      char toReplce[] = {'(', '0', '-', input[i + 1], ')'};

      input.replace(i, 2, toReplce);

      i += 5;
    }
  }
}

string infixToPostFix(string input) {

  mapTrigonometricFunctions(input);
  fixSingleOperand(input);

  string result;

  Stack<char, 500> s1;

  for (int i = 0; i < input.length(); i++) {

    if (isOperator(input[i])) {

      if (s1.isEmpty()) {
        s1.push(input[i]);
        continue;
      }

      if (input[i] == ')') {

        while (s1.top() != '(')
          result += s1.pop();

        s1.pop();
        continue;
      }

      if (!prcd(input[i], s1.top())) {
        s1.push(input[i]);
        continue;
      }

      while (!s1.isEmpty() && prcd(input[i], s1.top()))
        result += s1.pop();
      s1.push(input[i]);

    } else
      result += input[i];
  }

  while (!s1.isEmpty())
    result += s1.pop();

  return result;
}

int isOperator(char ch) {

  int priority = 0;

  switch (ch) {

  case '(':
  case ')':
    priority++;

  case COS_MAPPED_CHAR:
  case SIN_MAPPED_CHAR:
    priority++;

  case '!':
    priority++;

  case '^':
    priority++;

  case '/':
  case '*':
    priority++;

  case '+':
  case '-':
    priority++;
  }

  return priority;
}

bool prcd(char a, char b) {

  if (a == '^' && b == '^')
    return false;

  if (a == '(' || b == '(')
    return false;

  if (b == ')')
    return true;

  return isOperator(a) <= isOperator(b);
}
