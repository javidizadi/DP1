#pragma once

bool prcd(char a, char b) {

  if (a == '^' && b == '^')
    return false;

  if (a == b)
    return true;

  if (a == '(' || b == '(')
    return false;

  if (b == ')')
    return true;

  if (a == '^')
    return true;

  if ((a == '*' || a == '/') && (b == '+' || b == '-'))
    return true;

  if ((a == '+' && b == '-') || (a == '-' && b == '+'))
    return true;

  if ((a == '*' && b == '/') || (a == '/' && b == '*'))
    return true;

  return false;
}
