#pragma once

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> stack;
    
    void applyOperator(char op);

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expr);
};