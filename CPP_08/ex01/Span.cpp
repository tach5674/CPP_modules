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

void Span::printNumbers() const
{
    if (numbers.empty())
        return;
    std::cout << "Numbers - ";
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i];
        if (i != numbers.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");

    std::vector<int> copy = numbers;
    std::sort(copy.begin(), copy.end());
    int res = copy[1] - copy[0];
    for (size_t i = 1; i < copy.size() - 1; i++)
        res = std::min(copy[i + 1] - copy[i], res);
    return res;
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
