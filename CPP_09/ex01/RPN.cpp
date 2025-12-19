#include "RPN.hpp"
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expr)
{
    while (!stack.empty())
        stack.pop();

    std::istringstream iss(expr);
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
            applyOperator(token[0]);
        else
            throw std::invalid_argument("Invalid argument: " + token);
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Invalid RPN expression.");
    return stack.top();
}

void RPN::applyOperator(char op)
{
    if (stack.size() < 2)
        throw std::invalid_argument("Not enough operands in the stack.");
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    if (op == '+')
        stack.push(a + b);
    else if (op == '-')
        stack.push(a - b);
    else if (op == '*')
        stack.push(a * b);
    else if (op == '/')
    {
        if (b == 0)
            throw std::invalid_argument("Division by zero occured.");
        stack.push(a / b);
    }
}
