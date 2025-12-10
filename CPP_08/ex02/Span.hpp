#pragma once

#include <vector>

class Span
{
private:
    unsigned int max_size;
    std::vector<int> numbers;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

    void fillSpan(const int n);
    void printNumbers() const;
};