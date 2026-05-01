#include "Span.hpp"

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cstdlib>

static int randValue()
{
    return std::rand() % 100;
}

Span::Span() : max_size(0) {}

Span::Span(unsigned int n) : max_size(n) {}

Span::Span(const Span &other) : max_size(other.max_size), numbers(other.numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->max_size = other.max_size;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (this->numbers.size() == this->max_size)
        throw std::runtime_error("Span is full");
    this->numbers.push_back(num);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");

    std::vector<int> copy = numbers;
    std::sort(copy.begin(), copy.end());
    int res = numbers[1] - numbers[0];
    for (size_t i = 1; i < numbers.size() - 1; i++)
        res = std::min(numbers[i + 1] - numbers[i], res);
    return 0;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");

    return *std::max_element(numbers.begin(), numbers.end()) -
           *std::min_element(numbers.begin(), numbers.end());
}

void Span::fillSpan(const int n)
{
    if (numbers.size() + n > max_size)
        throw std::runtime_error("Span is full");
    numbers.resize(numbers.size() + n);
    std::generate(numbers.end() - n, numbers.end(), randValue);
}
