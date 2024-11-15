#pragma once
#include <string>

// Should return -1 otherwise validation error occured
int validateInfix(std::string);

std::string infixToPostFix(std::string);

// if not operator returns 0 otherwise returns priority of operator
int isOperator(char);
