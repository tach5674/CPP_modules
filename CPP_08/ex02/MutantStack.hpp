#pragma once

#include <vector>
#include <cstddef>

template <typename T>
class MutantStack
{
private:
    std::vector<T> container;

public:
    MutantStack() {}
    MutantStack(std::vector<T> v) : container(v) {}
    MutantStack(const MutantStack &other) : container(other.container) {}
    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            this->container = other.container;
        return *this;
    }
    ~MutantStack() {}

    bool empty() const { return container.size() ? true : false; }

    size_t size() const { return container.size(); }

    T &top() { return container.back(); }

    const T &top() const { return container.back(); }

    void push(T val) { container.push_back(val); }

    void pop() { container.pop_back(); }

    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator begin() { return container.begin(); }
    iterator end() { return container.end(); }
    const_iterator begin() const { return container.begin(); }
    const_iterator end() const { return container.end(); }
};